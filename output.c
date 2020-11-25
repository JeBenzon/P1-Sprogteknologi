//This is where we start writing our output
//Members who have worked on this file:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORDS_COUNT 70000
#define WORDS_IN_ORDBOG 64894

//Funktionen læser ind: Ord fra filen, Ordklassen fra filen, vores gæt, og så en true/false comparison.
void print_output(char **input_ord, char **input_class, char **input_guess, int *output_truefalse) {
    input_ord[0] = "hus";
    input_class[0] = "NOUN";
    input_guess[0] = "sb";

    input_ord[1] = "bil";
    input_class[1] = "NOUN";
    input_guess[1] = "sb";

    input_ord[2] = "realtest";
    input_class[2] = "test";
    input_guess[2] = "test";

    int c;
    int winrate = 0;
    for(c = 0; c < WORDS_COUNT; c++) {

        if(input_ord[c] == NULL || input_class[c] == NULL || input_guess[c] == NULL){
            continue;
        }

        //Understående strcmp har endnu ingen funktion, da de er formateret hver for sig.
        //+ så bliver int(output_truefalse) ikke 0 eller 1, da stringcomp. ikke giver 1 eller 0.
        if(strcmp(input_class[c], input_guess[c]) == 0) {
           output_truefalse[c] = 1;
           winrate++;
        }

        printf("%s\t%s\t%s\t%d\n", input_ord[c], input_class[c], input_guess[c], output_truefalse[c]);
        
        /*
        if(input_ord[c][0] == '.') {
            printf("\n");
        }*/
    }
    printf("accuracy: %d out of %d\n", winrate, c);
    
}