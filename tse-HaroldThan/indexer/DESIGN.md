# TSE Crawler Design Spec

### User interface

The indexer's only interface with the user is on the command-line; it must always have 2 arguments.

```
./indexer pageDirectory indexFileName
```

For example:

``` bash
$ ./indexer ../data fileIndex
```

### Inputs and outputs

Input: the only inputs are command-line parameters; see the User Interface above.

Output: We save each explored webpage to a file, one file per page.
We use a unique document ID as the file name, for document IDs 1, 2, 3, 4, and so forth.
Within a file, we write

 * the page URL on the first line,
 * the depth of the page (where the seed is depth 0) on the second line,
 * the page contents, beginning on the third line.

### Functional decomposition into modules

We anticipate the following modules or functions:

 1. *main* parses parameters and passes them to the crawler.
 2. *indexer* uses an index to track count of which words appear how many time in which docID
 3. *index_build* build up the index datastructure
 4. *index_save* write content from index datastructure into file
 4. *index_load* load up the indexFile back into Memory

And some helper modules that provide data structures:

 1. *bag* of pages we have yet to explore
 4. *hashtable* of URLs we've seen so far

### Pseudo code for logic/algorithmic flow
# indexer:
Process and validate command-line parameters
Initialize data structure index
index_build(directory, index)
index_save(file, index);
clean up data structures

# indextest:
Process and validate command-line parameters
Initialize data structure index
index_load(file1, index)
index_save(file2, index)
clean up data structures

**normalizeWord** means to convert it into a clean, canonical form.
As one simple example, `WOrd` becomes `word`.


### Dataflow through modules

 1. *main* parses parameters and passes them to the crawler.
 2. *indexer* uses an index to track count of which words appear how many time in which docID
 3. *index_build* build up the index datastructure
 4. *index_save* write content from index datastructure into file
 4. *index_load* load up the indexFile back into Memory

### Major data structures

Three helper modules provide data structures:

 1. *counters* of word appearance in ccertain docID
 2. *hashtable* of key: word and item: counters

### Testing plan
1. Test various inputs to see if indexer will return input errors. 

2. Create Indexer and indextest

3. Point the indexer to the data collected from crawler in ../data2

5. Test Index_load from old to new data file

6. Sort output files content and compare in Test to see if the new index file created from load_index and the old one created from index_save are the same

7. Compare to the correct indexFile Output Provided By Prof.