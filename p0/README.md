*****************************************
*Project - : Doubly Linked List Library
*Class: CompSci 453 Section 001
*Name: Caitlyn Goetz
*******************************i**********

OVERVIEW:

	This program implements a doubly-linked list using nodes and generic objects.
	

COMPILING AND USING:

	From the directory containing the source files type the following in the command line to compile the project:
		$make
	
	After that you can set up your console to run the program by typing this in the command line:
		export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib

	Finally you can run the program by using the test file called UnitTestList by typing this in the command line:	
		$testsuite/UnitTestList

PROGRAM DEVELOPMENT AND TESTING DISCUSSION:

	This lab was one of the easiest that I have done in my CompSci career.  I knew what was going on and I 
	understood what I was suppose to be doing.  It was a great confidence booster.  I had a little bit of
	a problem understanding valgrind and how all the libraries worked together but that is because I hadn't
	been exposed to that before.  After I worked that out, I really enjoyed this project and it was somewhat
	of a nice break from the usual mindnumbing confusion that usually comes with doing projects.  It was also
	nice to remain constantly working on the project and not have to stop for help or take a break because I
	didn't understand.  I wish more projects were like this!  (I am sure once I get a handle on this that other
	projects will become this way).  
	
	After I turned it in the first time, there was found to be a segmentation fault originating from adding or
	removing NULL nodes or lists.  After some testing I was able to discover it and fix it.  There was also some
	dangling nodes which I also found and took care of.  So as far as I know, there are no issues/bugs in my
	code.
	
DISCUSSION:

	The previous statement was written when I first did this project in CS 253.  It was one of my favorite programs
	that we had done.  For this time around, I thankfully kept this code in my GitHub folder and all I had to do
	was move it to the backpack folder and run it agains the grader.  I ran into a somewhat stupid problem where
	I was trying to run this Linux program on my Mac OS.  So of course, I got stuck on that.  Once I made a fool of
	myself, I managed to get it running and ran it against the grader.  I got all passing tests on the grader so then
	I just had to figure out how to use backpack to turn it in which wasn't hard at all since it is the same as GitHub.

SOURCES USED:

	I don't think I used many sources when I first developed this program.  Since we had done a doubly linked list in 
	Java, it was fairly straightforward to convert it to C.  I believe when I did run into problems, I would ask the
	lab TA's for help.  To get the grader and backpack working, I did seek help from fellow students, who had previously
	used backpack.
