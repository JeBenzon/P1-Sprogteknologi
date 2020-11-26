#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "input.c"
#include "functions.c"
#include "output.c"


#define WORDS_COUNT 80378
#define WORDS_IN_ORDBOG 64894
int main(void){

    char **input_array_words = (char **)malloc(WORDS_COUNT * sizeof(char *));
    char **input_array_class = (char **)malloc(WORDS_COUNT * sizeof(char *));    
    char **output_array_class_guesstimate = (char **)malloc(WORDS_COUNT * sizeof(char *));

    //truefalse array
    int *truefalse_array = (int*)calloc(WORDS_COUNT, sizeof(int));

    char **book_array_words = (char **)malloc(WORDS_IN_ORDBOG * sizeof(char *));
    char **book_array_class = (char **)malloc(WORDS_IN_ORDBOG * sizeof(char *));

    getWordBookClass(book_array_words, book_array_class);
    
    getArrayFromFile(input_array_words, input_array_class);
    
    //print_output(input_array_words, input_array_class, output_array_class_guesstimate, truefalse_array);
    
    
    for(int i = 0; i < 1; i++){
        //output_array_class_guesstimate[i] = get_our_estimate(book_array_words, book_array_class, "under");
        output_array_class_guesstimate[i] = get_our_estimate( *book_array_words, *book_array_class, input_array_words[i]);
        printf("guess: %s", output_array_class_guesstimate[i]);
    }
    
    //printf("%s\n", ord);

    return 0;
}