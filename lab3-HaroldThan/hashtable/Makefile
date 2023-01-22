# Makefile for 'hashtable' module
#
# CS50, Summer 2021

PROG = hashtabletest
OBJS = hashtabletest.o hashtable.o ../lib/readlinep.o ../lib/memory.o jhash.o ../set/set.o
LIBS = 

# uncomment the following to turn on verbose memory logging
TESTING=-DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

hashtabletest.o: hashtable.h ../lib/readlinep.h
hashtable.o: hashtable.h 
readlinep.o: ../lib/readlinep.h
jhash.o: jhash.h
../set/set.o: ../set/set.h

.PHONY: test valgrind clean

# expects a file `test.names` to exist; it can contain any text.
test: $(PROG) 
	./$(PROG) 

# expects a file `test.names` to exist; it can contain any text.
valgrind: $(PROG) 
	valgrind ./$(PROG)

clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f $(PROG)

