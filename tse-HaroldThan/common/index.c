// Implement Hashtable To Create New Index Datatype
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "word.h"
#include "pagedir.h"
#include "index.h"
#include "../libcs50/hashtable.h"
#include "../libcs50/counters.h"
#include "../libcs50/memory.h"
#include "../libcs50/file.h"
#include "../libcs50/webpage.h"


/**************** Index Data types ****************/
typedef hashtable_t index_t;
static void save_ht_to_file(void *arg, const char *key, void *item);
static void save_counters_to_file(void *arg, const int key, const int count);

static void ct_delete(void *item);
// delete counters item 
static void ct_delete(void *item){
	counters_t* ct = item;

	if (ct != NULL){
		counters_delete(ct);
	}
}

//****************** INDEX FUNCTIONS **********************//
/**************** index_new() ****************/
index_t *index_new(const int num_slots){
	index_t *index;
	index = hashtable_new(num_slots);
	if (index == NULL) {
		fprintf(stderr, "FAILED TO CREATE INDEX\n");
		exit(1);
	}
	return index;
}

/**************** index_insert() ****************/
bool index_insert(index_t *index, char *key, counters_t *ctrs){
    //Normalize word to lowercase (from word.c)
	NormalizeWord(key);
	return hashtable_insert(index, key, ctrs);
}

counters_t *index_find(index_t *index, const char *key){
	return (counters_t*) hashtable_find(index, key);
}

void index_delete(index_t *index){
	hashtable_delete(index, ct_delete);
}
 
/**************** index_iterate() ***************/
void index_iterate(index_t *index, void *arg, void(*itemfunc)(void *arg, const char *key, void *item)){
	hashtable_iterate(index, arg, itemfunc);
}

char* indexFileName(char* pageDirectory, int docID){
	//Build Indexfile's Name
	char *docID_copy = count_malloc(sizeof(char *));
	sprintf(docID_copy, "%d", docID); // make id a string
	size_t filename_length = strlen(docID_copy) + strlen(pageDirectory) + 1;
	char* filename = malloc(filename_length);
	if (filename==NULL){
		fprintf(stderr, "FAILED TO CREATE filename\n");
		return NULL;
	}
	sprintf(filename, "%s/%s", pageDirectory, docID_copy);

	//Clean Up
	count_free(docID_copy);
	return filename;
}

webpage_t* createWebpage(char* pageDirectory, int docID){
	char* filename= indexFileName(pageDirectory, docID);
	if (filename==NULL){
		fprintf(stderr, "createWebpage: Cant Make IndexFileName\n");
		return NULL;
	}
	//Create Webpage Object from filename
	FILE* current_file= pageloader(filename);
	count_free(filename);

	if (current_file!=NULL){
		char* url = freadlinep(current_file); // get URL from first line of the file
		char* depth=freadlinep(current_file); // Get Depth From 2nd Line In String form --> Convert to Int with atoi 
		char* html= freadfilep(current_file); // Get Everything Else
		webpage_t *page = webpage_new(url, atoi(depth), html); //Create webpage_t object from docID data
		if (page!=NULL){
			//Clean Up After Creating Webpage_t
			free(depth);
			return page;
		}

		//Clean Up After Creating Webpage_t
		count_free(url);
		count_free(depth);
		count_free(html);
		count_free(current_file);
		fclose(current_file);

		//Error Message 
		fprintf(stderr,"createWebpage: Failed to Load Current File, returning NULL\n");
		return NULL;
	}
	count_free(current_file);
	return NULL;
}

//====== index_build(): going through all pages in a directory and build Index in 
index_t* index_build(char* pageDirectory, index_t* index){ //Pass In Data Directory and Empty Index Initialized In Main
	int docID=1; //Initialize docID To Be Looped Over

	webpage_t* page;
	//loop over each page data and create Webpage Object
	while ( (page=createWebpage(pageDirectory, docID)) != NULL){   // add a function in pagedir.c (pageloader(): Load Current File From ID)
		//1.index this page
		index_page(index, page, docID); 

		//2. delete this page
		webpage_delete(page);
		
		//3. increment the docID
		docID++;
	}
	//Clean Up Filename 
	return index;
}

//Helper For index_build To Put Words Into Set
void index_page(index_t* index, webpage_t* page, const int docID){
    int pos=0;
    //Insert Every Word As Key To Hashtable
    //Get Word From File 
	char* word;
    while ((word= webpage_getNextWord(page, &pos)) != NULL){
		// 	0.1 check if the word is a trivia word 
		if (strlen(word) >2){
			// 	0.2 find the counters for the word 
			counters_t* curr_cts= index_find(index, word);
			if(curr_cts == NULL){ // If Cant Find Counters, Then Initialize New One
				counters_t* new_cts = counters_new(); //Update new counters to become current running counters
				curr_cts=new_cts; //Add New Word and its new Cts To Index
				index_insert(index, word, curr_cts);
			}
			//Update counters
			counters_add(curr_cts, docID);
		}
		//Clean Up 
		count_free(word);
    }
}

/*************** index_save() *****************/
bool index_save(index_t *index, char* index_file){ //Save Info From Index To File
	// create new output file for index
    FILE *fp = fopen(index_file, "w");
    if (fp!=NULL){ // Error Check File Open
		// Write Index From ht_index to output file
		index_iterate(index, fp, save_ht_to_file);
		// clean up
		fclose(fp);
		return true;
    }
    fprintf(stderr, "Error Opening %s\n", index_file);
	return false;
}

/*************** index_load() *****************/
index_t* index_load(char* index_file_name){// Take file and load it back to memory
	FILE* index_file= fopen(index_file_name,"r");
	if (index_file==NULL){
		fprintf(stderr, "Index_load: Failed To Open %s\n", index_file_name);
	}
	int index_size= lines_in_file(index_file);
	//Create New Index In Memory To Load Data From Index File Into
	index_t* load_index= index_new(index_size);

	char* word;
	int docID, count;
	while ((word=freadwordp(index_file))!=NULL){
		//Create New counters-pair for every id-count load from index_file
		counters_t* cts= counters_new();

		while (fscanf(index_file, "%d %d ", &docID, &count) == 2){
			counters_set(cts, docID, count);
		}
		//Insert The Counters To Load-Index
		index_insert(load_index, word, cts);
		count_free(word);
	}
	//Clean Up
	count_free(word);
	fclose(index_file);

	// Return the new Load-Index In Memory
	return load_index;
}

/*****************Helper Functions********************/
// Save HT
static void save_ht_to_file(void *arg, const char *key, void *item){
    FILE* fp= arg;
	//Print To File The Current Key
	fprintf(fp, "%s ", key);
	counters_iterate(item, arg, save_counters_to_file);
	fprintf(fp,"\n");
}

static void save_counters_to_file(void *arg, const int key, const int count){
    FILE* fp= arg;
	fprintf(fp, "%d %d ", key, count);
}

