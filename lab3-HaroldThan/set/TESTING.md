# CS50 Lab 3
## CS50 Summer 2021

### Functionality test

Various functionality tests are conducted in settest.c: 

* TEST 1: creating an empty set
* TEST 2: inserting null item into a valid set
* TEST 3: inserting null item into a null set
* TEST 4: printing set_pairs in a valid set
* TEST 5: set_insert with pre-existing key
* Test 6: set_insert with new key 
* TEST 7: deleting a valid set with itemdelete=NULL
* TEST 7: deleting a valid set with valid itemdelete function



#### Functionality test output
f003xd3@plank:~/cs50/labs/lab3-HaroldThan/set$ make clean
rm -rf *.dSYM  # MacOS debugger info
rm -f *~ *.o
rm -f settest
f003xd3@plank:~/cs50/labs/lab3-HaroldThan/set$ make test
gcc -Wall -pedantic -std=c11 -ggdb -DMEMTEST -I../lib   -c -o settest.o settest.c
gcc -Wall -pedantic -std=c11 -ggdb -DMEMTEST -I../lib   -c -o set.o set.c
gcc -Wall -pedantic -std=c11 -ggdb -DMEMTEST -I../lib settest.o set.o ../lib/readlinep.o ../lib/memory.o  -o settest
./settest 
Testing set_insert.....
Call set_insert(set, key1, item1):
Call set_insert(set, key2, item2):
Call set_insert(set, key3, item3):
TESTING set_print with valid set, itemprint= NULL: Should Print empty set {}:
{} 
TESTING set_print with NULL set, valid itemprint_int: Should Print (NULL):
(NULL) 
TESTING set_print with valid set, valid itemprint_int function:
{key3:item3,key2:item2,key1:item1} 
Testing set_insert with NULL key, valid item
INSERTION FAIL!
Testing set_insert with valid key, NULL item
INSERTION FAIL!
Call set_insert(set, key3duplicate, item3duplicate)
PRE-EXIST KEY FOUND IN SET
INSERTION FAIL!
The Set:
{key3:item3,key2:item2,key1:item1} 
Call set_insert(set, key4, item3)
The Set:
{key4:item3,key3:item3,key2:item2,key1:item1} 
deleting the set...
itemdelete=NULL; Do Nothing
The Set:
{key4:item3,key3:item3,key2:item2,key1:item1} 
valid itemdelete; Should Empty The Set
The Set:
{} 

#### MEMORY TEST OUTPUT
==7175== Memcheck, a memory error detector
==7175== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7175== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7175== Command: ./settest
==7175== 
Testing set_insert.....
Call set_insert(set, key1, item1):
Call set_insert(set, key2, item2):
Call set_insert(set, key3, item3):
TESTING set_print with valid set, itemprint= NULL: Should Print empty set {}:
{} 
TESTING set_print with NULL set, valid itemprint_int: Should Print (NULL):
(null) 
TESTING set_print with valid set, valid itemprint_int function:
{key3:item3,key2:item2,key1:item1} 
Testing set_insert with NULL key, valid item
INSERTION FAIL!
Testing set_insert with valid key, NULL item
INSERTION FAIL!
Call set_insert(set, key3duplicate, item3duplicate)
PRE-EXIST KEY FOUND IN SET
INSERTION FAIL!
The Set:
{key3:item3,key2:item2,key1:item1} 
Call set_insert(set, key4, item3)
The Set:
{key4:item3,key3:item3,key2:item2,key1:item1} 
deleting the set...
itemdelete=NULL; Do Nothing
The Set:
{key4:item3,key3:item3,key2:item2,key1:item1} 
valid itemdelete; Should Empty The Set
The Set:
==7175== Invalid read of size 8
==7175==    at 0x10905B: set_print (set.c:106)
==7175==    by 0x108E16: main (settest.c:90)
==7175==  Address 0x522f040 is 0 bytes inside a block of size 8 free'd
==7175==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10946F: count_free (memory.c:88)
==7175==    by 0x1091D5: set_delete (set.c:157)
==7175==    by 0x108DED: main (settest.c:88)
==7175==  Block was alloc'd at
==7175==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10939B: count_malloc (memory.c:53)
==7175==    by 0x108E98: set_new (set.c:46)
==7175==    by 0x108B35: main (settest.c:42)
==7175== 
==7175== Invalid read of size 8
==7175==    at 0x10906F: set_print (set.c:108)
==7175==    by 0x108E16: main (settest.c:90)
==7175==  Address 0x522f7e8 is 8 bytes inside a block of size 24 free'd
==7175==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10946F: count_free (memory.c:88)
==7175==    by 0x1091BA: set_delete (set.c:151)
==7175==    by 0x108DED: main (settest.c:88)
==7175==  Block was alloc'd at
==7175==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10939B: count_malloc (memory.c:53)
==7175==    by 0x108E37: setpair_new (set.c:30)
==7175==    by 0x108F2E: set_insert (set.c:66)
==7175==    by 0x108D53: main (settest.c:78)
==7175== 
==7175== Invalid read of size 8
==7175==    at 0x109077: set_print (set.c:108)
==7175==    by 0x108E16: main (settest.c:90)
==7175==  Address 0x522f7e0 is 0 bytes inside a block of size 24 free'd
==7175==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10946F: count_free (memory.c:88)
==7175==    by 0x1091BA: set_delete (set.c:151)
==7175==    by 0x108DED: main (settest.c:88)
==7175==  Block was alloc'd at
==7175==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10939B: count_malloc (memory.c:53)
==7175==    by 0x108E37: setpair_new (set.c:30)
==7175==    by 0x108F2E: set_insert (set.c:66)
==7175==    by 0x108D53: main (settest.c:78)
==7175== 
==7175== Invalid read of size 1
==7175==    at 0x4C34D32: __strlen_sse2 (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x4E9B5D2: vfprintf (vfprintf.c:1643)
==7175==    by 0x4EA2F43: fprintf (fprintf.c:32)
==7175==    by 0x108B0B: itemprint (settest.c:26)
==7175==    by 0x109086: set_print (set.c:108)
==7175==    by 0x108E16: main (settest.c:90)
==7175==  Address 0x522f790 is 0 bytes inside a block of size 5 free'd
==7175==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10946F: count_free (memory.c:88)
==7175==    by 0x1091AE: set_delete (set.c:150)
==7175==    by 0x108DED: main (settest.c:88)
==7175==  Block was alloc'd at
==7175==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10939B: count_malloc (memory.c:53)
==7175==    by 0x108F04: set_insert (set.c:64)
==7175==    by 0x108D53: main (settest.c:78)
==7175== 
==7175== Invalid read of size 1
==7175==    at 0x4C34D44: __strlen_sse2 (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x4E9B5D2: vfprintf (vfprintf.c:1643)
==7175==    by 0x4EA2F43: fprintf (fprintf.c:32)
==7175==    by 0x108B0B: itemprint (settest.c:26)
==7175==    by 0x109086: set_print (set.c:108)
==7175==    by 0x108E16: main (settest.c:90)
==7175==  Address 0x522f791 is 1 bytes inside a block of size 5 free'd
==7175==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10946F: count_free (memory.c:88)
==7175==    by 0x1091AE: set_delete (set.c:150)
==7175==    by 0x108DED: main (settest.c:88)
==7175==  Block was alloc'd at
==7175==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10939B: count_malloc (memory.c:53)
==7175==    by 0x108F04: set_insert (set.c:64)
==7175==    by 0x108D53: main (settest.c:78)
==7175== 
==7175== Invalid read of size 1
==7175==    at 0x4EC9B2D: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1241)
==7175==    by 0x4E9B0EA: vfprintf (vfprintf.c:1643)
==7175==    by 0x4EA2F43: fprintf (fprintf.c:32)
==7175==    by 0x108B0B: itemprint (settest.c:26)
==7175==    by 0x109086: set_print (set.c:108)
==7175==    by 0x108E16: main (settest.c:90)
==7175==  Address 0x522f793 is 3 bytes inside a block of size 5 free'd
==7175==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10946F: count_free (memory.c:88)
==7175==    by 0x1091AE: set_delete (set.c:150)
==7175==    by 0x108DED: main (settest.c:88)
==7175==  Block was alloc'd at
==7175==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10939B: count_malloc (memory.c:53)
==7175==    by 0x108F04: set_insert (set.c:64)
==7175==    by 0x108D53: main (settest.c:78)
==7175== 
==7175== Invalid read of size 1
==7175==    at 0x4EC9B44: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1241)
==7175==    by 0x4E9B0EA: vfprintf (vfprintf.c:1643)
==7175==    by 0x4EA2F43: fprintf (fprintf.c:32)
==7175==    by 0x108B0B: itemprint (settest.c:26)
==7175==    by 0x109086: set_print (set.c:108)
==7175==    by 0x108E16: main (settest.c:90)
==7175==  Address 0x522f792 is 2 bytes inside a block of size 5 free'd
==7175==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10946F: count_free (memory.c:88)
==7175==    by 0x1091AE: set_delete (set.c:150)
==7175==    by 0x108DED: main (settest.c:88)
==7175==  Block was alloc'd at
==7175==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10939B: count_malloc (memory.c:53)
==7175==    by 0x108F04: set_insert (set.c:64)
==7175==    by 0x108D53: main (settest.c:78)
==7175== 
==7175== Invalid read of size 1
==7175==    at 0x4C391B8: mempcpy (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x4EC9A63: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1258)
==7175==    by 0x4E9B0EA: vfprintf (vfprintf.c:1643)
==7175==    by 0x4EA2F43: fprintf (fprintf.c:32)
==7175==    by 0x108B0B: itemprint (settest.c:26)
==7175==    by 0x109086: set_print (set.c:108)
==7175==    by 0x108E16: main (settest.c:90)
==7175==  Address 0x522f790 is 0 bytes inside a block of size 5 free'd
==7175==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10946F: count_free (memory.c:88)
==7175==    by 0x1091AE: set_delete (set.c:150)
==7175==    by 0x108DED: main (settest.c:88)
==7175==  Block was alloc'd at
==7175==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10939B: count_malloc (memory.c:53)
==7175==    by 0x108F04: set_insert (set.c:64)
==7175==    by 0x108D53: main (settest.c:78)
==7175== 
==7175== Invalid read of size 1
==7175==    at 0x4C391C6: mempcpy (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x4EC9A63: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1258)
==7175==    by 0x4E9B0EA: vfprintf (vfprintf.c:1643)
==7175==    by 0x4EA2F43: fprintf (fprintf.c:32)
==7175==    by 0x108B0B: itemprint (settest.c:26)
==7175==    by 0x109086: set_print (set.c:108)
==7175==    by 0x108E16: main (settest.c:90)
==7175==  Address 0x522f792 is 2 bytes inside a block of size 5 free'd
==7175==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10946F: count_free (memory.c:88)
==7175==    by 0x1091AE: set_delete (set.c:150)
==7175==    by 0x108DED: main (settest.c:88)
==7175==  Block was alloc'd at
==7175==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10939B: count_malloc (memory.c:53)
==7175==    by 0x108F04: set_insert (set.c:64)
==7175==    by 0x108D53: main (settest.c:78)
==7175== 
==7175== Invalid read of size 8
==7175==    at 0x10908B: set_print (set.c:110)
==7175==    by 0x108E16: main (settest.c:90)
==7175==  Address 0x522f7f0 is 16 bytes inside a block of size 24 free'd
==7175==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10946F: count_free (memory.c:88)
==7175==    by 0x1091BA: set_delete (set.c:151)
==7175==    by 0x108DED: main (settest.c:88)
==7175==  Block was alloc'd at
==7175==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10939B: count_malloc (memory.c:53)
==7175==    by 0x108E37: setpair_new (set.c:30)
==7175==    by 0x108F2E: set_insert (set.c:66)
==7175==    by 0x108D53: main (settest.c:78)
==7175== 
==7175== Invalid read of size 8
==7175==    at 0x1090A9: set_print (set.c:106)
==7175==    by 0x108E16: main (settest.c:90)
==7175==  Address 0x522f7f0 is 16 bytes inside a block of size 24 free'd
==7175==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10946F: count_free (memory.c:88)
==7175==    by 0x1091BA: set_delete (set.c:151)
==7175==    by 0x108DED: main (settest.c:88)
==7175==  Block was alloc'd at
==7175==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==7175==    by 0x10939B: count_malloc (memory.c:53)
==7175==    by 0x108E37: setpair_new (set.c:30)
==7175==    by 0x108F2E: set_insert (set.c:66)
==7175==    by 0x108D53: main (settest.c:78)
==7175== 
{key4:item3,key3:item3,key2:item2,key1:item1} 
==7175== 
==7175== HEAP SUMMARY:
==7175==     in use at exit: 29 bytes in 2 blocks
==7175==   total heap usage: 12 allocs, 10 frees, 1,177 bytes allocated
==7175== 
==7175== LEAK SUMMARY:
==7175==    definitely lost: 24 bytes in 1 blocks
==7175==    indirectly lost: 5 bytes in 1 blocks
==7175==      possibly lost: 0 bytes in 0 blocks
==7175==    still reachable: 0 bytes in 0 blocks
==7175==         suppressed: 0 bytes in 0 blocks
==7175== Rerun with --leak-check=full to see details of leaked memory
==7175== 
==7175== For counts of detected and suppressed errors, rerun with: -v
==7175== ERROR SUMMARY: 69 errors from 11 contexts (suppressed: 0 from 0)