// Harold Than, CS50, 21X
// * usage: ./crawler seedURL pageDirectory maxDepth`

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libcs50/bag.h"
#include "../libcs50/hashtable.h"
#include "../libcs50/webpage.h"
#include "../libcs50/memory.h"
#include "../common/pagedir.h"
#include "../libcs50/set.h"


// 4. *pagesaver*, which outputs a page to the the appropriate file
/**************** TODO: save_page ****************/
//Write the webpage to the `pageDirectory` with 
//a unique document ID
void pagesaver(int id, webpage_t* page, char* pageDirectory){
        if (page == NULL) {
            fprintf(stderr, "Page is NULL\n");
            return;
        }
        
        char *filename= malloc(strlen(pageDirectory) + 10);
        sprintf(filename, "%s/%d", pageDirectory, id);//Convert ID to filename
        // char* program_name=".crawler";

        //Write File To fp
        FILE *fp= fopen(filename, "w");
        //Error Check
        if (fp == NULL){
            free(filename);
            return;
        }

        //Write Page's HTML to file
        fprintf(fp,"%s\n", webpage_getURL(page) );
        fprintf(fp, "%d\n", webpage_getDepth(page));
        fprintf(fp,"%s\n", webpage_getHTML(page));
        
        // Free filename
        free(filename);
        fclose(fp);   
 
}

//  Retrieve all urls in a page
void pagescanner(hashtable_t* seen_URLs, bag_t* unexplored_pages, webpage_t* page){
    int pos = 0;
    int depth=webpage_getDepth(page);
  //7. for each extracted URL,
    char *current_URL;
    while ((current_URL = webpage_getNextURL(page, &pos)) != NULL){
        //8. 'normalize' the URL and check if isInternal)
        if (NormalizeURL(current_URL) && IsInternalURL(current_URL)){
                //9. try to insert that URL into the *hashtable* of URLs seen
                if ( hashtable_insert(seen_URLs, current_URL, "") ){
                    // 11. if it was added to the table,
                    //12. make a new *webpage* for that URL, at depth+1
                    webpage_t *new_page;
                    new_page= webpage_new(current_URL, depth+1, NULL);  //REMEMBER TO DELETE
                    //13. add the new webpage to the *bag* of webpages to be crawled
                    bag_insert(unexplored_pages, new_page);
                } else {
                    //10. if it was already in the table, do nothing;
                    // webpage_delete(new_page);
                }
                //9. if that URL is not 'internal", ignore it;
            }
            //SHOULD BE HERE BUT GIVING DOUBLE FREE
            // count_free(current_URL);
    }
    count_free(current_URL);
}

// 2. *crawler* uses a bag to track pages to explore, and hashtable to track pages seen; when it explores
// a page it gives the page URL to the pagefetcher, then the result to pagesaver, then to the pagescanner.
void crawler(char* seedURL, char* pageDirectory, int maxDepth){
    //2. insert seedURL to bag and hashtable 
    bag_t *unexplored_pages= bag_new();
    hashtable_t *seen_URLs= hashtable_new(69);

    //2. insert seedURL to bag and hashtable 
	char* seedURL_copy=malloc(strlen(seedURL)+1); //Allocate Memory ----> REMEMBER TO FREEEEEEEEEEEEEEEEEEEEEEEEEEEEE
	strcpy(seedURL_copy, seedURL); //Copy String Instead Of Passing Pointer Directly
	webpage_t *seed_page= webpage_new(seedURL_copy, 0, NULL);	

    //Insert Current seedURL to bag
    bag_insert(unexplored_pages, seed_page);
    //Insert seedURL to hashtable of seen URLs
    hashtable_insert(seen_URLs, seedURL_copy, "");

    //Initialize ID
    int id=1;
    webpage_t *page;
    while ((page= bag_extract(unexplored_pages)) !=NULL){ 
        if (webpage_fetch(page)){//If Successfully Fetched, Pause 1s
            pagesaver(id, page, pageDirectory); //Call PageSaver
            printf("Depth:%d; ID:%d; URL: %s\n", webpage_getDepth(page), id, webpage_getURL(page));
            id++; //Increment id Number

            // 3.4  if depth < max_depth, then scan the page for more URLs (webpage_getNextURL)
            if (webpage_getDepth(page)<maxDepth){
                pagescanner(seen_URLs, unexplored_pages, page); ////Scan Page To Extract Embedded URLs
            } 
        }
        // 3.5  delete the page (remove its memory footprint) (webpage_delete)
        webpage_delete(page); //No Need To Free(seedURL_copy) because webpage_delete() already done it
    }
    bag_delete(unexplored_pages, NULL);
    hashtable_delete(seen_URLs, NULL);
    return;
}



// Run The Crawler Program
/**************** main ****************/
int main(const int argc, char *argv[]){
// 1. check input arguments
	// check input arguments: # of arguments
    // 2. validate it received exactly three command-line arguments
    char* program = argv[0];  // program name
	if (argc != 4) {
		fprintf(stderr, "Try Again! usage: %s seedURL pageDirectory maxDepth \n", program);
		return 1; 
	}

    // Initialize Input To Variables For Easier Access
    char* seedURL = argv[1];  //seedURL
    char* pageDirectory= argv[2];
    int maxDepth=atoi(argv[3]); //Convert User Input Depth to Integer

    // * `seedURL` must be an "internal" URL, as defined below,
    if (!IsInternalURL(seedURL)){
        fprintf(stderr, "Must Be Internal URL Containing: 'http://cs50tse.cs.dartmouth.edu'\n");
        return 2;
    }

	// check input arguments: URL validity
	if (!NormalizeURL(seedURL)) {
		fprintf(stderr, "%s cannot be normalized\n", seedURL);
		return 3;
	}


    //Check For pageDirectory
	char* filename = malloc(strlen(pageDirectory)+strlen("/.crawler") + 1);
	sprintf(filename, "%s/.crawler", pageDirectory);
	FILE* fp = fopen(filename, "w");
	free(filename); 

    //Check if directory Exist
	if(fp == NULL){
		fprintf(stderr, "Page directory %s does not exist or is not writable\n", pageDirectory);
		return 5;
	}
	fclose(fp); 

    // * `maxDepth` must be an integer in the range [0..10].
    if (maxDepth<0 || maxDepth>10){
        fprintf(stderr, "`maxDepth` must be an integer in the range [0..10]\n");
        return 6;
    }

    // 2. call crawl()
    crawler(seedURL, pageDirectory, maxDepth);
    return 0;
}

