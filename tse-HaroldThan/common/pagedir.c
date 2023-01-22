#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "webpage.h"


// 4. *pagesaver*, which outputs a page to the the appropriate file
/**************** TODO: save_page ****************/
//Write the webpage to the  pageDirectory  with 
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

bool isDirectory(char* pageDirectory){
	char* filename = malloc(strlen(pageDirectory)+strlen("/.crawler") + 1);
	sprintf(filename, "%s/.crawler", pageDirectory);
	FILE* fp = fopen(filename, "w");
	free(filename); 

    //Check if directory Exist
	if(fp == NULL){
		fprintf(stderr, "Page directory %s does not exist or is not writable\n", pageDirectory);
		return false;
	}
	fclose(fp); 
    return true;
}

bool isCrawlerDirectory(char *dir){
	char* filename = malloc(strlen(dir)+strlen("/.crawler") + 1);
    sprintf(filename, "%s/.crawler", dir);
	//Try To Open /.crawler file for Read
    printf("isCrawlerDirectory: %s\n", filename);
	FILE* fp= fopen(filename, "r");
	// IF Can Open .crawler then that file exists
	if (fp != NULL){
		fclose(fp);
        printf("%s :Is A Crawler Directory\n", filename);
        free(filename);
		return true;
	} else {
	    fprintf(stderr, "%s Is Not A Crawler Directory\n", dir);
    }
    free(filename);
	return false;
}

/************** pageloader(): Load Current Page DocID ***************/
FILE* pageloader(char* docID){
    char* docID_copy= malloc(20*sizeof(char));
    strcpy(docID_copy, docID);

	FILE *fp = fopen(docID_copy, "r");
    if (fp != NULL){ // error opening file
        free(docID_copy);
        return fp;
    }
    free(docID_copy);
    //Return NULL If Cant Load Page
    return NULL;
}