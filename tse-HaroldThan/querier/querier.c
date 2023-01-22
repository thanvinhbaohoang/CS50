// //CS50, Harold Than, 21X
// // Usage: ./querier pageDirectory indexFilename

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "../common/index.h"
#include "../libcs50/file.h"
#include "../libcs50/bag.h"
#include "../libcs50/counters.h"
#include "../libcs50/memory.h"
/******** local data types *******/
typedef struct doc{
	int docID;
	int score;
} doc_t;

typedef struct docs_ranking{
    doc_t** docs; //Array of doc(s)
    int index;
} docs_ranking_t;
//**************************** Headers 
bool isLiteral(char* word);
int extract_words(char* line, char** words);
bool valid_query(char** words, int nwords);
void print_query_words(int nwords, char** words);
void counter_copy(void *arg, const int key, const int count);
void countResultItems(void *arg, const int key, const int count);
void counters_union(void *arg, const int key, const int count);
static inline int min(const int a, const int b) ;
void intersect_helper(void *arg, const int key, const int count);
static void print_results(docs_ranking_t* docs_ranking, char* pageDirectory, int resultNumber);
counters_t* create_scores(index_t* index, char** words,int nwords);
void sort_docs(void *arg, const int key, const int count);
void run_query(char** words, int nwords, index_t* index, char* pageDirectory);
void process_query(index_t* index, char* pageDirectory);



//Check if Word Is "and" or "or"
bool isLiteral(char* word){
    if ( strcmp(word,"and")==0){
        return true;
    }
    if ( strcmp(word,"or")==0){
        return true;
    }
    return false;

}

//Given line and empty words array, extract words from line to words_array and return number of words
int extract_words(char* line, char** words){
	int line_size = strlen(line);
    int count=0;
    // 1. Input Testing/ Filter Out Illegal Chars
	char curr_char;
	for (int i = 0; i < line_size; i++) {
		curr_char = line[i];
        // Filter Non-Alpha And Non-Space Characters
		if (!isalpha(curr_char) && !isspace(curr_char)){
			fprintf(stderr, "Error: bad character '%c' in query\n", curr_char);
			return 0;
		}
	}
    // 2. Normalize All Chars In line
    NormalizeWord(line);

    // 3. Count Words in Line (Taken from Lab2-words)
    // 4. Split Words From Line To words_array
    // Start both iterators at beginning of string
    char* word;
    int i=0; //Index For Words Array
    printf ("Splitting \"%s\" into words:\n",line);
    word = strtok(line," ,.-");
    while (word != NULL){
        //Assigning Current Word To Words[i] array
        words[i]=word;
        i++;
        word = strtok(NULL, " ,.-");
    }
    //Word Count is Highest Index
    count= i;

    // for (int j=0; j<count;j++){
    //     printf("%d: %s\n",j, words[j]);
    // }

    //Return Words Count
	return count;
}
//Check If Query Is Of Correct Format
bool valid_query(char** words, int nwords){
    //Check First and Last
    if (isLiteral(words[nwords-1])) {
		fprintf(stderr, "Error: '%s' cannot be last\n", words[nwords-1]);
		return false;
	} else if (isLiteral(words[0])) {
			fprintf(stderr, "Error: '%s' cannot be first\n", words[0]);		
        return false;
	}

	char* curr_word = words[0];
	char* prev_word = curr_word;
	//Check Adjacents
	for (int i = 0; i < nwords; i++) {
		curr_word = words[i];
		if (isLiteral(prev_word) && isLiteral(curr_word)) {
			fprintf(stderr, "the literals ('and' & 'or') cannot be adjacent\n");
			return false;
		} 
        //Update Previous Word
		prev_word = curr_word;
	}
	return true;
}

// Print Out The Query in process_query()
void print_query_words(int nwords, char** words){
    printf("QUERY: ");
    for (int i=0; i<nwords; i++){
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Copies a counter into another
void counter_copy(void *arg, const int key, const int count){
    if (arg != NULL){
    counters_t *otherCounter = (counters_t *) arg;
    counters_set(otherCounter, key, count);
    }
}

//*****************HELPER FOR CREATE_SCORES****************
// Incremement Count For Total Non-Zero Items in Counters
void countResultItems(void *arg, const int key, const int count){
    int *resultNumber = arg;
    if (resultNumber!=NULL && count!=0){
        (*resultNumber)++;
    }
}
// Union Of All The andSequence To Give Final Result
void counters_union(void *arg, const int key, const int count){
    if (arg!=NULL){
        counters_t *result_cts = (counters_t*)arg;
        //Add The Key-Count Of Current Counters to Result_counters
        int sum= count + counters_get(result_cts, key);
        counters_set(result_cts, key, sum);
    }
}
//Simple Return Minimum Value
static inline int min(const int a, const int b) {
  return (a < b ? a : b);
}

//Helper To Intersect Counters
void intersect_helper(void *arg, const int key, const int count){
	counters_t** two_counters = (counters_t**)arg; 
    int otherCountersCount= counters_get(two_counters[1], key);
    //Instead Of Using two_counters, Just use counters** array(0:andSequence, 1:Other cts)
	counters_set(two_counters[0], key, min(count, otherCountersCount));
}

// Print Every Doc In Docs_Ranking
static void print_results(docs_ranking_t* docs_ranking, char* pageDirectory, int resultNumber){
    // 0 Case
    if (resultNumber==0){
        fprintf(stderr,"No documents matched.\n");
        return;
    }

    // Print Result
    doc_t** docs= docs_ranking->docs;
    int size= resultNumber;
    // Number Of Matches
    printf("Matched %d Documents: \n", resultNumber);
    
    // score: docID:
    for (int i=0; i<size; i++){
        //Create Filename 
        char* filename= indexFileName(pageDirectory, docs[i]->docID);
        FILE* fp= fopen(filename, "r");
        if (fp==NULL){
            fprintf(stderr, "Print_result: Can't Open %s\n", filename);
        }

        //Get URL From First Line Of current Doc's Index Data
        char* URL= freadlinep(fp);
        if (URL==NULL){
            fprintf(stderr,"print_result: Can't Extract URL\n");
        }
        fclose(fp);

        //Print Current DocID Result
        printf("Score: %d DocID:%d :%s \n", docs[i]->score, docs[i]->docID, URL);

        //Clean Up
        free(URL);
        free(filename);
    }
    printf("----------------------------------------------------------------------\n");
}

//Create Scores Counters For Queried Words
counters_t* create_scores(index_t* index, char** words,int nwords){
    bag_t* andSequencesBag= bag_new();
	counters_t* andCounter = counters_new();//Result Of Current andSequence
    counters_iterate(hashtable_find(index, words[0]), andCounter, counter_copy);
    counters_t* result; //result: counters_t pointer pointing to the final result
    //Loop Over Every Word In Query
    for (int i=0; i<nwords; i++){
        //1. If "OR" then Add Current andSequence Into Bag for Union Later
        if ( strcmp(words[i], "or") == 0 ){
            // Put andCounter Into Bag; Merge andCounter with Result (Union) Later
            bag_insert(andSequencesBag, andCounter);
            // Reset andCounter (Free, set it Null)
            andCounter= counters_new();
            counters_iterate(index_find(index, words[i+1]), andCounter, counter_copy);
        } else {
            if ( strcmp(words[i],"and") != 0) {//If Is A Query Word (Not "and")
                //Find The Current Word In Index
                counters_t* curr_word_cts= index_find(index, words[i]);
                //Find Intersection of current Word And andSequence (Update andCounter)
                counters_t* two_counters[2]= {andCounter, curr_word_cts};

                //Update Current And Counter
                counters_iterate(andCounter, two_counters, intersect_helper);
            }
        }
    }

    //2. Insert last (andSequence) into Bag To Be United
    bag_insert(andSequencesBag, andCounter);

    //3. Unite Every andSequence in the Bag
    result=bag_extract(andSequencesBag);
    counters_t* currSequence;
    while (( currSequence=bag_extract(andSequencesBag) ) != NULL ){ 
        counters_iterate(currSequence, result, counters_union);
        //Clean Up
        counters_delete(currSequence);
    }
    //Clean Up
    bag_delete(andSequencesBag,NULL);
    //Return Final Result Counters
    return result;
 }

//Sort In Decreasing Order 
void sort_docs(void *arg, const int key, const int count){
    //Only Sort Valid Match docID (with non-zero count)
    if (count>0){
        //Initialize index and final docs_ranking to be sorted
        docs_ranking_t* docs_ranking = (docs_ranking_t *)arg;
        int index = docs_ranking->index;
        
        // Initialize Current Document
        doc_t* doc = malloc(sizeof(doc_t));
        doc->docID = key;
        doc->score = count;


    //No Need To Sort If Only 1 Result Found
    if(index == 0){
        docs_ranking->docs[0] = doc;
    }

    // Initialize prev and curr score keepers
    int prev=docs_ranking->docs[index-1]->score;
    int curr= doc->score;
    while (index > 0 &&  (prev < curr) ){
        //Make Current Doc into Prev Doc
        docs_ranking->docs[index] = docs_ranking->docs[index - 1];
        //Update (Decrement) Index
        index = index - 1;
    }
    //Update Docs Ranks
    docs_ranking->docs[index] = doc;
    //Update Current Index
    docs_ranking->index++;
    }
}

// Run The Query On Given Words
void run_query(char** words, int nwords, index_t* index, char* pageDirectory){
    // 1). find the match for the query 
        // 1.1) Create result counters
	counters_t* result = create_scores(index, words, nwords);//Create docId->Scores Index
    
    //Get Number Of Results
    int resultNumber=0;
    counters_iterate(result, &resultNumber,countResultItems);

    // 2) Create Sorted Result Array/Sort Final-Scores Index
	docs_ranking_t* docs_ranking = malloc(sizeof(docs_ranking_t));
    doc_t* docArray[resultNumber];
    docs_ranking->index=0;
    docs_ranking->docs= docArray ;
    counters_iterate(result, docs_ranking, sort_docs);
	
    // 3). print 
	print_results(docs_ranking, pageDirectory, resultNumber);
	
    //4. Clean Up
    free(docs_ranking);
    counters_delete(result);
}

// Process Query
void process_query(index_t* index, char* pageDirectory){
    char* line;
    while ( (line=freadlinep(stdin)) != NULL ){
        //1. Parse Query
        char** words=count_malloc(sizeof(char*) * 25); // Average words in a sentence is 15 to 20, so pick 25 just to be extra safe
        int nwords=extract_words(line, words); //Extract the current line to words + count number of words to nwords
        if (nwords!=0 && words!=NULL){
            print_query_words(nwords, words);
            //2. Validate Basic Structure
            if (valid_query(words, nwords)){
                run_query(words, nwords, index, pageDirectory);
            }
        }
    // 1.3 clean up memory space 
    free(words);
    free(line);
    }
}

int main(const int argc, char *argv[]){
    // 0). check arguments 
    if (argc != 3) {
        fprintf(stderr, "Usage: ./querier pageDirectory indexFilename\n");
        return 1;
    }
    char* pageDirectory= argv[1];
    if (!isCrawlerDirectory(pageDirectory)){
        fprintf(stderr, "Querier Main: Not A Crawler Directory\n");
    }
    // 1). load the index from the index file (index_load())
    char* indexFilename= argv[2];
    index_t* index= index_load(indexFilename);
    assertp(index, "Cant Load Index in Main\n");
    // 2). process query from keyboard/stdin using the index until EOF (ctrl+D)
    process_query(index, pageDirectory);
    // 3). clean up the index (index_delete)
    index_delete(index);
}

