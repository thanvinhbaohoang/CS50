// @Author: Harold Than, CS50, Summer 2021
// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counters.h"
#include "memory.h"


/**************** local types ****************/
typedef struct counterspair {
  int key;                  // Key to the counter
  int count;                 // count of occurences

  struct counterspair *next;       // link to next pair
} counterspair_t;

//Header For Local Function
static counterspair_t *counterspair_new(int key, int count);

//Local Function
counterspair_t *counterspair_new(int key, int count){
 counterspair_t *counterspair = count_malloc(sizeof(counterspair_t));
  if (counterspair == NULL) {
    return NULL;              // error allocating counterspair
  } else {
    // initialize contents of counterspair structure
    counterspair->key = key;
    counterspair->count= count;

    return counterspair;
  }
}
/**************** global types ****************/
typedef struct counters {
  struct counterspair *head;        // Head (First Pair) in Set
} counters_t;

/* Create a new (empty) counter structure; return NULL if error. */
counters_t *counters_new(void){
    counters_t *counters = count_malloc(sizeof(counters_t));
    if (counters == NULL){ // If Fail To Allocate Memory To Create New Counters
        return NULL;
    } else {
        //Initialize Empty Counters Structure
        counters->head = NULL;
        return counters;
    }
}

/* Increment the counter indicated by key; key must be >= 0.
 * If the key does not yet exist, create a counter for it and initialize to 1.
 * Ignore if ctrs is NULL or key is negative.
 * Return the new value of the counter related to the inserted key
 */
int counters_add(counters_t *ctrs, const int key){
    if (ctrs != NULL && key >= 0){
        // Initialize CounterPair If Key Not Yet Exist, Set Count To 1
        if (counters_get(ctrs, key) == 0){                        
            counterspair_t *new_pair= counterspair_new(key, 1);
            if (new_pair !=NULL){        
                // add it to the head of the list
                new_pair->next = ctrs->head;
                ctrs->head = new_pair;
                return new_pair->count;
            }
        } else { //If Found The Key
            for (counterspair_t *current_pair= ctrs-> head; current_pair != NULL; current_pair = current_pair -> next){
                if (current_pair-> key == key){
                    int current_count= counters_get(ctrs,key)+1;        //Get Current Count and increment + 1
                    current_pair->count= current_count;      //Update count to new value
                    return current_count;
                }
            }
        }
    }
    printf("ERROR: Key Must Be >= 0 and Ctrs must NOT be NULL\n");
    return -1;
}

/* Return current value of counter associated with the given key;
 * return 0 if ctrs is NULL or if key is not found.
 */
int counters_get(counters_t *ctrs, const int key){
    if (ctrs != NULL){
        for (counterspair_t *current_pair = ctrs->head; current_pair!= NULL; current_pair= current_pair-> next){
            if (key == current_pair->key){
                return current_pair->count;
            }
        }
    }
    // return 0 if ctrs is NULL or if key is not found.
    return 0;
}

/* Set the current value of counter associated with the given key;
 * If the key does not yet exist, create a counter for it and initialize to
 * the given value. Return false if ctrs is NULL, if key < 0, or count < 0, or if out of memory, otherwise return true.
 */
bool counters_set(counters_t *ctrs, const int key, int count){
    if (ctrs != NULL && key >=0){
        if (counters_get(ctrs, key) !=0){ //If Find Key
                //Find The Pair With Matching Key
                for (counterspair_t *current_pair= ctrs-> head; current_pair != NULL; current_pair = current_pair -> next){
                    if (current_pair-> key == key){
                        current_pair->count= count;      //Set Count To Specified Count Number
                        return true;                     // Return True After Setting New Count
                    }
                }
            }
            // If Can't Find Key, Make New One And Set To Specified Count
            counters_add(ctrs, key);
            counters_set(ctrs, key, count);
            return true;
        }
            return false;
    }


/* Print all counters; provide the output file.
 * Ignore if NULL fp. Print (null) if NULL ctrs.
 */
void counters_print(counters_t *ctrs, FILE *fp){
    if (fp != NULL && ctrs!=NULL){
            fputs("{", fp);

            for (counterspair_t *current_pair=ctrs->head; current_pair != NULL; current_pair= current_pair->next){
                fprintf(fp, "%d", current_pair->key);
                // fputc(current_pair->key, fp);
                fprintf(fp, ":");
                fprintf(fp, "%d", current_pair->count);

                //Separate With ","
                if (current_pair->next != NULL){
                    fputs(",", fp);
                }
            }
           //End Of Set Representation
        fputs("} \n", fp);
      } else { //Print NULL if NULL Set
        fputs("NULL \n", fp);
      }
    }

/* Iterate over all counters in the set (in undefined order):
 * call itemfunc for each item, with (arg, key, count).
 * If ctrs==NULL or itemfunc==NULL, do nothing.
 */
void counters_iterate(counters_t *ctrs, void *arg, void (*itemfunc)(void *arg, const int key, int count)){
    if (ctrs!=NULL){
        if (itemfunc!=NULL){
            for (counterspair_t *current_pair= ctrs->head; current_pair!=NULL; current_pair= current_pair->next){
                // Call itemfunc for each item, with (arg, key, count).
                (*itemfunc)(arg,current_pair->key, current_pair ->count);
            }
        }
    }
}

/* Delete the whole counters. ignore NULL ctrs. */
void counters_delete(counters_t *ctrs){
    if (ctrs!=NULL){
        for (counterspair_t *current_pair= ctrs->head; current_pair!=NULL;){
            counterspair_t *next_pair= current_pair->next; //Remember What Comes Next
            count_free(current_pair);
            //Iterate
            current_pair=next_pair;
        }
    }
    //Delete Counters After Emptying its content
    count_free(ctrs);
}
