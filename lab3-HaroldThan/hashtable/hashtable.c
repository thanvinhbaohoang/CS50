// @Author: Harold Than, CS50, Summer 2021
// 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../set/set.h"
#include "memory.h"
#include "jhash.h"


/**************** global types ****************/
typedef struct hashtable {
  set_t **slots;                      // Array Of Slots
  int num_slots;                      // Number Of Slots In hashtable
} hashtable_t;

/* Create a new hashtable with initialized slots; return NULL if error. */
hashtable_t *hashtable_new(const int num_slots){
    if (num_slots>0){
        //Allocate Memory For HashTable
        hashtable_t *hashtable= count_malloc(sizeof(hashtable_t)); //Initialize Table
        hashtable->slots=count_calloc(num_slots, sizeof(set_t*));
        hashtable->num_slots = num_slots;

        //Initialize HashTable With Each Num Slot being initialized as a set
        for (int i=0; i< num_slots; i++){
          hashtable->slots[i] = set_new();
        }
        //Return NULL if ERROR: Fail To Create Table
        if (hashtable==NULL|| hashtable->slots==NULL){
            return NULL; 
        }
        return hashtable;
    }
    fprintf(stderr,"FAILED: Slots Must Be > 0\n");
    return NULL;
}

/* Insert item, identified by key (string), into the given hashtable.
 * The key string is copied for use by the hashtable.
 * Return false if key exists in ht, any parameter is NULL, or error;
 * return true iff new item was inserted.
 */
bool hashtable_insert(hashtable_t *ht, const char *key, void *item){
    if (ht!= NULL && key != NULL && item != NULL){
      int hash_key= JenkinsHash(key,ht->num_slots);
      set_insert(ht->slots[hash_key], key, item);
      return true; //return true iff new item was inserted.
    }
    // Return false if key exists in ht, any parameter is NULL, or error;
    return false;
}


/* Return the item associated with the given key;
 * return NULL if hashtable is NULL, key is NULL, key is not found.
 */
void *hashtable_find(hashtable_t *ht, const char *key){
    if (ht!=NULL && key!=NULL){
      int hash_key= JenkinsHash(key, ht->num_slots);
      return set_find(ht->slots[hash_key], key);
    }
    return NULL;
}

/* Print the whole table; provide the output file and func to print each item.
 * Ignore if NULL fp. Print (null) if NULL ht.
 * Print a table with no items if NULL itemprint.
 */
void hashtable_print(hashtable_t *ht, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item) ){
    if (fp!=NULL && ht!=NULL){
      if (itemprint!=NULL){
        for (int i=0; i<ht->num_slots; i++){ //Iterate Over Every Slot
          printf("Slot %d: ",i);
          set_print(ht->slots[i],fp, (*itemprint)); //Print Out Current Slot(set)
        }
      }
      //Print Table With No Item if Itemprint==NULL (SHOULD BE DONE AUTOMATICALLY IF set_print FUNCTION CORRECTLY)
    }
    // * Ignore if NULL fp. Print (null) if NULL ht.
  }

/* Iterate over all items in the table; in undefined order.
 * Call the given function on each item, with (arg, key, item).
 * If ht==NULL or itemfunc==NULL, do nothing.
 */
void hashtable_iterate(hashtable_t *ht, void *arg, void (*itemfunc)(void *arg, const char *key, void *item) ){
  if (ht!=NULL && itemfunc!=NULL){
    for (int i=0; i<ht->num_slots; i++){
      //Iterate Over Every Slot (set) In Table
      set_iterate(ht->slots[i], arg, (*itemfunc));
    }
  }
  //If ht==NULL or itemfunc==NULL, do nothing.
}

/* Delete the whole hashtable; ignore NULL ht.
 * Provide a function that will delete each item (may be NULL).
 */
void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item) ){
  if (ht!=NULL){
    for (int i=0; i<ht->num_slots;i++){
      set_delete(ht->slots[i],(*itemdelete));
    }
    count_free(ht);
  }
  //Ignore If NULL ht
}