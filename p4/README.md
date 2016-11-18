********************************************
Project 4 Booga Device Driver
Author: Caitlyn Goetz
Class: CS 453 Operating Systems Section 001
********************************************

OVERVIEW:
	For this project, I wrote a character driver called booga, in order to explore
	how drivers interact with the operating system.

MANIFEST:
	*README.md - this file which describes the project and other files within
	*booga.c - main file for this project. Runs all the main methods for developing
		   the driver and how it should behave.
	*booga.h - header file for booga.c.  Contains all header things
	*booga_load - executeable that loads the driver for use
	*booga-test.sh - given script for testing the driver
	*booga-test2.sh - given script for testing the driver
	*booga_unload - executeable that unloads the driver so that it can no longer be used
	*Makefile - the file used to compile/make and build the project
	*test-booga.c - given file used for testing
	*test-read.sh - script file that I wrote for testing the read functionality
	*test-write.sh - scripte file that I wrote for testing the write functionality

BUILD THE PROJECT:
	In order to build the project, run the following command in the directory containing Makefile:

		$make

	In order to make the driver ready to run, run the following command with your own adminstration
	requirements (username and password):

		$sudo ./booga_load

	In order to run the compiled project, run the following command with any of the executeables:
	
		$./<executeable> <whatever> <parameters> <needed>

	After you are done using the driver, run the following command with your own administration
	requirements (username and password):

		$sudo ./booga_unload

TESTING:
	To test this project, I relied mostly on test-booga.c.  It was the easiest to run and the easiest 
	to use for debugging.  I also wrote two other script files to test the read and write functionality
	of the driver.  In them I ran read or write on the numbers 1, 24, 3456, 23457695, 12308504, and
	10000389.
	I also used the two scripts, booga-test.sh and booga-test2.sh, after I had got the driver what I 
	considered as done.  They both ran with no problems.

DISCUSSION:
	This project went ok.  The example code in the CS453-resources repository was extremely helpful.
	It allowed me to look at how the code was suppose to run and look and then apply it to my own 
	project.  If that example code wasn't there, though, I don't know if I would have had a clue
	what to do for this project.  There is so much going on and, let me tell you, I somehow found 
	1290342309708 ways to type booga, neka, maka, wooga and googa wrong.  Maka always, ALWAYS turned
	into make.  My poor compiler must think I am an idiot.
	I basically relied on the examples to write it and once I figured out how to navigate them and 
	read the code, everything went ok.  I do have to say that I am so happy that I learned how to
	really use grep this semester because that was a lifesavor when looking through the CS453-resources
	directory!  It makes it so nice to be able to find things easily!

SOURCES:
	Some of the code for this project came largely out of examples within the
	CS453-R\resources git repository.  This was extremely helpful but still
	allowed us to experiment on our own.
