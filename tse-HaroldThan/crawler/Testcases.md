### 15 test cases. Before testing, you should create several target folders.

#### T1-T6 are testing input checking. 2 points each, 6 * 2 = 12 points in total.

T1:
Command  
./crawler http://cs50tse.cs.dartmouth.edu/tse/ 

Expected value: lack of arguments


T2:
Command  
./crawler http://cs50tse.cs.dartmouth.edu/tse/ target2 -4

Expected value: incorrect value

T3:
Command
./crawler http://cs50tse.cs.dartmouth.edu/tse/ donotcreatethefolder 1

Expected value: cannot write the folder (when the folder does not exist)

T4:
Command
./crawler http://www.saisld3210df.com/ target4 1

Expected value: non-existent server

T5:
Command
./crawler http://www.dartmouthcoach.com/freeticket target5 1

Expected value: non-existent page

T6:
Command ./crawler http://www.google.com/ target6 1

Expected value: not internal seed


#### Test 7-11 are based on http://cs50tse.cs.dartmouth.edu/~cs50/data/tse/letters/, 2 points each, 5 * 2 = 10 points in total.

T7:
Command 
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html  target7 0

Expected value: 1

T8:
Command 
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html target8 1

Expected value: 2

T9:
Command 
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html target9 2

Expected value: 3

T10:
Command
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html  target10 3

Expected value: 6

T11:
Command
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html target11 4

Expected value: 8


#### For Test 12-15, if #files in target folder is close to the expected value, it is still correct. 11 points in total.

T12: (2 points)
Command
./crawler http://cs50tse.cs.dartmouth.edu/tse/wikipedia/Computer_science.html target12 0

Expected value: 1

T13: (3 points)
Command
./crawler http://cs50tse.cs.dartmouth.edu/tse/wikipedia/Computer_science.html target13 1

Expected value:345

T14: (3 points)
Command
./crawler http://cs50tse.cs.dartmouth.edu/tse/wikipedia/Computer_science.html target14 2 

Expected value: 849

T15: (3 points)
Command
./crawler http://cs50tse.cs.dartmouth.edu/tse/wikipedia/Computer_science.html target15 3

Expected value: 1550



