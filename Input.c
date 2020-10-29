//This is where we start writing our input
//Members who have worked on this file:

#include <stdio.h>
#include <string.h>

#define LINE_LEN 500

int main(void){

char ord[10][50];
ord[0][0] = 'c';

char line[LINE_LEN];
FILE *inp;
inp = fopen("Data/da_ddt-ud-train", "r");

int i = 0;

char *status = fgets(line, LINE_LEN, inp);
//while(status != 0){
while(i < 10 && status != 0){
    printf("%d\n",i);
    if (line[strlen(line) - 1] == '\n'){
        line[strlen(line) - 1] = '\0';
    }
    char *token = strtok(line, "\t");
    token = strtok(NULL, "\t");
    printf("Token is: %s\n", token);
    
    if(token == NULL){
        i++;
        status = fgets(line, LINE_LEN, inp);
        continue;
    }
    int f;
    for(f = 0; f < (int)strlen(token); f++){
        printf("%d %d\n", i, f);
        ord[i][f] = token[f];
        
    }
    printf("%d",f);
    ord[i][f] = '\0';
    
    
    //printf("%d>> %s\n\n", ++i, line);
    
    status = fgets(line, LINE_LEN, inp);
    i++;
}

for(int j = 0; j < 10; j++){
    printf("%d", j);
    puts(ord[j]);
    printf("\n");
    
}

return (0);
}