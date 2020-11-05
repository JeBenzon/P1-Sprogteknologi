//This is where we start writing our input
//Members who have worked on this file: Jonathan, Frederik

#include <stdio.h>
#include <string.h>

#define LINE_LEN 500
#define WORDS_COUNT 10
#define CHAR_COUNT 50

void readfile(char ord[WORDS_COUNT][CHAR_COUNT], char filen[50]);
void hentfil(char filen[50]);
int main(void){
    
    char ord[WORDS_COUNT][CHAR_COUNT];
    char filen[50];

    hentfil(filen);
    
    readfile(ord, filen);



    for(int j = 0; j < WORDS_COUNT; j++){
        //puts printer ordet ud
        puts(ord[j]);
    }

    
    return (0);
}

void readfile(char ord[WORDS_COUNT][CHAR_COUNT], char filen[50]){

    FILE *inp = fopen(filen, "r");

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
            
            ord[i][f] = token[f];
        }
        ord[i][f] = '\0';
        
        //Læser ny linje ind i status
        status = fgets(line, LINE_LEN, inp);
        i++;
    } 
} 

void hentfil(char filen[50]){
    printf("skriv filnavns'stien f.eks. Data/da_ddt-ud-train\n");
    scanf("%s", filen);
}
