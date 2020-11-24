#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "input.c"
#include "functions.c"

#define LINE_LEN 500
#define WORDS_IN_ORDBOG 64894
#define CHAR_COUNT 100

int main(void){

    char **input_array_words = (char **)malloc(WORDS_COUNT * sizeof(char *));
    char **input_array_class = (char **)malloc(WORDS_COUNT * sizeof(char *));
    char **book_array_words = (char **)malloc(WORDS_IN_ORDBOG * sizeof(char *));
    char **book_array_class = (char **)malloc(WORDS_IN_ORDBOG * sizeof(char *));
    char **output_array_class_guesstimate = (char **)malloc(WORDS_COUNT * sizeof(char *));


    getWordBookClass(book_array_words, book_array_class);
    
    //kan finde 1 ordklasse, men ikke flere. 
    char * ord = BinSearch(book_array_words, book_array_class, "ringe");
    printf("%s\n", ord);


}