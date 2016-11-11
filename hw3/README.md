**********************
Project: Homework 3
Author: Caitlyn Goetz
Class: CS 453 Operating Systems Section 001
**********************

OVERVIEW:

This homework is an introduction to using monitors and condition varibales which 
control syncronization. 

MANIFEST:
	*README.md - this file
	*Accessor.java - Sets up the accessors for the java project
	*FileAccess.c - main program for the c version
	*FileAccess.h - header for the FileAccess.c program
	*FileAccess.java - Main program for the Java version
	*FileAccessTest.java - Driver class for the Java version
	*Makefile - Makefile for the C verison
	*TestFileAccess.c - Driver class for the C version

BUILDING:

	In the directory containing the files, do the following commnd to build the project:
	
		$make

	To run the C version, do the following command:

		$./TestFileAccess <numThreads> <max sum> <iterations>

	To run the Java version, do the following command:
		
		$java FileAccessTest <numThreds> <max sum> <iterations>

DISCUSSION:

	This project went fairly well.  Nothing to big to worry about besides figuring
	out the accessors and working with all that.  I forgot to add the print lines
	so I thought mine wasn't working for a couple of minutes but finally got that
	worked out.

	Part One Pseudo-code:

	FileAccess{

    	int sum;
   	 int max;
    	condition cond;
    
   	 public FileAccess(int max){
    
   	     sum = max;
       	 }
    
    	void StartAccess(int id){
        
       	 while((sum + id) <= max){
        
            cond.wait();
            
        	}
        sum += id;
        cond.signal();
    }
    
    void EndAccess(int id){
    
        cond.signal();
        sum -= id;
    }
