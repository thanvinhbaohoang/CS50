# CS50 Lab 3
## CS50 Summer 2021

### Functionality test
TEST 1: CREATING NEW TABLE WITH 0 SLOTS:
TEST 2: CREATING NEW TABLE WITH 6 SLOTS
TEST 3: PRINTING THE NEW EMPTY TABLE:
TEST 4: TEST INSERT WITH NEW KEYS
TEST 5: TEST INSERT WITH PRE-EXISTING KEY
TEST 6: TEST DELETE

### TEST FILE OUTPUT
./hashtabletest 
CREATING NEW TABLE WITH 0 SLOTS: Should fail
FAILED: Slots Must Be > 0
CREATING NEW TABLE WITH 6 SLOTS
PRINTING THE NEW EMPTY TABLE:
Slot 0: {} 
Slot 1: {} 
Slot 2: {} 
Slot 3: {} 
Slot 4: {} 
Slot 5: {} 
Testing hashtable_insert...
PRINTING THE TABLE:
Slot 0: {k3:item3} 
Slot 1: {} 
Slot 2: {randomkey:random_item} 
Slot 3: {k5:item5,k4:item4,k2:item2,k1:item1} 
Slot 4: {} 
Slot 5: {} 
DELETING TABLE...

### MEMORY TEST
valgrind ./hashtabletest
==14653== Memcheck, a memory error detector
==14653== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==14653== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==14653== Command: ./hashtabletest
==14653== 
CREATING NEW TABLE WITH 0 SLOTS: Should fail
FAILED: Slots Must Be > 0
CREATING NEW TABLE WITH 6 SLOTS
PRINTING THE NEW EMPTY TABLE:
Slot 0: {} 
Slot 1: {} 
Slot 2: {} 
Slot 3: {} 
Slot 4: {} 
Slot 5: {} 
Testing hashtable_insert...
PRINTING THE TABLE:
Slot 0: {k3:item3} 
Slot 1: {} 
Slot 2: {randomkey:random_item} 
Slot 3: {k5:item5,k4:item4,k2:item2,k1:item1} 
Slot 4: {} 
Slot 5: {} 
DELETING TABLE...
==14653== 
==14653== HEAP SUMMARY:
==14653==     in use at exit: 48 bytes in 1 blocks
==14653==   total heap usage: 21 allocs, 20 frees, 1,305 bytes allocated
==14653== 
==14653== LEAK SUMMARY:
==14653==    definitely lost: 48 bytes in 1 blocks
==14653==    indirectly lost: 0 bytes in 0 blocks
==14653==      possibly lost: 0 bytes in 0 blocks
==14653==    still reachable: 0 bytes in 0 blocks
==14653==         suppressed: 0 bytes in 0 blocks
==14653== Rerun with --leak-check=full to see details of leaked memory
==14653== 
==14653== For counts of detected and suppressed errors, rerun with: -v
==14653== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)