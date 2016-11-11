Homework 1 
Author: Caitlyn Goetz
Class: CS453 Operating Systems Section 001
******************************************

OVERVIEW:

	For this homework, I built and configured two linux kernels.  The first was the 
	standard linux kernel that ran at 50% max thread capacity.  The second, I altered
	to run at 95% the max thread capacity.

MANIFEST:

	*README.md - This file which explains what the other file does
	*fork.patch - The file that holds the diff, to prove that I did the requirments.

DISCUSSION:

	This homework went ok.  I had a couple of mistakes.  The first was that I failed 
	to give my Virtual Box enough memory to do anything.  I ended up re-doing the VM
	about 4 times to make enough space and stop making stupid mistakes.  That was 
	fun.  After that the homework went fairly well.  The only problem I had was that
	the first time I built the kernel, I mistook the two commands "sudo make 
	modules_install" and "sudo make install" as one command when reading the file. 
	So the kernel was not properly built and I ended restarting.  

	The other thing I did was put the .tar file in a seperate directory on my machine,
	and it apparently didn't like that.  Thankfully a friend from a different class
	pointed that out to me and it didn't cost me too much time.  Everything else went
	fairly smoothly.

	Finding the code to alter to make the max threads was one of the easier parts.
	I was in class when Dr. Amit talked about he would go about it and that is when
	he showed us that it was in the fork.c file.  After that, I just physically looked
	in different directories to find it.  First I tried the lib directory and then
	I tried the kernel directory and luckily it was in that one.  I then just did a 
	search within the file for "max" and then just looked through it until I found the 
	two lines that needed to be altered.

	To test that I did it right I used the command ulimit -Ha and looked at the amounts
	in the 95% boot and then I switched over to the original boot and did the same 
	command there.  The amounts were almost double in the first one so I figured it
	had worked.
