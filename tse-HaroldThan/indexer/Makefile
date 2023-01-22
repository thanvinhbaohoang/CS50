# Makefile for 'indexer'
#
# CS50, Summer 2021

PROG = indexer
OBJS = indexer.o 
LIBS = ../common/common.a ../libcs50/libcs50-given.a

# uncomment the following to turn on verbose memory logging
TESTING=-DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../libcs50 -I../common
CC = gcc
MAKE = make


indexer.o: ../libcs50/hashtable.h ../libcs50/set.h ../libcs50/counters.h ../libcs50/memory.h ../common/pagedir.h ../common/index.h
indextest.o: ../common/index.h 

.PHONY: indexer test valgrind clean

$(PROG): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@ 


all: indexer indextest

indexer: indexer.o $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

indextest: indextest.o $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@
	
# Run Program
test: $(PROG) 
	./$(PROG) ../data2 indexFile

# expects a file `test.names` to exist; it can contain any text.
valgrind: $(PROG) 
	valgrind --leak-check=full --show-leak-kinds=all ./$(PROG) ../data2 ../data2/indexFile

#Clean Up Previous Compilation
clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f $(PROG)


