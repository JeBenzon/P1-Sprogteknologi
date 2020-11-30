#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "input.c"
#include "functions.c"



#define WORDS_IN_DATA 80378
#define WORDS_IN_DICTIONARY 64894


int main(void){
    
    char **data_words = (char **)malloc(WORDS_IN_DATA * sizeof(char *));
    char **data_wordclass = (char **)malloc(WORDS_IN_DATA * sizeof(char *));
     
    char **estimate_wordclass = (char **)malloc(WORDS_IN_DATA * sizeof(char *));

    //truefalse array
    int *truefalse_array = (int*)calloc(WORDS_IN_DATA, sizeof(int));

    char **dictionary_words = (char **)malloc(WORDS_IN_DICTIONARY * sizeof(char *));
    char **dictionary_wordclass = (char **)malloc(WORDS_IN_DICTIONARY * sizeof(char *));

    get_data(data_words, data_wordclass, WORDS_IN_DATA);
    get_dictionary(dictionary_words, dictionary_wordclass, WORDS_IN_DICTIONARY);
    
    int winrate = 0;
    int i;

    estimate_wordclass[0] = get_estimate(dictionary_words, dictionary_wordclass, data_words[0]);

    printf("%d: %s\t%s\t%s\t%d\n",i+1, data_words[0], data_wordclass[0], estimate_wordclass[0], truefalse_array[0]);

    //estimate_wordclass[0] = get_estimate(dictionary_words, dictionary_wordclass, data_words[4405]);
    //printf("%s %s\n",estimate_wordclass[0], data_words[4405]);
    /*
    for(i = 25000; i < 80000; i++) {

        estimate_wordclass[i] = get_estimate(dictionary_words, dictionary_wordclass, data_words[i]);
        

        if(data_words[i] != NULL || data_wordclass[i] != NULL || estimate_wordclass[i] != NULL){
            
            //Understående strcmp har endnu ingen funktion, da de er formateret hver for sig.
            //+ så bliver int(output_truefalse) ikke 0 eller 1, da stringcomp. ikke giver 1 eller 0.
            if(strcmp(data_wordclass[i], estimate_wordclass[i]) == 0) {
            truefalse_array[i] = 1;
            winrate++;
            }

            printf("%d: %s\t%s\t%s\t%d\n",i+1, data_words[i], data_wordclass[i], estimate_wordclass[i], truefalse_array[i]);
            

        }else{
            //printf("%d: Fejl\n", i);
        }
    }
    
    printf("accuracy: %d out of %d\n", winrate, i);
    
    free(data_words);
    free(data_wordclass);
    free(estimate_wordclass);
    free(truefalse_array);
    free(dictionary_words);
    free(dictionary_wordclass);
    */
    return 0;
}