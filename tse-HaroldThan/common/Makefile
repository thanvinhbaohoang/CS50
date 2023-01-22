# Makefile for "common" library
#   Builds and compiles all these utility functions into a library.
#
# If you prefer our data-structure implementation over your own, 
# modify the rule for `$(LIB)`:
# $(LIB): libcs50-given.a
#	cp libcs50-given.a $(LIB)
#
# CS50, Summer 2021

# object files, and the target library
OBJS = pagedir.o index.o word.o
LIB = common.a
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I ../libcs50 -L ../libcs50
CC = gcc

# Build the library by archiving object files
$(LIB): $(OBJS)
	ar cr $(LIB) $(OBJS)

# $(LIB): libcs50-given.a
# 	cp libcs50-given.a $(LIB)

# Dependencies: object files depend on header files
pagedir.o: pagedir.h
index.o: index.h
word.o: word.h
.PHONY: clean

# clean up after our compilation
clean:
	rm -f $(LIB) *~ *.o *.a