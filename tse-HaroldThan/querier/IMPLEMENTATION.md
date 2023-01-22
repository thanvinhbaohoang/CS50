# TSE querier Design Spec

### User interface

The querier's only interface with the user is on the command-line; it must always have 2 arguments.

```
./querier pageDirectory indexFileName
```

### Inputs and outputs

Input: the only inputs are command-line parameters; see the User Interface above.

Output: Scores, docId and URL Of Matched document
 * the page URL on the first line,

### Functional decomposition into modules

We anticipate the following modules or functions:

 1. *main* parses parameters and passes them to the querier.
 2. *process_query* process the user input queries
 3. *run-query* Create A Ranked Querier Array (docs_ranking)

And some helper modules that provide data structures:

 1. *bag* of andSequences from user's Query
 4. *index* from indexFileName Used To Find Matching Words

### Pseudo code for logic/algorithmic flow
## 'indexer.c'
### 'main'
    Process and validate command-line parameters
    Load IndexFile with index_load()
    Process Query with process_query()
    clean up data structures

### 'process_query()'
	Read Each Line From Stdin As Queries Input From User
    Parse Queries
        Extract Input into words
        Get Number Of Words
        Print Query Words
        if Valid Query
            Run The Query (run_query())

### 'run_query()'
	1.Create Result counters With DocID and Score(create_scores())
    Count Number Of Items in Result-counters
    2.Sort Result-Counters into new Docs_ranking Array (sort_docs)
    3.Print Out Result (print_results())
    4.Clean Up

### 'create_scores()'
	1. Create Bag of andCounters To Keep every andSequence
    2. Copy Index's Items To current andCounter
    3. Loop Over Every Query Word
        3.1 If Word Is "OR"
            Insert Current andSequence Into Bag
        3.2 If Is Non-Literal Word (!="and")
            find Word in Index
            Find Intersection Of The Word's Counters in {andCounter, Current Word's Index's Counter}
    4. Add Up All The andSequence in Bag By Counters_Union()
    5. Return Final Result Counters

### 'sort_docs()'
    Sort By Order Of Decreasing Score
    1. If Only 1 Item Then No Sort
    2. Loop Over docs Array
        2.1 While The Doc[i-1] < Doc[i]
        2.2 Change doc[i] to become the prev doc[i-1]
        2.3 Update Current Running i (index)
    3. Update docs_ranking
    4. Increment Current Index

### Dataflow through modules

 1. *main* parses parameters and passes them to the querier.
 2. *run_query* uses an 

### Major data structures

Three helper modules provide data structures:
 1. *counters* of word appearance in ccertain docID
 2. *index* of counters: word and item: counters
 3. *bag* of andSequences for Intersecting and Uniting

### Testing plan
1. Test various inputs to see if querier will return input errors. 
