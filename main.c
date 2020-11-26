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

    char **input_array_words = (char **)malloc(WORDS_COUNT * sizeof(char *));
    char **input_array_class = (char **)malloc(WORDS_COUNT * sizeof(char *));
     
    char **guesstimate = (char **)malloc(WORDS_COUNT * sizeof(char *));

    //truefalse array
    int *truefalse_array = (int*)calloc(WORDS_COUNT, sizeof(int));

    char **book_array_words = (char **)malloc(WORDS_IN_ORDBOG * sizeof(char *));
    char **book_array_class = (char **)malloc(WORDS_IN_ORDBOG * sizeof(char *));

    getWordBookClass(book_array_words, book_array_class);
    
    getArrayFromFile(input_array_words, input_array_class);
    
    printf("%s",BinSearch(book_array_words, book_array_class, "under"));
    //print_output(input_array_words, input_array_class, output_array_class_guesstimate, truefalse_array);
    /*
    
    for(int i = 0; i < 1; i++){
        int c;
        int * ord_class_list = get_our_estimate(book_array_words, book_array_class, "doed");
        //output_array_class_guesstimate[i] = get_our_estimate( *book_array_words, *book_array_class, input_array_words[i]);
        
        for(int c = 0; c < ORDBOG_CLASS_COUNT; c++) {
            if(ord_class_list[c] == 1) {
                guesstimate[c] = class_switch(c, input_array_words[c]);
            }
            printf("Guestimate er: %s", guesstimate[c]);
        }
    */
        
   /* for(int c = 0; c < ORDBOG_CLASS_COUNT; c++) {
        //if(ord_class_list[c] == )

        switch(ord_class_list[c]) {

        case 0:
        if(ord_class_list[c] == 1) {
            pronomener(input_array_words[i]);
            break;
        }
        case 1:
        if(ord_class_list[c] == 1) {
            artikler(input_array_words[i]);
            break;
        }
        case 2:
        if(ord_class_list[c] == 1) {
            substantiver(input_array_words[i]);
            break;
        }
        case 3:
        if(ord_class_list[i] == 1) {
            verber(input_array_words[i]);
            break;
        }
        case 4:
        if(ord_class_list[i] == 1) {
            adjektiver(input_array_words[i]);
            break;
        }
        case 5:
        if(ord_class_list[i] == 1) {
            adverbier(input_array_words[i]);
            break;
        }
        case 6:
        if(ord_class_list[i] == 1) {
            konjunktioner(input_array_words[i]);
            break;
        }
        case 7:
        if(ord_class_list[i] == 1) {
            substantiver(input_array_words[i]); // Dette er specifikt proprier (mangler funktion)
            break;
        }
        case 8:
        if(ord_class_list[i] == 1) {
            praepositioner(input_array_words[i]);
            break;
        }
        case 9:
        if(ord_class_list[i] == 1) {
            // praefiks(input_array_words[i]); // Dette skal 
            break;
        }
        case 10:
        if(ord_class_list[i] == 1) {
            talord(input_array_words[i]);
            break;
        }
        case 11:
        if(ord_class_list[i] == 1) {
            lydord(input_array_words[i]);
            break;
        }
        case 12:
        if(ord_class_list[i] == 1) {
            udraabsord(input_array_words[i]);
            break;
        } 
    }*/
        
        //output_array_class_guesstimate[i] = get_our_estimate(book_array_words, book_array_class, "under");
        //output_array_class_guesstimate[i] = get_our_estimate( *book_array_words, *book_array_class, input_array_words[i]);
        //printf("guess: %s", output_array_class_guesstimate[i]);
    
    
    //printf("%s\n", ord);

    return 0;
}