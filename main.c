#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "input.c"
#include "functions.c"

#define WORDS_COUNT 80400
#define WORDS_IN_ORDBOG 64894
int main(void){

    char **input_array_words = (char **)malloc(WORDS_COUNT * sizeof(char *));
    char **input_array_class = (char **)malloc(WORDS_COUNT * sizeof(char *));
    
    char **book_array_words = (char **)malloc(WORDS_IN_ORDBOG * sizeof(char *));
    char **book_array_class = (char **)malloc(WORDS_IN_ORDBOG * sizeof(char *));
    
    char **output_array_class_guesstimate = (char **)malloc(WORDS_COUNT * sizeof(char *));

    getArrayFromFile(input_array_words, input_array_class);
    //getWordBookClass(book_array_words, book_array_class);
    
    //kan finde 1 ordklasse, men ikke flere. 
    char * ord = BinSearch(book_array_words, book_array_class, "aegte");
    printf("%s\n", ord);

    return 0;
}