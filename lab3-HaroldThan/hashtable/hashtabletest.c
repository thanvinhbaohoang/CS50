//
//
//
//
//
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../set/set.h"
#include "memory.h"
#include "hashtable.h"
#include "jhash.h"
#include "../lib/readlinep.h"


// Itemfunctions Headers
void itemprint(FILE *fp, const char *key, void *item);
void itemdelete(void *item);

//Item Functions
void itemprint(FILE *fp, const char *key, void *item){
  char *item_output=item;
  if (key!=NULL && item_output!=NULL){
    fprintf(fp, "%s:%s", key, item_output);
        // Separate Each Pair With "," Unless It Is The Last Item
  }
}
void itemdelete(void *item){
  if (item!=NULL){
    item=NULL;
  }
}

//Main Function
int main(){
  hashtable_t *hashtable;

  // create a set
  printf("CREATING NEW TABLE WITH 0 SLOTS: Should fail\n");
  hashtable= hashtable_new(0);  
  printf("CREATING NEW TABLE WITH 6 SLOTS\n");
  hashtable = hashtable_new(6);
  printf("PRINTING THE NEW EMPTY TABLE:\n");
  hashtable_print(hashtable, stdout, itemprint);
  if (hashtable == NULL) {
    fprintf(stderr, "hashtable_new failed\n");
    return 1;
  }
  
printf("Testing hashtable_insert...\n");
hashtable_insert(hashtable,"k1", "item1");
hashtable_insert(hashtable,"k2", "item2");
hashtable_insert(hashtable,"k3", "item3");
hashtable_insert(hashtable,"k4", "item4");
hashtable_insert(hashtable,"k5", "item5");
hashtable_insert(hashtable,"randomkey", "random_item");


printf("PRINTING THE TABLE:\n");
hashtable_print(hashtable, stdout, itemprint);

printf("DELETING TABLE...\n");
hashtable_delete(hashtable,itemdelete);
}