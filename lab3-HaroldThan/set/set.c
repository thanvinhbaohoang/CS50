// @Author: Harold Than, CS50, Summer 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "memory.h"

/**************** local types ****************/
typedef struct setpair {
  char *key;                  // Key to the item
  void *item;                 // pointer to data for this item

  struct setpair *next;       // link to next pair
} setpair_t;

/**************** global types ****************/
typedef struct set {
  struct setpair *head;        // Head (First Pair) in Set
} set_t;

/**************** local functions ****************/
static setpair_t *setpair_new(char *key, void *item);
/**************** setpair_new ****************/
/* Allocate and initialize a new pair(key-item) */ // not visible outside this file
static setpair_t *setpair_new(char *key, void *item){
  setpair_t *pair = count_malloc(sizeof(setpair_t));

  if (pair == NULL) {
    // error allocating memory for node; return error
    fprintf(stderr, "FAILED TO CREATE SETPAIR\n");
    return NULL;
  } else {
      pair->key = key;
      pair->item = item;
      return pair;
  }
}

/* Create a new (empty) set; return NULL if error. */
set_t *set_new(void){
    //Allocate Memory For Set
    set_t *set = count_malloc(sizeof(set_t));
    if (set == NULL) {
        return NULL;              // error allocating set
    } else {
        // initialize contents of set structure
        set->head = NULL;
        return set;
    }
}

/* Insert item, identified by a key (string), into the given set.
 * The key string is copied for use by the set.
 * Return false if key exists, any parameter is NULL, or error;
 * return true iff new item was inserted.
 */
bool set_insert(set_t *set, const char *key, void *item){
    if (set != NULL && key != NULL && item != NULL){  //If Valid Conditions
        // The key string is copied for use by the set.
        char *keystring=count_malloc(strlen(key)+1);
        strcpy(keystring, key);
        setpair_t *new_pair = setpair_new(keystring, item); //Create new_pair(key->item) in the set

        // Check To Make Sure Key Is Not Already In The Set
        if ( set_find(set, keystring) == NULL ){      // If cannot find pre-existing key
            //Insertion Of New Pair
            new_pair->next = set->head;       // Set next link of newpair to be the head of set
            set->head = new_pair;             // Make new_pair the new head of the set
            return true;                      //Return true after new item inserted
        }
    }
    fprintf(stderr, "INSERTION FAIL!\n");
    //Return False If None Of Above Condition Is Met
    return NULL;
}

/* Return the item associated with the given key;
 * return NULL if set is NULL, key is NULL, or key is not found.
 */
void *set_find(set_t *set, const char *key){
    if (set != NULL || key!=NULL){
        //Loop Over All Pair In The Set
        for (setpair_t *current_pair= set->head; current_pair != NULL ; current_pair = current_pair->next){
            if (strcmp(key, current_pair->key) == 0){
                fprintf(stderr, "PRE-EXIST KEY FOUND IN SET\n");
                return current_pair->item; //Return Item Associated With Given Key
            }
        }
    }
    // return NULL if No Above Condition Met (set is NULL, key is NULL, or key is not found)
    return NULL; 
}

/* Print the whole set; provide the output file and func to print each item.
 * Ignore if NULL fp. Print (null) if NULL set.
 * Print a set with no items if NULL itemprint.
*/
void set_print(set_t *set, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item) ){
    if (fp != NULL) {
      if (set != NULL){
        fprintf(fp, "{"); // Open Bracket For Set Representation
        for (setpair_t *current_pair= set->head; current_pair!=NULL; current_pair = current_pair->next ){
            if (itemprint != NULL){
                (*itemprint)(fp, current_pair->key, current_pair->item);
                // Separate Each Pair With "," Unless It Is The Last Item
                if (current_pair->next != NULL){
                  fprintf(fp, ",");
                }
            }
        }
        //End Of Set Representation
        fprintf(fp, "} \n");
      } else { //Print NULL if NULL Set
        fprintf(fp, "(null) \n");
      }
    }
}



/* Iterate over all items in the set, in undefined order.
 * Call the given function on each item, with (arg, key, item).
 * If set==NULL or itemfunc==NULL, do nothing.
 */
void set_iterate(set_t *set, void *arg, void (*itemfunc)(void *arg, const char *key, void *item)){
  if (set != NULL && itemfunc != NULL){
      for (setpair_t *current_pair= set->head; current_pair != NULL; current_pair = current_pair->next){
        //Call Given Function On Every Current_pair in set
        (*itemfunc)(arg, current_pair->key, current_pair->item);
      }
  }//  * If set==NULL or itemfunc==NULL, do nothing.
}

/* Delete the whole set; ignore NULL set.
 * Provide a function that will delete each item (may be NULL).
 */
void set_delete(set_t *set, void (*itemdelete)(void *item) ){
  if (set != NULL){
        for (setpair_t *current_pair=set->head; current_pair != NULL;){ //For Loops Don't Update Till Later 
            if (itemdelete != NULL){                 
              (*itemdelete)(current_pair-> item);   // Delete Pair->Item
            }
            
            //Save The Link To Next Pair/ Remember what comes next
            setpair_t *next_pair = current_pair->next;
            //Free Up Allocated Memory
            count_free(current_pair->key);
            count_free(current_pair);

            // Update link to next pair/ Update The For Loop
            current_pair= next_pair;
          }
      //Free Up The Set After Deleting All Of Its Content
      count_free(set);
      }
          //If set==NULL; Do Nothing
  } 


