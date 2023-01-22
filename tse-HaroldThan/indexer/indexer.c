// Harold Than, CS50 2021X
//Usage: ./indexer pageDirectory indexFilename`

#include <stdio.h>
#include <stdlib.h>
#include "../libcs50/hashtable.h"
#include "../libcs50/set.h"
#include "../libcs50/counters.h"
#include "../libcs50/memory.h"
#include "../common/pagedir.h"
#include "../common/index.h"


/**************** main ****************/
int main(const int argc, char *argv[]){
	//1. Process and validate command-line parameters
	char* program = argv[0];  // program name
	// check input arguments: # of arguments
	if (argc != 3) {
		fprintf(stderr, "Correct Usage: %s pageDirectory indexOutputFileName\n", program);
		return 1; 
	}
	//Turn Inputs To Variables For Easy Access
    char* pageDirectory=argv[1];
    char* index_file= argv[2];

    // Check if Directory Exists
    if (!isCrawlerDirectory(pageDirectory)){
		fprintf(stderr, "NOT A CRAWLER DIRECTORY\n");
		return 1;
	}

	//2. Initialize data structure index
	index_t* index= index_new(420);

	//3. 2. Build the index in memory by loading pages from directory
	index= index_build(pageDirectory, index); 

	//4. save the index to an external file indexFilename
	index_save(index, index_file);

	//5. clean up data structures
	index_delete(index);
	return 0;
}

