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
char ** getArrayFromFile(char filen[50])

int main(void){
    arraytest();
    
    char * filnavn = getfil();
    char ** word_array = getArrayFromFile(filnavn);
    /*
    do calculations on array;
    */
    printArray(word_array);

    return (0);
}

char ** getArrayFromFile(char filen[50]){

    char **arr = (char **)malloc(WORDS_COUNT * sizeof(char *)); 
    for (int i = 0; i < WORDS_COUNT; i++){
        arr[i] = (char *)malloc(CHAR_COUNT * sizeof(char)); 
    }

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

char * getfil(){
    char filnavn[50];
    printf("skriv filnavns'stien f.eks. Data/da_ddt-ud-train\n");
    scanf("%s", &filnavn);

    return filnavn;
}

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

void menu_filvalg(){ //Skal implementeres, så den retunerer "filnavn" i korrekt sammenhæng.
    char menu, filnavn[50]; //Bemærk filnavn, måske faktisk hedder "fil" eller "filen".
    //Læsning til brugeren, spørg om valg til switchen 1,2 eller 3.
    printf("Indtast filvalg til indlæsning fra menuen,\n med nummeret fra listen, forsæt med Enter:\n");
    printf("1:Train\n2:Test\n3:Skriv selv adresse på fil til indlsæning.\n");
    scanf("%c",&menu);
    //Case 1&2 bruger "char filnavn", ved ikke om det virker ¯\_(ツ)_/¯
    switch (menu){
    case '1':
        char filnavn[50] = 'Data/da_ddt-ud-train';
        break;
    
    case '2':
        char filnavn[50] = 'Data/da_ddt-ud-test';
        break;
    //Case 3 sprøger til at brugeren selv skal vælge
    case '3':
        printf("Skriv filnavns'stien f.eks. Data/da_ddt-ud-train\n");
        scanf("%s", filnavn);
    //Eventuele metoder kan tilføjes herunder
    }

}