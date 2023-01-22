### FUNCTION TESTING
isCrawlerDirectory: ../data2/.crawler
../data2/.crawler :Is A Crawler Directory
Splitting "and" into words:
QUERY: and 
Error: 'and' cannot be last
Splitting "or" into words:
QUERY: or 
Error: 'or' cannot be last
Splitting "and dartmouth" into words:
QUERY: and dartmouth 
Error: 'and' cannot be first
Splitting "or dartmouth" into words:
QUERY: or dartmouth 
Error: 'or' cannot be first
Splitting "dartmouth college or" into words:
QUERY: dartmouth college or 
Error: 'or' cannot be last
Splitting "dartmouth college and" into words:
QUERY: dartmouth college and 
Error: 'and' cannot be last
Splitting "dartmouth college and or computer" into words:
QUERY: dartmouth college and or computer 
the literals ('and' & 'or') cannot be adjacent
Splitting "dartmouth college and and computer" into words:
QUERY: dartmouth college and and computer 
the literals ('and' & 'or') cannot be adjacent
Splitting "dartmouth college or and computer" into words:
QUERY: dartmouth college or and computer 
the literals ('and' & 'or') cannot be adjacent
Error: bad character '5' in query
Error: bad character '!' in query
Error: bad character '-' in query
Splitting "tse" into words:
QUERY: tse 
Matched 1 Documents: 
Score: 1 DocID:1 :http://cs50tse.cs.dartmouth.edu/tse/letters/index.html 
----------------------------------------------------------------------
Splitting "home" into words:
QUERY: home 
Matched 9 Documents: 
Score: 2 DocID:1 :http://cs50tse.cs.dartmouth.edu/tse/letters/index.html 
Score: 1 DocID:2 :http://cs50tse.cs.dartmouth.edu/tse/letters/A.html 
Score: 1 DocID:3 :http://cs50tse.cs.dartmouth.edu/tse/letters/B.html 
Score: 1 DocID:4 :http://cs50tse.cs.dartmouth.edu/tse/letters/E.html 
Score: 1 DocID:5 :http://cs50tse.cs.dartmouth.edu/tse/letters/G.html 
Score: 1 DocID:6 :http://cs50tse.cs.dartmouth.edu/tse/letters/H.html 
Score: 1 DocID:7 :http://cs50tse.cs.dartmouth.edu/tse/letters/F.html 
Score: 1 DocID:8 :http://cs50tse.cs.dartmouth.edu/tse/letters/D.html 
Score: 1 DocID:9 :http://cs50tse.cs.dartmouth.edu/tse/letters/C.html 
----------------------------------------------------------------------
Splitting "algorithm" into words:
QUERY: algorithm 
Matched 1 Documents: 
Score: 1 DocID:2 :http://cs50tse.cs.dartmouth.edu/tse/letters/A.html 
----------------------------------------------------------------------
f003xd3@plank:~/cs50/labs/tse-HaroldThan/querier$ 




##### MEMORY TESTING 
gcc -Wall -pedantic -std=c11 -ggdb -DMEMTEST -I../libcs50 -I../common querier.o ../common/common.a ../libcs50/libcs50-given.a -o querier
valgrind --leak-check=full --show-leak-kinds=all ./querier ../data2 ../data2/oldIndexFilename
==11621== Memcheck, a memory error detector
==11621== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11621== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==11621== Command: ./querier ../data2 ../data2/oldIndexFilename
==11621== 
home
isCrawlerDirectory: ../data2/.crawler
../data2/.crawler :Is A Crawler Directory
Splitting "home" into words:
QUERY: home 
Matched 9 Documents: 
==11621== Invalid write of size 1
==11621==    at 0x4EBF7BF: vsprintf (iovsprintf.c:43)
==11621==    by 0x4EA3183: sprintf (sprintf.c:32)
==11621==    by 0x10A55A: indexFileName (index.c:73)
==11621==    by 0x109932: print_results (querier.c:179)
==11621==    by 0x109E76: run_query (querier.c:296)
==11621==    by 0x109F38: process_query (querier.c:314)
==11621==    by 0x10A031: main (querier.c:338)
==11621==  Address 0x523602a is 0 bytes after a block of size 10 alloc'd
==11621==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==11621==    by 0x10A508: indexFileName (index.c:68)
==11621==    by 0x109932: print_results (querier.c:179)
==11621==    by 0x109E76: run_query (querier.c:296)
==11621==    by 0x109F38: process_query (querier.c:314)
==11621==    by 0x10A031: main (querier.c:338)
==11621== 
==11621== Syscall param openat(filename) points to unaddressable byte(s)
==11621==    at 0x4F4DD5E: open (open64.c:47)
==11621==    by 0x4ECA659: _IO_file_open (fileops.c:189)
==11621==    by 0x4ECA659: _IO_file_fopen@@GLIBC_2.2.5 (fileops.c:281)
==11621==    by 0x4EBCF89: __fopen_internal (iofopen.c:78)
==11621==    by 0x4EBCF89: fopen@@GLIBC_2.2.5 (iofopen.c:89)
==11621==    by 0x109949: print_results (querier.c:180)
==11621==    by 0x109E76: run_query (querier.c:296)
==11621==    by 0x109F38: process_query (querier.c:314)
==11621==    by 0x10A031: main (querier.c:338)
==11621==  Address 0x523602a is 0 bytes after a block of size 10 alloc'd
==11621==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==11621==    by 0x10A508: indexFileName (index.c:68)
==11621==    by 0x109932: print_results (querier.c:179)
==11621==    by 0x109E76: run_query (querier.c:296)
==11621==    by 0x109F38: process_query (querier.c:314)
==11621==    by 0x10A031: main (querier.c:338)
==11621== 
Score: 2 DocID:1 :http://cs50tse.cs.dartmouth.edu/tse/letters/index.html 
Score: 1 DocID:2 :http://cs50tse.cs.dartmouth.edu/tse/letters/A.html 
Score: 1 DocID:3 :http://cs50tse.cs.dartmouth.edu/tse/letters/B.html 
Score: 1 DocID:4 :http://cs50tse.cs.dartmouth.edu/tse/letters/E.html 
Score: 1 DocID:5 :http://cs50tse.cs.dartmouth.edu/tse/letters/G.html 
Score: 1 DocID:6 :http://cs50tse.cs.dartmouth.edu/tse/letters/H.html 
Score: 1 DocID:7 :http://cs50tse.cs.dartmouth.edu/tse/letters/F.html 
Score: 1 DocID:8 :http://cs50tse.cs.dartmouth.edu/tse/letters/D.html 
Score: 1 DocID:9 :http://cs50tse.cs.dartmouth.edu/tse/letters/C.html 
----------------------------------------------------------------------
==11621== 
==11621== HEAP SUMMARY:
==11621==     in use at exit: 72 bytes in 9 blocks
==11621==   total heap usage: 229 allocs, 220 frees, 95,307 bytes allocated
==11621== 
==11621== 72 bytes in 9 blocks are definitely lost in loss record 1 of 1
==11621==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==11621==    by 0x109C83: sort_docs (querier.c:255)
==11621==    by 0x10B0AA: counters_iterate (counters.c:197)
==11621==    by 0x109E60: run_query (querier.c:293)
==11621==    by 0x109F38: process_query (querier.c:314)
==11621==    by 0x10A031: main (querier.c:338)
==11621== 
==11621== LEAK SUMMARY:
==11621==    definitely lost: 72 bytes in 9 blocks
==11621==    indirectly lost: 0 bytes in 0 blocks
==11621==      possibly lost: 0 bytes in 0 blocks
==11621==    still reachable: 0 bytes in 0 blocks
==11621==         suppressed: 0 bytes in 0 blocks
==11621== 
==11621== For counts of detected and suppressed errors, rerun with: -v
==11621== ERROR SUMMARY: 19 errors from 3 contexts (suppressed: 0 from 0)