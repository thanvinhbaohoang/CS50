## 'indexer.c'
### 'main'
    Process and validate command-line parameters
    Initialize data structure index
    index_build(directory, index)
    index_save(file, index);
    clean up data structures

### 'index.c'
	Use Hashtable as based Datastructure but create new struct called index_t

### 'index_build'
	Increment docID while dir/docID exists
    Create webpage_t object from current docID
        index current page using index_page()
        delete current webpage after indexing
        increment docID
    return a built index

### 'index_save'
	create indexFile
    write data from provided index from Memory to indexFile

### 'index_load'
    Load indexFile created by index_save
    Load data back into memory



