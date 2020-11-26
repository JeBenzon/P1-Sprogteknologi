#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "input.c"
#include "functions.c"
#include "output.c"


#define WORDS_COUNT 70000
#define WORDS_IN_ORDBOG 64894
#define ORDBOG_CLASS_COUNT 14
int main(void){

    char **input_array_words = (char **)malloc(WORDS_COUNT * sizeof(char *));
    char **input_array_class = (char **)malloc(WORDS_COUNT * sizeof(char *));
     
    // char **output_array_class_guesstimate = (char **)malloc(WORDS_COUNT * sizeof(char *));

    //truefalse array
    int *truefalse_array = (int*)calloc(WORDS_COUNT, sizeof(int));

    char **book_array_words = (char **)malloc(WORDS_IN_ORDBOG * sizeof(char *));
    char **book_array_class = (char **)malloc(WORDS_IN_ORDBOG * sizeof(char *));

    getWordBookClass(book_array_words, book_array_class);
    //getArrayFromFile(input_array_words, input_array_class);
    
    //print_output(input_array_words, input_array_class, output_array_class_guesstimate, truefalse_array);
    


    for(int i = 0; i < 1; i++){
        int * ord_class_list = get_our_estimate(book_array_words, book_array_class, "under");
        //output_array_class_guesstimate[i] = get_our_estimate( *book_array_words, *book_array_class, input_array_words[i]);
        switch(c) {
        case 0:
        if(ord_class_list[i] = 1) {
            pronomener(char *ord);
            break;
        }
        case 1:
        if(ord_class_list[i] = 1) {
            artikler(char *ord);
            break;
        }
        case 2:
        if(ord_class_list[i] = 1) {
            substantiver(char *ord);
            break;
        }
        case 3:
        if(ord_class_list[i] = 1) {
            verber(char *ord);
            break;
        }
        case 4:
        if(ord_class_list[i] = 1) {
            adjektiver(char *ord);
            break;
        }
        case 5:
        if(ord_class_list[i] = 1) {
            adverbier(char *ord);
            break;
        }
        case 6:
        if(ord_class_list[i] = 1) {
            konjunktioner(char *ord);
            break;
        }
        case 7:
        if(ord_class_list[i] = 1) {
            substantiver(char *ord); // Dette er specifikt proprier (mangler funktion)
            break;
        }
        case 8:
        if(ord_class_list[i] = 1) {
            praepositioner(char *ord);
            break;
        }
        case 9:
        if(ord_class_list[i] = 1) {
            // praefiks(char *ord); // Dette skal 
            break;
        }
        case 10:
        if(ord_class_list[i] = 1) {
            talord(char *ord);
            break;
        }
        case 11:
        if(ord_class_list[i] = 1) {
            lydord(char *ord);
            break;
        }
        case 12:
        if(ord_class_list[i] = 1) {
            udraabsord(char *ord);
            break;
        }
        }
    }
    
    
    //printf("%s\n", ord);

    return 0;
}