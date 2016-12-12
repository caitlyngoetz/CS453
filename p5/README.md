******************************************************************
*Project: Shell Project Part 2 (with Buddy System Memory Manager)
*Author: Caitlyn Goetz
*Date: December 11, 2016
*Class: CS453 Operating Systems Section #001
*****************************************************************

OVERVIEW:
	For this project, we were to pair our mydash project with a buddy memory
	manager.

MANIFEST:
	*README.md - this file
	*buddy.c - the main file which holds all the code for the buddy system
	*buddy.h - the header file for buddy.c
	*buddy-test.c - given testing document
	*buddy-unit-test.c - given testing document with added tests
	*malloc-test.c - given testing document
	*git.log - contains the git log for this project
	*Makefile - the makefile that builds this project

BUILDING THE PROJECT:
	To build this project, in the directory containing the top-level Makefile,
	run the following command:

		$make

FEATURES AND USAGE:
	To run the buddy-test executable, run the following command in the directory
	containing the executable:

		$./buddy-test <number of test> [random seed] [silen|terse|verbose|interactive]

	To run the buddy-unit-test executable, run the following commmand in the directory
	containing the executable:

		$./buddy-unit-test [silent|terse|verbose|interactive]

	To run the malloc-test executable, run the following command in the directory
	containing the executable:

		$./malloc-test <number of tests> [random seed] [silent|terse|verbose|interactive]

TESTING:
	I used the given testing documents (buddy-test.c, buddy-unit-test.c and 
	malloc-test.c) to test what I have of my program.  I also added a test 
	case to buddy-unit-test.c which will allocate a block of memory which
	size gets bigger by 20 times every iteration until there is no more memory
	left.  However, since I did not complete this project 100%, I was not able
	to utilize all of the features in my tests or the tests given to me.

VALGRIND:
	Valgrind works pretty good right now.  There are stil some blocks "still reachable" but other than
	that it is pretty clean when run agains the malloc-test.c file.

KNOWN BUGS:
	When being build this project currently throws three warnings which do not affect how the project
	builds.  There are two errors about the machine getting to the end of a non-void function.  For those
	two methods, I was not able to build them out fully so that is why the errors are being thrown.
	The other warning is about a method being defined but not used.  This is also becasue I was not able
	to fully make this project work.  But again these do not affect the building of this project since
	they are just warnings.

SOURCE CODE CONTROL:
	For some version control, I was bad an only started pushing to git after a while of programming.
	However, this did save my butt a little because I accidently deleted my almost completed README,
	so it was nice just to checkout the file again!  I generally only pushed once I got somethine 
	"done" or "added".  I ran the following command to have git output a log so that you could see
	my git actions from the past week till now:

		$git log --since=1.weeks > git.log

	That file is included in the top-level of the directory with this file.

DISCUSSION:
	This project kicked my butt.  I will in no way be able to finish this in the
	duration of what time is left for this class, let alone the late due dates.  It
	went ok to start off with but once I got deeper and deeper into it, the worse
	it got.  It's like the rabbit hole in Alice in Wonderland.  I got the first chunk
	working (the 70 pts part).  Hopefully it is enough for me to get some part of	
	the grade for this project.  I also did a little testing, which is further
	documented in the testing part of this document.

	To perhaps help a little bit with understanding what I believe I have done for this
	project, here is a little break down.  I believe the first chunk of the project
	description is done (the 70 pts section).  I also added one test to the 
	buddy-unit-test.c file so that is a little bit of the testing grade which was a total
	of 20 pts. I also checked the part of the project that I could agains Valgrind.  I also 
	included the git log (didn't have a point specification) as well as a hopefully suitable 
	README (Documentation section for 20 pts).

	I am very sorry that I could not get this project done because it does seem like a 
	fun challenge.  However, with the other projects I had for other CS classes and the
	fact that I had an on-site interview with a company on Wednesday and Thursday, I just
	didn't budget my time correctly.  However there was not much I could have changed because
	of the job interview.

	I will work on this over break and I do hope I get it running someday because I do not
	like to leave stuff broken.  However, for the remaining time in this class, it will have
	to be so.  I beg that you please be gentle with the grading and know that I did learn
	much from this project even if it is not complete by grading standards.

	Thank you for a wonderful semester :)
