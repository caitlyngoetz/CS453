*************************************************
Project 2: Multithreaded Application (Webstats)
Author: Caitlyn Goetz
Class: CS 453 Operating Systems Section 001
*************************************************

OVERVIEW:
	I was given single threaded versions of a Java and C program, which I then turned
	into multithreaded programs and added a Windows/C++ multithreaded version to.

MANIFIEST:

	*README.md - this file which talks about this project
	*version1/ - directory that holds main files
	*version1/error.c - given file that holds error details
	*version1/Makefile - Makefile for the version1 directory of Java and C programs
	*version1/ourhdr.h - given file that holds header details
	*version1/README - given README that holds build details for that directory
	*version1/webstats.c - Changed single to multithreaded C program
	*version1/Webstats.java - Changed single to multithreaded Java program
	*version2/ - given directory for extra credit which I did not do
	*ms-windows/webstats

BUILDING THE PROJECT:
	To build the C and Java protions of this project, cd into the version1 directory
	and run the following command:

		$make 

FEATURES AND USUAGE:
	To run the C program and see the time it takes, use the following command after 
	building the project:
		
		$time ./webstats <access_log_file>

	To run the Java program and see the time it takes, use the following command 
	after building the project:

		$time java Webstats <access_log_file>

	To run the Windows/C++ program and see the time it takes,

		>Measure-Command {./webstats.exe <access_log_files>}

TESTING: 
	To test the C program, I ran the solutions on a Linux Virtual Machine on my Mac.
	The same one that I had been using all semester.  I found that I got improvements
	 on the times so I know it was working and should work on other Linux operating 
	systems.
	
	For the Java program, I, too, ran the solution on the same Linux Virtual Machine
	on my Mac, and it seemed to go fine.  So I then assumed that it would also work 
	on any Linux operating systems.

	For the Windows/C++ solution,

	Valgrind:
		As per the instuctions, I ran valgrind against the C program and found
		that there were memory leaks.  To find those I ran the leak-check=full
		on valgrind and it gave me the first few where the memmory that had
		been malloc was not free.  After fixing those (about three of them) I 
		ran valgrind again but discovered that there was still memory leaks.
		After some searching, I had seen that we were opening files so I checked 
		to see if the files were then closed and found that they were not.  
		So once I closed them,valgrind gave me a clean bill of health.

DISCUSSION
	Here are the times that I am getting for running on single threads or multiple 
	threads for each program/operating system:

	Linux:
	
		Single Threaded Version for all access_log files:

			real	0m4.483s
			user	0m3.870s
			sys	0m0.481s
	
		Multithreaded Version for all access_log files:		

			real	0m4.138s
			user	0m4.003s
			sys	0m0.056s
	Java:

		Single Threaded Version for all access_log files:

			real	0m3.446s
			user	0m3.202s
			sys 	0m0.134s
	
		Multithreaded Version for all access_log files:

			real	0m3.364s
			user	0m3.130s
			sys	0m0.365


	Windows:

		Single Threaded version for all access_log files:

			Seconds		:5
			Milliseconds	:418

		Multithreaded version for all access_log files:

			Seconds		:4
			Milliseconds	:934

	For the Java and C versions, I ran them both on my Fedora/Linux virtual machine that 
	is on my Macbook Air which has 2 cores.  The Windows version I ran on the same Mac
	on a Windows 10 Virual Machine with Visual Studios 2015 Community

	This project went a lot smoother than the first one (thank goodness) for the C
	and Java parts! I was able to somewhat understand the solutions and get them to 
	work easily.  I also struggled with realizing that I needed to unzip the 
	access_log files.  That was really stupid of me but I didn't comprehend that they
	were zipped with the .gz file name.  

	The Windows and Visual Studio part was a pain though.  Between learning the nuances
	(I hope that is the right word) and figuring out C++ which I have never used; it took
	way longer than I think it should have.  I still don't fully know if I got it right
	or if I submitted whatever the "solution" files were.  And having to type "dir" instead 
	of "ls" is going to drive me insane if we ever have to do another project on here.  It
	just wasn't my favorite part of this project at all.


SOURCES USED:
	The only sources that I used were some StackOverflow pages to figure out how to
	unzip the access files and understand a little more about semaphores and mutex.
