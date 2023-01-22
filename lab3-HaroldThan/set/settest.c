/* 
 * settest.c - test program for CS50 set module
 *
 * usage: read lines from stdin
 *
 * CS50, Summer 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "../lib/readlinep.h"
#include "../lib/memory.h"


void itemprint(FILE *fp, const char *key, void *item);
void itemdelete(void *item);

void itemprint(FILE *fp, const char *key, void *item){
  char *item_output=item;
  if (key!=NULL && item_output!=NULL){
    fprintf(fp, "%s:%s", key, item_output);
        // Separate Each Pair With "," Unless It Is The Last Item
  }
}

void itemdelete(void *item){
  if (item!=NULL){
      item = NULL;
  }
}

/* **************************************** */
int main() {
  set_t *set;

  // create a set
  set = set_new();
  if (set == NULL) {
    fprintf(stderr, "set_new failed\n");
    return 1;
  }

printf("Testing set_insert.....\n");
char *key1 ="key1"; 
char *key2 ="key2"; 
char *key3 ="key3"; 
printf("Call set_insert(set, key1, item1):\n");
set_insert(set, key1, "item1");
printf("Call set_insert(set, key2, item2):\n");
set_insert(set, key2, "item2");
printf("Call set_insert(set, key3, item3):\n");
set_insert(set, key3, "item3");
printf("TESTING set_print with valid set, itemprint= NULL: Should Print empty set {}:\n");
set_print(set, stdout, NULL);
printf("TESTING set_print with NULL set, valid itemprint_int: Should Print (NULL):\n");
set_print(NULL, stdout, itemprint);
printf("TESTING set_print with valid set, valid itemprint_int function:\n");
set_print(set, stdout, itemprint);
printf("Testing set_insert with NULL key, valid item\n");
set_insert(set, NULL, "item2");
printf("Testing set_insert with valid key, NULL item\n");
set_insert(set, "valid_key", NULL);


char *key3duplicate ="key3"; 
printf("Call set_insert(set, key3duplicate, item3duplicate)\n");
set_insert(set, key3duplicate, "item3");
printf("The Set:\n");
set_print(set, stdout, itemprint);

char *key4 ="key4"; 
printf("Call set_insert(set, key4, item3)\n");
set_insert(set, key4, "item3");
printf("The Set:\n");
set_print(set, stdout, itemprint);

printf("deleting the set...\n");
// printf("itemdelete=NULL; Do Nothing\n");
// set_delete(set, NULL);
printf("The Set:\n");
set_print(set, stdout, itemprint);
printf("valid itemdelete; Should Empty The Set\n");
set_delete(set, itemdelete);
printf("The Set:\n");
set_print(set, stdout, itemprint);
}
