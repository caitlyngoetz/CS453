#include "booga.h"

static boogaptr booga_device;
static struct proc_dir_entry *booga_proc_file;
static int booga_major = BOOGA_MAJOR;
module_param(booga_major, int, 0);
static int booga_nr_devs = BOOGA_NR_DEVS;
module_param(booga_nr_devs, int, 0);
static int booga_proc_open(struct inode *inode, struct file *file);

MODULE_AUTHOR("Caitlyn Goetz");
MODULE_LICENSE("GPL v2");

static struct file_operations booga_fops = {
	.read = booga_read,
	.write = booga_write,
	.unlocked_ioctl = NULL,
	.open = booga_open,
	.release = booga_release,
};

static const struct file_operations booga_proc_fops = {
	.owner = THIS_MODULE,
	.open = booga_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};

static unsigned int getOption (void){
	char randval;
	get_random_bytes(&randval, 1);
	return (randval & 0x7F) % 4;
}

static int booga_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, "bytes read = %ld\n", booga_device->bytes_read);
	seq_printf(m, "bytes written = %ld\n", booga_device->bytes_write);
	seq_printf(m, "number of opens:\n");
	seq_printf(m, "\t/dev/booga0 = %ld times\n", booga_device->booga0_opens);
	seq_printf(m, "\t/dev/booga1 = %ld times\n", booga_device->booga1_opens);
	seq_printf(m, "\t/dev/booga2 = %ld times\n", booga_device->booga2_opens);
	seq_printf(m, "\t/dev/booga3 = %ld times\n", booga_device->booga3_opens);
	seq_printf(m, "strings output:\n");
	seq_printf(m, "\tbooga! booga!  = %ld times\n", booga_device->option0_output);
	seq_printf(m, "\tgoogoo! gaagaa!  = %ld times\n", booga_device->option1_output);
	seq_printf(m, "\tneka! maka!    = %ld times\n", booga_device->option2_output);
	seq_printf(m, "\twooga! wooga!  = %ld times\n", booga_device->option3_output);
	return 0;
}


static int booga_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, booga_proc_show, NULL);
}

static int booga_open(struct inode *inode, struct file *filp){

	unsigned int num = NUM(inode->i_rdev);

	if(num >= booga_nr_devs){
		return -ENODEV;
	}
	filp->f_op = &booga_fops;

	if(down_interruptible (&booga_device->s)){
		return (-ERESTARTSYS);
	}
	booga_device->d_num = num;

	if(num == 0){
		(booga_device->booga0_opens)++;
	}
	if(num == 1){
		(booga_device->booga1_opens)++;
	}
	if(num == 2){
		(booga_device->booga2_opens)++;
	}
	if(num == 3){
		(booga_device->booga3_opens)++;
	}
	up(&booga_device->s);
	try_module_get(THIS_MODULE);
	return 0;
}

static int booga_release(struct inode *inode, struct file *filp){
	module_put(THIS_MODULE);
	return (0);
}

static ssize_t booga_read(struct file *filp, char *buf, size_t count, loff_t *f_pos){
	unsigned int stringIndex = 0;
	unsigned int outputStringIndex = 0;
	unsigned int selectedOption;

	char *option;
	char *outputString = (char *) kmalloc(sizeof(char) * count, GFP_KERNEL);

	if(down_interruptible(&booga_device->s)){
		return (-ERESTARTSYS);
	}
	selectedOption = getOption();

	if(selectedOption == 0){
		option = "booga! booga! ";
		(booga_device->option0_output)++;
	}
	if(selectedOption == 1){
		option = "googoo! gaagaa! ";
		(booga_device->option1_output)++;
	}
	if(selectedOption == 2){
		option = "wooga! wooga! ";
		(booga_device->option2_output)++;
	}
	if(selectedOption == 3){
		option = "neka! maka! ";
		(booga_device->option3_output)++;
	}

	booga_device->bytes_read += count;
	up(&booga_device->s);

	while(outputStringIndex < count){
		outputString[outputStringIndex++] = option[stringIndex++];
		if(option[stringIndex] == '\0'){
			stringIndex = 0;
		}
	}
	if(__copy_to_user(buf, outputString, count)){
		buf = NULL;
		return 0;
	}
	return count;
}

static ssize_t booga_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos){
	char *s = (char *) kmalloc(sizeof(char) * count, GFP_KERNEL);
	unsigned int w = count;
	w -= __copy_from_user(s, buf, count);
	if(down_interruptible(&booga_device->s)){
		return (-ERESTARTSYS);
	}
	if(booga_device->d_num == 3) {
		send_sig_info(SIGTERM, NULL, current);
		up(&booga_device->s);
		return 0;
	}
	booga_device->bytes_write += w;
	up(&booga_device->s);
	return w;
}

static void init_booga_device(void)
{
	booga_device->bytes_read = 0;
	booga_device->bytes_write = 0;
	booga_device->booga0_opens = 0;
	booga_device->booga1_opens = 0;
	booga_device->booga2_opens = 0;
	booga_device->booga3_opens = 0;
	booga_device->option0_output = 0;
	booga_device->option1_output = 0;
	booga_device->option2_output = 0;
	booga_device->option3_output = 0;
	sema_init(&booga_device->s, 1);
}

static int __init booga_init(void){
	int result;
	result = register_chrdev(booga_major,"booga",&booga_fops);
	if(result < 0){
		printk(KERN_WARNING "booga: can't get major %d\n", booga_major);
		return result;
	}

	if(booga_major == 0){
		booga_major = result;
	}
	printk("<1> booga device driver version 3: loaded at major number %d\n", booga_major);
	booga_device = (boogaptr) kmalloc(sizeof(booga), GFP_KERNEL);

	if(!booga_device) {
		result = -ENOMEM;
		goto fail_malloc;
	}
	init_booga_device();
	booga_proc_file = proc_create("driver/booga", 0, NULL, &booga_proc_fops);
	if(!booga_proc_file){
		result = -ENOMEM;
		goto fail_malloc;
	}

	return 0;

fail_malloc:
	unregister_chrdev(booga_major, "booga");
	return result;
}

static void __exit booga_exit(void){
	remove_proc_entry("driver/booga", NULL);
	kfree(booga_device);
	unregister_chrdev(booga_major, "booga");
	printk("<1> booga device driver version: unloaded\n");
}

module_init(booga_init);
module_exit(booga_exit);
