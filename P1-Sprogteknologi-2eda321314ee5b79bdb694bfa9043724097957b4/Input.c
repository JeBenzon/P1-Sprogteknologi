//This is where we start writing our input
//Members who have worked on this file: Jonathan, Frederik

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN 500
#define WORDS_COUNT 500
#define CHAR_COUNT 50

void arraytest();
char * menu_filvalg();
void getArrayFromFile();
void printArray(char ** array_words, char ** array_class);

int main(void){

    getArrayFromFile();

    return 0;
}

void getArrayFromFile(){
    //laver 2 arrays
    char **array_words = (char **)malloc(WORDS_COUNT * sizeof(char *)); 
    char **array_class = (char **)malloc(WORDS_COUNT * sizeof(char *)); 

    char * fil = menu_filvalg();

    //Laver Array med Malloc
    for (int i = 0; i < WORDS_COUNT; i++){
        array_words[i] = (char *)malloc(CHAR_COUNT * sizeof(char)); 
        array_class[i] = (char *)malloc(CHAR_COUNT * sizeof(char)); 
    }

    //Åbner fil
    FILE *inp = fopen(fil, "r");
    char line[LINE_LEN];
    char *status = fgets(line, LINE_LEN, inp);
    
    int i = 0;
    while(i < WORDS_COUNT && status != 0){

        //Hvis sidste linje i line er \n så byt det ud med \0
        if (line[strlen(line) - 1] == '\n'){
            line[strlen(line) - 1] = '\0';
        }

        //Læser alle ord fra linjen ind i Token, som nu består af flere ord.
        char *token = strtok(line, "\t");

        //Tjekker om Token er tom eller en kommentar
        if(token == NULL || token[0] == '#'){
            status = fgets(line, LINE_LEN, inp);
            continue;
        }
        
        //skipper et ord i token.
        token = strtok(NULL, "\t");
 
        //læser ordet fra Token og sætter det ind i Ord array
        int f;
        for(f = 0; f < (int)strlen(token); f++){
            array_words[i][f] = token[f];
        }
        array_words[i][f] = '\0';

        //skipper et ord i token.
        token = strtok(NULL, "\t");
        token = strtok(NULL, "\t");

        for(f = 0; f < (int)strlen(token); f++){
            array_class[i][f] = token[f];
        }
        array_class[i][f] = '\0';
        
        //Læser ny linje ind i status
        status = fgets(line, LINE_LEN, inp);
        i++;
    }

    printArray(array_words, array_class);
} 

void printArray(char ** array_words, char ** array_class){
    for(int i = 0; i < WORDS_COUNT; i++){
        //puts printer ordet ud
        printf("%s \t -> %s \n", array_words[i], array_class[i]);
    }
}

char * menu_filvalg(){ //Skal implementeres, så den retunerer "filnavn" i korrekt sammenhæng.
    char * fil = (char *)malloc(50 * sizeof(char *));
    int menu;
    //Læsning til brugeren, spørg om valg til switchen 1, 2 eller 3.
    printf("Indtast filvalg til indlæsning fra menuen,\nmed nummeret fra listen, forsæt med Enter:\n");
    printf("1: Train\n2: Test\n3: Skriv selv adresse på fil til indlsæning.\n");
    scanf("%d",&menu);

    switch (menu){
    case 1:
        return "Data/da_ddt-ud-train";
    case 2:
        return "Data/da_ddt-ud-test";
    //Case 3 sprøger til at brugeren selv skal vælge
    case 3:      
        printf("skriv filnavns'stien f.eks. Data/da_ddt-ud-train\n");
        scanf("%s", fil);
    }

    return "0";
}