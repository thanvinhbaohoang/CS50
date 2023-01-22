# TESTING FUNCTIONALITY OUTPUT
f003xd3@plank:~/cs50/labs/tse-HaroldThan/indexer$ ./testing.sh
1. Testing Inputs
Correct Usage: ./indexer pageDirectory indexOutputFileName
Usage:./indextest oldIndexFilename newIndexFilename`
Correct Usage: ./indexer pageDirectory indexOutputFileName
FILENAME isCrawlerDirectory: ../data2/.crawler
../data2/.crawler :Is A Crawler Directory
2. Test Indexer
FILENAME isCrawlerDirectory: ../data2/.crawler
../data2/.crawler :Is A Crawler Directory
3. Use Indextest to write(load) from data/oldIndexFilename to data/newIndexFilename...
4. Sort Files Before Comparison
COMPARING OLD VS NEW:
PASSED: OLD AND NEW FILES MATCHED
5. COMPARING TO PROF'S PROVIDED INDEXFILE
PASSED: MATCHED THE PROF'S PROVIDED OUTPUT

# MEMORY CHECK
gcc -Wall -pedantic -std=c11 -ggdb -DMEMTEST -I../libcs50 -I../common indexer.o ../common/common.a ../libcs50/libcs50-given.a -o indexer
valgrind --leak-check=full --show-leak-kinds=all ./indexer ../data2 indexFile
==26548== Memcheck, a memory error detector
==26548== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==26548== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==26548== Command: ./indexer ../data2 indexFile
==26548== 
FILENAME isCrawlerDirectory: ../data2/.crawler
../data2/.crawler :Is A Crawler Directory
==26548== Invalid write of size 1
==26548==    at 0x4EBF7BF: vsprintf (iovsprintf.c:43)
==26548==    by 0x4EA3183: sprintf (sprintf.c:32)
==26548==    by 0x109955: indexFileName (index.c:73)
==26548==    by 0x10998C: createWebpage (index.c:81)
==26548==    by 0x109B1B: index_build (index.c:122)
==26548==    by 0x109415: main (indexer.c:37)
==26548==  Address 0x523889a is 0 bytes after a block of size 10 alloc'd
==26548==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==26548==    by 0x109903: indexFileName (index.c:68)
==26548==    by 0x10998C: createWebpage (index.c:81)
==26548==    by 0x109B1B: index_build (index.c:122)
==26548==    by 0x109415: main (indexer.c:37)
==26548== 
==26548== Invalid read of size 1
==26548==    at 0x4C34E03: strcpy (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==26548==    by 0x10972D: pageloader (pagedir.c:89)
==26548==    by 0x1099CD: createWebpage (index.c:87)
==26548==    by 0x109B1B: index_build (index.c:122)
==26548==    by 0x109415: main (indexer.c:37)
==26548==  Address 0x523889a is 0 bytes after a block of size 10 alloc'd
==26548==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==26548==    by 0x109903: indexFileName (index.c:68)
==26548==    by 0x10998C: createWebpage (index.c:81)
==26548==    by 0x109B1B: index_build (index.c:122)
==26548==    by 0x109415: main (indexer.c:37)
==26548== 
==26548== 
==26548== HEAP SUMMARY:
==26548==     in use at exit: 4,968 bytes in 9 blocks
==26548==   total heap usage: 1,483 allocs, 1,474 frees, 202,970 bytes allocated
==26548== 
==26548== 4,968 bytes in 9 blocks are still reachable in loss record 1 of 1
==26548==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==26548==    by 0x4EBCF29: __fopen_internal (iofopen.c:65)
==26548==    by 0x4EBCF29: fopen@@GLIBC_2.2.5 (iofopen.c:89)
==26548==    by 0x109740: pageloader (pagedir.c:91)
==26548==    by 0x1099CD: createWebpage (index.c:87)
==26548==    by 0x109B1B: index_build (index.c:122)
==26548==    by 0x109415: main (indexer.c:37)
==26548== 
==26548== LEAK SUMMARY:
==26548==    definitely lost: 0 bytes in 0 blocks
==26548==    indirectly lost: 0 bytes in 0 blocks
==26548==      possibly lost: 0 bytes in 0 blocks
==26548==    still reachable: 4,968 bytes in 9 blocks
==26548==         suppressed: 0 bytes in 0 blocks
==26548== 
==26548== For counts of detected and suppressed errors, rerun with: -v
==26548== ERROR SUMMARY: 20 errors from 2 contexts (suppressed: 0 from 0)