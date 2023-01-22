# Function Testing
f003xd3@plank:~/cs50/labs/tse-HaroldThan/crawler$ ./test.sh
1. Test the crawler with a seedURL that points to a non-existent server.
rm -rf *.dSYM  # MacOS debugger info
rm -f *~ *.o
rm -f crawler
gcc -Wall -pedantic -std=c11 -ggdb -DMEMTEST -I../libcs50 -I../common   -c -o crawler.o crawler.c
gcc -Wall -pedantic -std=c11 -ggdb -DMEMTEST -I../libcs50 -I../common crawler.o ../common/common.a ../libcs50/libcs50-given.a -o crawler 
Must Be Internal URL Containing: 'http://cs50tse.cs.dartmouth.edu'
2. Test the crawler with a seedURL that points to a non-internal server.
Must Be Internal URL Containing: 'http://cs50tse.cs.dartmouth.edu'
3. Test the crawler with a seedURL that points to a valid server but non-existent page.
4. Crawl a simple, closed set of cross-linked web pages and explore at depths 0, 1, 2, 3, 4, 5.
./test.sh: line 16: URL: command not found
rm -rf *.dSYM  # MacOS debugger info
rm -f *~ *.o
rm -f crawler
gcc -Wall -pedantic -std=c11 -ggdb -DMEMTEST -I../libcs50 -I../common   -c -o crawler.o crawler.c
gcc -Wall -pedantic -std=c11 -ggdb -DMEMTEST -I../libcs50 -I../common crawler.o ../common/common.a ../libcs50/libcs50-given.a -o crawler 
Depth:0; ID:1; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/index.html
 good at depth 0
Depth:0; ID:1; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/index.html
Depth:1; ID:2; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/A.html
 good at depth 1
Depth:0; ID:1; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/index.html
Depth:1; ID:2; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/A.html
Depth:2; ID:3; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/B.html
 good at depth 2
Depth:0; ID:1; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/index.html
Depth:1; ID:2; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/A.html
Depth:2; ID:3; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/B.html
Depth:3; ID:4; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/E.html
Depth:3; ID:5; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/D.html
Depth:3; ID:6; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/C.html
 good at depth 3
Depth:0; ID:1; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/index.html
Depth:1; ID:2; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/A.html
Depth:2; ID:3; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/B.html
Depth:3; ID:4; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/E.html
Depth:4; ID:5; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/G.html
Depth:4; ID:6; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/F.html
Depth:3; ID:7; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/D.html
Depth:3; ID:8; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/C.html
 good at depth 4
Depth:0; ID:1; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/index.html
Depth:1; ID:2; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/A.html
Depth:2; ID:3; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/B.html
Depth:3; ID:4; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/E.html
Depth:4; ID:5; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/G.html
Depth:5; ID:6; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/H.html
Depth:4; ID:7; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/F.html
Depth:3; ID:8; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/D.html
Depth:3; ID:9; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/C.html
 good at depth 5
Point the crawler at our Wikipedia playground.

# MEMORY TEST
==46411== Memcheck, a memory error detector
==46411== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==46411== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==46411== Command: ./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data 3
==46411== 
Depth:0; ID:1; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/index.html
Depth:1; ID:2; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/A.html
Depth:2; ID:3; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/B.html
Depth:3; ID:4; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/E.html
Depth:3; ID:5; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/D.html
Depth:3; ID:6; URL: http://cs50tse.cs.dartmouth.edu/tse/letters/C.html
==46411== 
==46411== HEAP SUMMARY:
==46411==     in use at exit: 215 bytes in 4 blocks
==46411==   total heap usage: 940 allocs, 936 frees, 209,590 bytes allocated
==46411== 
==46411== 91 bytes in 2 blocks are definitely lost in loss record 1 of 2
==46411==    at 0x4C33B25: calloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==46411==    by 0x10ADCF: webpage_getNextURL (webpage.c:428)
==46411==    by 0x1094DC: pagescanner (crawler.c:54)
==46411==    by 0x109642: crawler (crawler.c:105)
==46411==    by 0x109860: main (crawler.c:168)
==46411== 
==46411== 124 bytes in 2 blocks are definitely lost in loss record 2 of 2
==46411==    at 0x4C33B25: calloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==46411==    by 0x10BDC3: FixupRelativeURL (webpage.c:1072)
==46411==    by 0x10ADA6: webpage_getNextURL (webpage.c:424)
==46411==    by 0x1094DC: pagescanner (crawler.c:54)
==46411==    by 0x109642: crawler (crawler.c:105)
==46411==    by 0x109860: main (crawler.c:168)
==46411== 
==46411== LEAK SUMMARY:
==46411==    definitely lost: 215 bytes in 4 blocks
==46411==    indirectly lost: 0 bytes in 0 blocks
==46411==      possibly lost: 0 bytes in 0 blocks
==46411==    still reachable: 0 bytes in 0 blocks
==46411==         suppressed: 0 bytes in 0 blocks
==46411== 
==46411== For counts of detected and suppressed errors, rerun with: -v
==46411== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
f003xd3@plank:~/cs50/labs/tse-HaroldThan/crawler$ 