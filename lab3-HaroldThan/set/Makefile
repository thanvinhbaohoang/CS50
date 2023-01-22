# Makefile for 'set' module
#
# CS50, Summer 2021

PROG = settest
OBJS = settest.o set.o ../lib/readlinep.o ../lib/memory.o 
LIBS = 

# uncomment the following to turn on verbose memory logging
TESTING=-DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

settest.o: set.h ../lib/readlinep.h
set.o: set.h
readlinep.o: ../lib/readlinep.h

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

