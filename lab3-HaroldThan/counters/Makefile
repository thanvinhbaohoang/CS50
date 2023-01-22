# Makefile for 'counters' module
#
# CS50, Summer 2021

PROG = counterstest
OBJS = counterstest.o counters.o ../lib/readlinep.o ../lib/memory.o 
LIBS = 

# uncomment the following to turn on verbose memory logging
TESTING=-DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

counterstest.o: counters.h ../lib/readlinep.h
counters.o: counters.h
readlinep.o: ../lib/readlinep.h

.PHONY: test valgrind clean

# expects a file `test.names` to exist; it can contain any text.
test: $(PROG) test.number
	./$(PROG) < test.number

# expects a file `test.names` to exist; it can contain any text.
valgrind: $(PROG) test.number
	valgrind ./$(PROG) < test.number

clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f $(PROG)

