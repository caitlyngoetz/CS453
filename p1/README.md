*******************************************
Project 1 Shell Project
Author: Caitlyn Goetz
Class: CS453 Operating Systems Section #001
********************************************

OVERVIEW:

This project creates its own shell that runs commands both in the forground and background.
It allows most of the usual command line commands.

MANIFEST:

|Filename       | Description                                                       |
|---------------|-------------------------------------------------------------------|
|backpack.sh	|Script file for grading					    |
|common.h	|Header file containing commonly used headers			    |
|docs		|Directory holding generated files				    |
|execute.c	|Contains code that makes the commands run			    |
|execute.h	|Header for execute.c						    |
|Job.c		|Contains the code to implement the jobs			    |
|Job.h		|Header file for Job.c						    |	
|ourhdr.h	|Header file for other headings					    |
|README.md      |This file                                                          |
|doxygen-config |Sample config file for doxygen                                     |
|Makefile       |Completed make file for the mydash project			    |
|TestCases      |An incomplete list of test cases                                   |
|test-harness/  |An example (incomplete) test harness for the dash project          |
|test-harness/example1  |example code 						    |
|test-harnes/example2	|example code						    |
|test-cd	|Test for cd command						    |
|test-empty	|Test for an empty command					    |
|test-eof	|Test for EOF command						    |
|test-exit	|Test for exit command						    |
|valgrind.supp  |Example suppression file for valgrind for the readline library     |
|mydash-src/Makefile | Build file for mydash (adapted to my needs)                  |
|mydash-src/mydash.c | Starter version of mydash.c                                  |
|mydash-src/error.c | Error handling code used in class examples                    |
|mydash-src/mydash.h| Header file for the mydash project                            |
|other-progs/test-readline.c|Example file on how to use auto completion with readline library |
|other-progs/loop.c   |Simple infinite loop program for testing purposes            |
|other-progs/Makefile |Makefile to build other program examples                     |
|p1_checkpoint.txt  |Grade for first checkpoint					    |
|p1_rubric.txt	|Rubric for this project					    |

BUILDING THE PROJECT:
	From the top-level directories containing all the other directories, use the following command to compile the project:
		$make

FEATURES AND USAGE:
	To run the script, use the following command:

		$./mydash

	To use the version command, use the following command:

		$./mydash -v

	To run valgrind, use the following command:

		$valgrind --leak-check=yes --suppressions=valgrind.supp dash
	Thus allowing you to run valgrind without the memory leaks and errors.

	To print out the job list, use the following command:
	
		my_dash> jobs

	To run a process in the background, use the following command:

		my_dash> <whatever valid command> &
TESTING:
	Testing was horrid.  I haven't been able to write any test cases because I haven't been able to finish the project
	(see disscussion section).  All the testing I have done is to try and figure out what the program is doing and where
	it is crashing by using printf's everywhere.  Not very glamorous but it is the best I got.

VALGRIND:
	Instructions for running valgrind are above int the Features and Usage section.  I haven't been able to/brave enough
	to run it yet because I have not finished the project and I don't want that pressure quite yet.

KNOWN BUGS:
	As of right now (Wednesday October 5 at 11:22 P.M. Mountain Time) the program seg faults once it gets into the 
	runJobs method. I have managed to figure out that the switch case is just continuing to call that method with one
	command line argument until the the system freaks out and crashes... To be continued.

DISCUSSIONS:
	As Amit predicted, I definately thought this project was super hard (and hopefully the hardest this semester).  The
	first checkpoint went somewhat ok.  The second/end was rough.  Between figuring out what needed to be included in
	each file and what needed to be built where in the Makefile, I ran into some weird issues.  I struggled a great
	deal having the methods declared where they needed to be so that caused pages of error lines when making.  Once I 
	got that figured out, I then had problems figuring out that I needed to alter the src directory Makefile so that
	it included all of the object files so they can be included in the project.  Then I had issues with an interesting
	error about the Makefile saying that there was "No rule to include <some file> in 'mydash."

	Well, I missed the first deadline for the project being due.  Between school work, work work and life work, there has
	been no sleep work and this project haunts my dreams.  Tonight is the deadline for the late extension and unless I 
	can figure out what the seg fault (mentioned in the Known Bugs section), this deadline will not be met either.  I 
	understand what this project does and needs to do but for some reason I cannot get it to work.  Missing these 
	deadlines is super stressful and embarrasing and simply not allowed.

	Going back to the first checkpoint, I had all of the requirements for that met.  So at one point those worked.  As
	of now, they don't.  Let's just say I am excited to scare the next semesters students with how terrifying this soul
	sucking project is.  Just kidding, its not that bad but I wish it would have gone better.  Thank you, Amit, for all
	the chances, help and time.

	FIXED IT AT 12:04!!!!!! PLEASE CONSIDER THIS, I PUSH NOW!!!
SOURCES USED:
	StackOverflow!!  And friendly peer advice.
