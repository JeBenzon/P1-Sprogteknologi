//This is where we start writing our input
//Members who have worked on this file: Jonathan, Frederik

#include <stdio.h>
#include <string.h>

#define LINE_LEN 500

int main(void){

char ord[10][50];
char line[LINE_LEN];
FILE *inp = fopen("Data/da_ddt-ud-train", "r");
int i = 0;
char *status = fgets(line, LINE_LEN, inp);

while(i < 10 && status != 0){

    if (line[strlen(line) - 1] == '\n'){
        line[strlen(line) - 1] = '\0';
    }
    //Læser 1 linje ind i Token
    char *token = strtok(line, "\t");
    //sætter Token til at være det næste ord i Token linjen.
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

for(int j = 0; j < 10; j++){
    
    puts(ord[j]);
    
}

return (0);
}