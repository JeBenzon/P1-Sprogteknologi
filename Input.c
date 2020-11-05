//This is where we start writing our input
//Members who have worked on this file: Jonathan, Frederik

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN 500
#define WORDS_COUNT 26
#define CHAR_COUNT 50

void arraytest();
char * getfil();
char ** getArrayFromFile(char filen[50]);
void printArray(char ** arrayWords);

int main(void){
    char * fil = getfil();
    char ** ord_array = getArrayFromFile(fil);
    /*
    do calculations on array;
    */
    printArray(ord_array);

    return (0);
}

char ** getArrayFromFile(char fil[50]){
    //Laver Array med Malloc
    char **ord_array = (char **)malloc(WORDS_COUNT * sizeof(char *)); 
    for (int i = 0; i < WORDS_COUNT; i++){
        ord_array[i] = (char *)malloc(CHAR_COUNT * sizeof(char)); 
    }

    FILE *inp = fopen(fil, "r");
    char line[LINE_LEN];
    char *status = fgets(line, LINE_LEN, inp);

    int i = 0;
    while(i < WORDS_COUNT && status != 0){

        if (line[strlen(line) - 1] == '\n'){
            line[strlen(line) - 1] = '\0';
        }

        //Læser alle ord fra linjen ind i Token, så består nu af flere ord.
        char *token = strtok(line, "\t");
        //skipper et ord i token.
        token = strtok(NULL, "\t");
        
        //Tjekker om Token er tom
        if(token == NULL){
            i++;
            status = fgets(line, LINE_LEN, inp);
            continue;
        }

        int f;
        //læser ordet fra Token og sætter det ind i Ord array
        for(f = 0; f < (int)strlen(token); f++){
            ord_array[i][f] = token[f];
        }
        
        ord_array[i][f] = '\0';
        
        //Læser ny linje ind i status
        status = fgets(line, LINE_LEN, inp);
        i++;
    }

    return ord_array;
} 

char * getfil(){
    char * fil = (char *)malloc(50 * sizeof(char *));
    printf("skriv filnavns'stien f.eks. Data/da_ddt-ud-train\n");
    scanf("%s", fil);

    return fil;
}

//Denne funktion er bare til lige at forstå basic array Malloc **FJERNES SNART**
void arraytest(){
    char **arr = (char **)malloc(WORDS_COUNT * sizeof(char *)); 
    for (int i = 0; i < WORDS_COUNT; i++){
        arr[i] = (char *)malloc(CHAR_COUNT * sizeof(char)); 
    }

    // Note that arr[i][j] is same as *(*(arr+i)+j) 
    
    for (int i = 0; i <  WORDS_COUNT; i++){
        for (int j = 0; j < CHAR_COUNT; j++) 
        arr[i][j] = 'c';
    } 

    for (int i = 0; i <  WORDS_COUNT; i++){
        for (int j = 0; j < CHAR_COUNT; j++) 
        printf("%c ", arr[i][j]); 
    }
}

void printArray(char ** arrayWords){
    for(int j = 0; j < WORDS_COUNT; j++){
        //puts printer ordet ud
        puts(arrayWords[j]);
    }
}