// Usage: words [filename]...
//
// Input:
//      If No Filename: words reads from stdin.
//      One or more filenames: 1 word/line reads from each file in sequence.
//      If the special filename "-" is given as one of the filenames: the stdin is read at that point in the sequence.
//
// Output:
//      stdout should consist of a sequence of lines, with exactly one word on each output line 
//      (i.e., each output line contains exactly one word and no other characters). 
//      A “word” is a sequence of letters or a single letter.
//      Note: it is possible for the output to be empty, if there are no words in any of the input files.
//
// Harold Than, CS50, Summer 2021

#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>

// Headers
void getWords(FILE * filename);

// Functions
// "Trigger" for a newline is when the current-char(c) is alpha but the next-char(n) behind it it not 
void getWords(FILE * filename){
    int wordCount=0;
    char c=fgetc(filename);
    while (c != EOF){ // Run until end of file
        char n=c;
        c=fgetc(filename);
        if (isalpha(n)){
            //Use putchar(n) instead of printf("c",n) to be more optimal
            fputc(n, stdout);
            if (!isalpha(c)){
                printf("\n");    
                wordCount++;      
            }
        }
    }
    printf("Word Count: %d\n",wordCount);


    char** words=malloc(sizeof(char*) * 25); // Average words in a sentence is 15 to 20, so pick 22 just to be extra safe
    char* line ="    hello this is arean searhch for harold";
    char line_copy[420]; //Assuming things work fine
    strcpy(line_copy,line);
    char* word;
    int count=0;
    printf ("Splitting string \"%s\" into words:\n",line_copy);
    word = strtok (line_copy," ,.-");
    while (word != NULL){
        words[count]=word;
        word = strtok (NULL, " ,.-");
        printf ("%d: %s\n" ,count, words[count]);
        count++;
    }

}


int main(int argc, const char * argv[]){
    // Read From Filenames given in parameter
    if (argc > 1){
        for (int file_index=1; file_index <= argc; file_index++){
            // If Given "-": : the stdin is read at that point in the sequence.
            if (strcmp(argv[file_index], "-") == 0){
                printf("Please Write Out Your Sentence: \n");
                getWords(stdin);
            } else {
            printf("\nLoading data from file %s\n", argv[file_index]);
            FILE *fp = fopen(argv[file_index],"r"); 

            if (fp == NULL){
                fprintf(stderr, "CAN NOT OPEN %s \n", argv[file_index]);
                continue;
            }
            //Read file
            getWords(fp);
            //Close File After Done Reading
            fclose(fp);
            }
        }
    }
    
    // Print Out Word/Line From stdin If no Argument given
    if (argc == 1){ //If No Filename
        printf("Please Write Your Sentence: ");
        getWords(stdin);
    }
}   