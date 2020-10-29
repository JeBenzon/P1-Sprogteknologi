//This is where we start writing our input
//Members who have worked on this file:

#include <stdio.h>
#include <string.h>

#define LINE_LEN 500
#define NAME_LEN 40

int main(void){
char line[LINE_LEN], inname[NAME_LEN], outname[NAME_LEN];
FILE *inp;
char *status;
int i = 0;

inp = fopen("Data/da_ddt-ud-train", "r");

for (status = fgets(line, LINE_LEN, inp);
    status != 0;
    status = fgets(line, LINE_LEN, inp)) {
    if (line[strlen(line) - 1] == '\n')
    line[strlen(line) - 1] = '\0';
printf("%3d>> %s\n\n", ++i, line);
}
return (0);
}