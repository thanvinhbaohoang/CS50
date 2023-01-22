//a module index.c that contains all the logic for saving and loading index files 
//(this module is common between the Indexer, Querier, and indextest);


#include <stdlib.h>
#include <ctype.h>
#include "word.h"

/**************** NormalizeWord to Lower Case ****************/
char *NormalizeWord (char *word){
  if (word != NULL) {
    for (char *c = word; *c != '\0'; c++)
      *c = tolower(*c);
  }
  return word;
}