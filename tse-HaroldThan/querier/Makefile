# Makefile for '    querier'
#
# CS50, Summer 2021

PROG =     querier
OBJS =     querier.o 
LIBS = ../common/common.a ../libcs50/libcs50-given.a

# uncomment the following to turn on verbose memory logging
TESTING=-DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../libcs50 -I../common
CC = gcc
MAKE = make


 querier.o: ../libcs50/hashtable.h ../libcs50/set.h ../libcs50/counters.h ../libcs50/memory.h ../common/pagedir.h ../common/index.h ../libcs50/bag.h ../libcs50/file.h

.PHONY:     querier test valgrind clean

$(PROG): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@ 


all:     querier 

    querier:     querier.o $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

# Run Program
test: $(PROG) 
	./$(PROG) ../data2 ../data2/oldIndexFilename

# expects a file `test.names` to exist; it can contain any text.
valgrind: $(PROG) 
	valgrind --leak-check=full --show-leak-kinds=all ./$(PROG) ../data2 ../data2/oldIndexFilename

#Clean Up Previous Compilation
clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f $(PROG)


