# Makefile for 'crawler' module
#
# CS50, Summer 2021

PROG = crawler
OBJS = crawler.o 
LIBS = ../common/common.a ../libcs50/libcs50-given.a

# uncomment the following to turn on verbose memory logging
TESTING=-DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../libcs50 -I../common
CC = gcc
MAKE = make

crawler.o: ../libcs50/bag.h ../libcs50/hashtable.h ../libcs50/webpage.h ../libcs50/memory.h ../common/pagedir.h ../libcs50/set.h

.PHONY: crawler test valgrind clean

$(PROG): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@ 

# Run Program
test: $(PROG) 
	./$(PROG) http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data 9

# expects a file `test.names` to exist; it can contain any text.
valgrind: $(PROG) 
	valgrind --leak-check=full ./$(PROG) http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data 3

#Clean Up Previous Compilation
clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f $(PROG)
