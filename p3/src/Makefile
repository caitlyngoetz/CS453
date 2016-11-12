CC=gcc
CFLAGS=-g -Wall -I. $(INCLUDES) -MMD
LIBS=-lpthread
INCLUDES=-I../include
MV=/bin/mv

PROGS=pc

all: $(PROGS)

pc: thread-safe-list.o Node.o Item.o pc.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	$(MV) $@ ../

clean: 
	/bin/rm -f *.o $(PROGS) a.out core *.d
