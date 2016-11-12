********************************************
Project 3: Producers-Consumers Monitor
Author: Caitlyn Goetz
Class: CS 453 Operating Systems Section 001
*********************************************

OVERVIEW:
	For this project, we altered our linked list to make it thread safe and then
	used it to utilize a monitor to make producers and consumers.

MANIFEST:
	*README.md - this file describing the project
	*Makefile - top level makefile to build the project
	*test-mq-pc.sh - given script to run test on project
	*test-pc.sh - given script to run test on project
	*include - directory containing header files
	*include/Item.h - header file for Item.c
	*include/Node.h - header file for Node.c
	*include/thread-safe-list.h - header file for thread-safe-list.c
	*src - directory containing main source files
	*src/Item.c - source file that makes item objects
	*src/Makefile - sublevel makefile that builds the sublevel
	*src/Node.c - source file defining the node object
	*src/pc.c - given source file that runs the producers and consumers
	*src/thread-safe-list.c - modified list source code to make it thread safe

BUILDING:
	To build this project, run the following command in the directory containing the
	top level Makefile:
		
			$make

	To run the compiled project, run the following command in the same directory as
	the executable:

		$./pc <poolsize> <#items/producer> <#producers> <#consumers> <sleep interval(microsecs)>

TESTING:
	To test this program, I ran it on my own Virtual Machine running Linux.  I ran
	larger (19 or so) several times.  It returned the same every time I ran it so
	I took that as a good sign. I also ran the given scripts to test the program.
	These returned the values they were expected to every time I ran them.

DISCUSSION:
	This project went ok.  I had issues getting the files all linked together right
	(which one is included in which file and that type of thing).  Once I figured that
	out, I just had to figure out how to make the list thread safe.  That went ok
	once I got the first method going, the others followed pretty easy.  The major
	challenge was reading the man pages for all of the thread methods.  I would
	say it went ok though.  Not to bad but those man pages can run circles around
	answers without giving you any answers.  
