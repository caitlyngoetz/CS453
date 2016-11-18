#ifndef __BOOGA_H
#define __BOOGA_H

#include <linux/module.h>
#include <linux/slab.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/signal.h>
#include <linux/sched.h>
#include <linux/random.h>
#include <linux/uaccess.h>

#ifndef BOOGA_MAJOR
#define BOOGA_MAJOR 0 
#endif

#ifndef BOOGA_NR_DEVS
#define BOOGA_NR_DEVS 4
#endif

#define TYPE(dev) (MINOR(dev) >> 4) 
#define NUM(dev) (MINOR(dev) & 0xf) 

typedef struct Booga booga;
typedef struct Booga * boogaptr;

struct Booga {
	struct semaphore s;
	long int bytes_read;
	long int bytes_write;
	long int booga0_opens;
	long int booga1_opens;
	long int booga2_opens;
	long int booga3_opens;
	long int option0_output;
	long int option1_output;
	long int option2_output;
	long int option3_output;
	unsigned int d_num;
};

static int __init booga_init(void);
static void __exit booga_exit(void);
static int booga_open(struct inode *inode, struct file *filp);
static int booga_release(struct inode *inode, struct file *filp);
static ssize_t booga_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);
static ssize_t booga_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos);

#endif
