//This is where we start writing our input
//Members who have worked on this file: Jonathan, Frederik

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN 500
#define WORDS_COUNT 50
#define CHAR_COUNT 50

void arraytest();
char * getfil();
void getArrayFromFile(char fil[50],char ** ord_array, char ** class_array);
void printArray(char ** arrayWords);

int main(void){
    char **ord_array = (char **)malloc(WORDS_COUNT * sizeof(char *)); 
    char **class_array = (char **)malloc(WORDS_COUNT * sizeof(char *)); 

    char * fil = getfil();
    getArrayFromFile(fil, ord_array, class_array);
    /*
    do calculations on array;
    */
    printArray(ord_array);

    return (0);
}

void getArrayFromFile(char fil[50], char ** ord_array, char ** class_array){
    //Laver Array med Malloc
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

        //Læser alle ord fra linjen ind i Token, som nu består af flere ord.
        char *token = strtok(line, "\t");

        
        //Tjekker om Token er tom
        if(token == NULL){
            i++;
            status = fgets(line, LINE_LEN, inp);
            continue;
        }

        if(token[0] == '#' || token[0] == '\0'){
            status = fgets(line, LINE_LEN, inp);
            continue;
        }

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
/*
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
        break;
    //Eventuele metoder kan tilføjes herunder
    }
    
}

*/