//Harold Than, CS50, 21X
#include <stdio.h>
#include <stdlib.h>
#include "index.h"

int main(int argc, char* argv[]){
	// check inputs
	if (argc != 3) {
		fprintf(stderr, "Usage:./indextest oldIndexFilename newIndexFilename`\n");
		exit(1);
	}
    //Turn inputs to vars
	char* oldIndexFilename = argv[1];
	char* newIndexFilename = argv[2];

	index_t *index = index_load(oldIndexFilename);
	index_save(index, newIndexFilename);
	
	// clean up
	index_delete(index);
	return 0;
}
