// Implement Hashtable To Create New Index Datatype
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "word.h"
#include "pagedir.h"
#include "../libcs50/hashtable.h"
#include "../libcs50/counters.h"
#include "../libcs50/memory.h"
#include "../libcs50/file.h"
#include "../libcs50/webpage.h"


// Index Functions
typedef hashtable_t index_t;
index_t *index_new(const int num_slots);
bool index_insert(index_t *index, char *key, counters_t *ctrs);
counters_t *index_find(index_t *index, const char *key);
void index_delete(index_t *index);
void index_iterate(index_t *index, void *arg, void(*itemfunc)(void *arg, const char *key, void *item));
index_t* index_build(char* pageDirectory, index_t* index);
void index_page(index_t* index, webpage_t* page, const int docID);
bool index_save(index_t *index, char* index_file);
index_t* index_load(char* index_file_name);
char* indexFileName(char* pageDirectory, int docID);