# CS50 Lab 3
## CS50 Summer 2021

### Functionality test

Various functionality tests are conducted in counterstest.c: 

* TEST 1: creating an empty counters
* TEST 2: inserting counters_pairs into a valid counters
* TEST 3: inserting counters_pairs into a null counters
* TEST 4: inserting null item into a valid counters
* TEST 5: inserting null item into a null counters
* TEST 6: printing counters_pairs in a valid counters
* TEST 7: counters_set with pre-existing key
* Test 8: counters_set with new key 
* TEST 9: deleting a valid counters


#### Functionality test output
```bash
./counterstest < test.number
Count (should be zero): 0
testing counters_add...
Count (should be 20): 20
test with null counters, good item...
ERROR: Key Must Be >= 0 and Ctrs must NOT be NULL
test with invalid key...
ERROR: Key Must Be >= 0 and Ctrs must NOT be NULL
test with null counters, null item...
ERROR: Key Must Be >= 0 and Ctrs must NOT be NULL
The counters:
{20:1,19:1,18:1,17:1,16:1,15:1,14:1,13:1,12:1,11:1,10:1,9:1,8:1,7:1,6:1,5:1,4:1,3:1,2:1,1:1} 

testing counters_add...
Manually Add 1; 3 more times
The counters:
{20:1,19:1,18:1,17:1,16:1,15:1,14:1,13:1,12:1,11:1,10:1,9:1,8:1,7:1,6:1,5:1,4:1,3:1,2:1,1:4} 

testing counters_set....
Set Pre-existing Counter: called counters_set(counters, 1, 30) 
Set New Counter: called counters_set(counters, 23, 30) 
The counters:
{23:30,20:1,19:1,18:1,17:1,16:1,15:1,14:1,13:1,12:1,11:1,10:1,9:1,8:1,7:1,6:1,5:1,4:1,3:1,2:1,1:30} 

delete the counters...
```
The above output excludes the compilation output with `gcc`.

### Memory test
vf003xd3@plank:~/cs50/labs/lab3-HaroldThan/counters$ make valgrind
gcc -Wall -pedantic -std=c11 -ggdb -DMEMTEST -I../lib   -c -o counterstest.o counterstest.c
gcc -Wall -pedantic -std=c11 -ggdb -DMEMTEST -I../lib   -c -o counters.o counters.c
gcc -Wall -pedantic -std=c11 -ggdb -DMEMTEST -I../lib counterstest.o counters.o ../lib/readlinep.o ../lib/memory.o  -o counterstest
valgrind ./counterstest < test.number
==22399== Memcheck, a memory error detector
==22399== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==22399== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==22399== Command: ./counterstest
==22399== 
Count (should be zero): 0
testing counters_add...
Count (should be 20): 20
test with null counters, good item...
ERROR: Key Must Be >= 0 and Ctrs must NOT be NULL
test with invalid key...
ERROR: Key Must Be >= 0 and Ctrs must NOT be NULL
test with null counters, null item...
ERROR: Key Must Be >= 0 and Ctrs must NOT be NULL
The counters:
{20:1,19:1,18:1,17:1,16:1,15:1,14:1,13:1,12:1,11:1,10:1,9:1,8:1,7:1,6:1,5:1,4:1,3:1,2:1,1:1} 

testing counters_add...
Manually Add 1; 3 more times
The counters:
{20:1,19:1,18:1,17:1,16:1,15:1,14:1,13:1,12:1,11:1,10:1,9:1,8:1,7:1,6:1,5:1,4:1,3:1,2:1,1:4} 

testing counters_set....
Set Pre-existing Counter: called counters_set(counters,1, 30) 
Set New Counter: called counters_set(counters,23, 30) 
The counters:
{23:30,20:1,19:1,18:1,17:1,16:1,15:1,14:1,13:1,12:1,11:1,10:1,9:1,8:1,7:1,6:1,5:1,4:1,3:1,2:1,1:30} 

delete the counters...
==22399== 
==22399== HEAP SUMMARY:
==22399==     in use at exit: 0 bytes in 0 blocks
==22399==   total heap usage: 44 allocs, 44 frees, 11,180 bytes allocated
==22399== 
==22399== All heap blocks were freed -- no leaks are possible
==22399== 
==22399== For counts of detected and suppressed errors, rerun with: -v
==22399== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)