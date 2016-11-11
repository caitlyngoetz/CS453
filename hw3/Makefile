
JFLAGS=

# .class and .java extensions
.SUFFIXES: .class .java

.java.class:
	 javac $(JFLAGS) $<

CC=gcc
#CFLAGS= -g   -Wall 
CFLAGS= -O  -Wall  
LIBS=-lpthread
PROGS=TestFileAccess FileAccessTest.class

all: $(PROGS)

TestFileAccess: FileAccess.h FileAccess.o TestFileAccess.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^ 

FileAccess: Webstats.class

clean:
	/bin/rm -f *.o $(PROGS) *.class
