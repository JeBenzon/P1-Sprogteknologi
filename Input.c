//This is where we start writing our input
//Members who have worked on this file:

#include <stdio.h>
#include <string.h>

#define LINE_LEN 500
#define NAME_LEN 40

int main(void){
char line[LINE_LEN], inname[NAME_LEN];
FILE *inp;
inp = fopen("Data/da_ddt-ud-train", "r");

int i = 0;

char *status = fgets(line, LINE_LEN, inp);
while(status != 0){
    if (line[strlen(line) - 1] == '\n')
    line[strlen(line) - 1] = '\0';
    printf("%d>> %s\n\n", ++i, line);

    status = fgets(line, LINE_LEN, inp);
}

return (0);
}