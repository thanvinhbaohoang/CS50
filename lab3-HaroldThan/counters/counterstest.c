/* 
 * counterstest.c - test program for CS50 counters module
 *
 * usage: read lines from stdin
 *
 * CS50, Summer 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counters.h"
#include "../lib/readlinep.h"

static void itemcount(void *arg, const int key, int count);

/* count the non-null items in the counters.
 * note here we don't care what kind of item is in counters.
 */
static void itemcount(void *arg, const int key, int count){
  int *nitems = arg;
  if (nitems != NULL && key != 0 && count !=0){
    (*nitems)++;
  }
}

/* **************************************** */
int main() {
  counters_t *counters;
  int keycount = 0;

  // create a counters
  counters = counters_new();
  if (counters == NULL) {
    fprintf(stderr, "counters_new failed\n");
    return 1;
  }


  printf("Count (should be zero): ");
  counters_iterate(counters, &keycount, itemcount);
  printf("%d\n", keycount);  

  printf("testing counters_add...\n");
  // read lines from stdin
  keycount = 0;
  while (!feof(stdin)) {
    char *key = readlinep();
    if (key != NULL) {
      counters_add(counters, atoi(key));
      keycount++;
      free(key);
    }
  }

  printf("Count (should be %d): ", keycount);
  keycount = 0;
  counters_iterate(counters, &keycount, itemcount);
  printf("%d\n", keycount);  

  printf("test with null counters, good item...\n");
  counters_add(NULL, 1);
  printf("test with invalid key...\n");
  counters_add(counters, -1); 
  printf("test with null counters, null item...\n");
  counters_add(NULL, -1);
  printf("The counters:\n");
  counters_print(counters, stdout);
  printf("\n");


  printf("testing counters_add...\n");
  printf("Manually Add 1; 3 more times\n");
  counters_add(counters, 1); 
  counters_add(counters, 1); 
  counters_add(counters, 1); 
  printf("The counters:\n");
  counters_print(counters, stdout);
  printf("\n");


  printf("testing counters_set....\n");
  printf("Set Pre-existing Counter: called counters_set(counters,1, 30) \n");
  counters_set(counters, 1, 30);
  printf("Set New Counter: called counters_set(counters,23, 30) \n");
  counters_set(counters, 23, 30);
  printf("The counters:\n");
  counters_print(counters, stdout);
  printf("\n");

  printf("delete the counters...\n");
  counters_delete(counters);

  return 0;
}



