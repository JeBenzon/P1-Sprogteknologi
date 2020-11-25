#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "input.c"
#include "functions.c"

#define WORDS_COUNT1 100000
#define WORDS_IN_ORDBOG1 64896

int main(void){

    char **input_array_words = (char **)malloc(WORDS_COUNT1 * sizeof(char *));
    char **input_array_class = (char **)malloc(WORDS_COUNT1 * sizeof(char *));
    char **book_array_words = (char **)malloc(WORDS_IN_ORDBOG1 * sizeof(char *));
    char **book_array_class = (char **)malloc(WORDS_IN_ORDBOG1 * sizeof(char *));
    //char **output_array_class_guesstimate = (char **)malloc(WORDS_COUNT * sizeof(char *));

    //getArrayFromFile(input_array_words, input_array_class);
    getWordBookClass(book_array_words, book_array_class);
    
    //kan finde 1 ordklasse, men ikke flere. 
    char * ord = BinSearch(book_array_words, book_array_class, "ringe");
    printf("%s\n", ord);

    return 0;
}