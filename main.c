#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "input.c"
#include "functions.c"
#include "output.c"


#define WORDS_COUNT 80378
#define WORDS_IN_ORDBOG 64894
#define ORDBOG_CLASS_COUNT 14
int main(void){
    /*
    char **input_array_words = (char **)malloc(WORDS_COUNT * sizeof(char *));
    char **input_array_class = (char **)malloc(WORDS_COUNT * sizeof(char *));
     
    char **guesstimate = (char **)malloc(WORDS_COUNT * sizeof(char *));

    //truefalse array
    //int *truefalse_array = (int*)calloc(WORDS_COUNT, sizeof(int));

    char **book_array_words = (char **)malloc(WORDS_IN_ORDBOG * sizeof(char *));
    char **book_array_class = (char **)malloc(WORDS_IN_ORDBOG * sizeof(char *));

    getWordBookClass(book_array_words, book_array_class);
    
    getArrayFromFile(input_array_words, input_array_class);
    
    */
    
    char **bintest = (char **)malloc(10 * sizeof(char *));
    bintest[0] = "abe";
    bintest[1] = "benjamin";
    bintest[3] = "ost";
    bintest[2] = "paa";
    bintest[4] = "sort";

    bin2("Paa", bintest);
    
    //printf("%s",BinSearch(book_array_words, book_array_class, input_array_words[0]));
    //print_output(input_array_words, input_array_class, output_array_class_guesstimate, truefalse_array);
    
    /*
    for(int i = 0; i < 5; i++){
        int * ord_class_list = get_our_estimate(book_array_words, book_array_class, input_array_words[i]);
        //output_array_class_guesstimate[i] = get_our_estimate( *book_array_words, *book_array_class, input_array_words[i]);
        
        for(int c = 0; c < ORDBOG_CLASS_COUNT; c++) {
            if(ord_class_list[c] == 1) {
                guesstimate[c] = class_switch(c, input_array_words[c]);
            }
            //printf("Guestimate er: %s", guesstimate[c]);
        }
    }
    */
    
    return 0;
}