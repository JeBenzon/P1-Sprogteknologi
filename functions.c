//This is where we start writing out functions
//Members who have worked on this file: 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORDS_COUNT 300
#define CHAR_COUNT 50

#define WORDS_IN_ORDBOG 64896

int substantiver(char *ord);
int is_capitol_letter(char first_letter);
int is_correct_ending(char *ord);
int str_ending_compare(char *ord, char *ending);

int artikler(char *ord);
int is_article(char *ord);

void testord(char ** ord_array, char ** class_array);
char * BinSearch(char ** ord_array, char ** word_class, char * ord);

/*
//Test main for functions
int main(void){
    char **ord_array = (char **)malloc(WORDS_COUNT * sizeof(char *));
    char **class_array = (char **)malloc(WORDS_COUNT * sizeof(char *));
    char **vores_klaase_array = (char **)malloc(WORDS_COUNT * sizeof(char *));
    
    testord(ord_array, class_array);

    //artikler(ord_array[1]);

    //substantiver(ord_array[1]);

    //printf(" %d", is_capitol_letter(ord_array[24][3]));

    char ord[9] = "formanden";

    BinSearch(ord_array, ord);

    printf("test\n");

}*/

int substantiver(char *ord) {
    printf(" %s\n\n", ord);

    if(is_capitol_letter(ord[0]) == 2) {
        printf("capitol er opfyldt\n\n");
    } else {
        printf("capitol er ikke opfyldt\n\n");
    }

    if(is_correct_ending(ord) == 1) {
        printf("ending er opfyldt\n\n");
    } else {
        printf("ending er ikke opfyldt\n\n");
    }

    return 0;
}

int is_capitol_letter(char first_letter) {

    if(first_letter >= 'A' && first_letter <= 'Z') {
        return 2;
    } else if(first_letter >= 'a' && first_letter <= 'z') {
        return 1;
    } else {
        return 0;
    }
}

int is_correct_ending(char *ord) {
    char er[] = "er";
    char e[] = "e";
    char ene[] = "ene";
    char en[] = "en";
    char et[] = "et";
    char r[] = "r";
    char ne[] = "ne";
    char s[] = "s";
    // char test[] = "de";

    /* TEST PROG
    if((str_ending_compare(ord, test) == 0)) {
        return 1;
    } else{
        return 0;
    } */
    
    if((str_ending_compare(ord, ene) == 0)) {            // strstr(ord, segment) tjekker om første-string(ord) indholder anden-string(segment)
        return 1;
    } else if((str_ending_compare(ord, ne) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, en) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, er) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, et) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, s) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, r) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, e) == 0)) {
        return 1;
    } else {
        return 0;
    }

    /*
    if(strstr(ord, ene)) {            // strstr(ord, segment) tjekker om første-string(ord) indholder anden-string(segment)
        return 1;
    } else if(strstr(ord, ne)) {
        return 1;
    } else if(strstr(ord, en)) {
        return 1;
    } else if(strstr(ord, er)) {
        return 1;
    } else if(strstr(ord, et)) {
        return 1;
    } else if(strstr(ord, s)) {
        return 1;
    } else if(strstr(ord, r)) {
        return 1;
    } else if(strstr(ord, e)) {
        return 1;
    } else {
        return 0;
    }
    */
}

int str_ending_compare(char *ord, char *ending) {
    int c;
    int result;
    int ord_len = (strlen(ord) + 1);
    int ending_len = (strlen(ending) + 1);
    char ord_ending[ending_len];

    // printf(" %s, %s\n", ord, ending);

    for(c = 1; c <= ending_len; c++) {
        ord_ending[ending_len - c] = ord[ord_len - c];
    }

    // printf(" %s, %s\n", ending, ord_ending);

    return strcmp(ending, ord_ending);
}

int artikler(char *ord) {
    
    if(is_article(ord) == 1) {
        printf("\narticle er opfyldt\n\n");
    } else {
        printf("\narticle er ikke opfyldt\n\n");
    }
    
    return 0;
}

int is_article(char *ord) {
    char den[] = "den";
    char det[] = "det";
    char en[] = "en";
    char et[] = "et";
    char de[] = "de";
    
    if((strcmp(ord, den) == 0)) {                                      // strcmp(ene_string, anden_string) tjekker om første-string tilsvarer anden-string 
        return 1;
    } else if((strcmp(ord, det) == 0)) {
        return 1;
    } else if((strcmp(ord, en) == 0)) {
        return 1;
    } else if((strcmp(ord, et) == 0)) {
        return 1;
    } else if((strcmp(ord, de) == 0)) {
        return 1;
    } else {
        return 0;
    }
}

// funktion for endelse(artikel) 
// funktion for artikel - tjek forrige ord
// funktion for første ord i sætning - tjek forrige ord for punktum
// funktion for ordklaseesandsynlighed - tjek returværdier


/*
//finder ud af om et ord er et substantiv, ud fra ordbogen.
int sb_ordbog() {

}

//returnere ordklassen, givet et ord, ud fra søgning i ordbog.
char * get_ordklasse(char * ord){
    
}
*/
char * BinSearch(char ** ord_array, char ** word_class, char * ord){
    char * class[100];
    printf("\n");
    int lower;
    int max;
    int midt;
    lower = 1;
    max = WORDS_IN_ORDBOG;
    while (lower < max){
        midt = (lower + max)/2;
        
        printf("Min:\t%d\nMidt:\t%d\nMax:\t%d\n", lower, midt, max);
        printf("strcmp: %d\n", strcmp(ord, ord_array[midt]));


        if ((strcmp(ord, ord_array[midt]) >= 0)){
            printf("ordet: %s, ligger højere end ordet: %s\n", ord, ord_array[midt]);
            lower = midt + 1;
        } else{
            printf("ordet: %s, ligger lavere end ordet: %s\n", ord, ord_array[midt]);
            max = midt;
        }
        printf("\n");

  }
    printf("Min:\t%d\nMidt:\t%d\nMax:\t%d\n ord_array:\t %s\n", lower, midt, max, ord_array[midt]);
    
    if (strcmp(ord, ord_array[lower - 1]) == 0){
        printf("BinSeach: %s er på position %d\n",ord,lower);
        return word_class[lower - 1];

    }
    //Noget der skal tjekke de omkringliggende ord er samme ord, og i så fald;
    //Skal ordklassen sendes med: 
    //Ordet "Under" har fx 3(4) forskellige ordklasser/betdyninger: sb, sb, adv, præp.

    
}



void testord(char ** ord_array, char ** class_array){

    for (int i = 0; i < WORDS_COUNT; i++){
        ord_array[i] = (char *)malloc(CHAR_COUNT * sizeof(char)); 
        class_array[i] = (char *)malloc(CHAR_COUNT * sizeof(char));
    }
    ord_array[0][0] = 'P';
    ord_array[0][1] = 'a';
    ord_array[0][2] = 'a';
    ord_array[0][3] = '\0';
    
    class_array[0][0] = 'A';
    class_array[0][1] = 'D';
    class_array[0][2] = 'P';
    class_array[0][3] = '\0';

    ord_array[1][0] = 'F';
    ord_array[1][1] = 'r';
    ord_array[1][2] = 'e';
    ord_array[1][3] = 'd';
    ord_array[1][4] = 'a';
    ord_array[1][5] = 'g';
    ord_array[1][6] = '\0';

    class_array[1][0] = 'N';
    class_array[1][1] = 'O';
    class_array[1][2] = 'U';
    class_array[1][3] = 'N';
    class_array[1][4] = '\0';

    ord_array[2][0] = 'h';
    ord_array[2][1] = 'a';
    ord_array[2][2] = 'r';
    ord_array[2][3] = '\0';

    class_array[2][0] = 'A';
    class_array[2][1] = 'U';
    class_array[2][2] = 'X';
    class_array[2][3] = '\0';

    ord_array[3][0] = 'S';
    ord_array[3][1] = 'I';
    ord_array[3][2] = 'D';
    ord_array[3][3] = '\0';

    class_array[3][0] = 'P';
    class_array[3][1] = 'R';
    class_array[3][2] = 'O';
    class_array[3][3] = 'P';
    class_array[3][4] = 'N';
    class_array[3][5] = '\0';

    ord_array[4][0] = 'i';
    ord_array[4][1] = 'n';
    ord_array[4][2] = 'v';
    ord_array[4][3] = 'i';
    ord_array[4][4] = 't';
    ord_array[4][5] = 'e';
    ord_array[4][6] = 'r';
    ord_array[4][7] = 'e';
    ord_array[4][8] = 't';
    ord_array[4][9] = '\0';

    class_array[4][0] = 'V';
    class_array[4][1] = 'E';
    class_array[4][3] = 'R';
    class_array[4][4] = 'B';
    class_array[4][5] = '\0';

    ord_array[5][0] = 't';
    ord_array[5][1] = 'i';
    ord_array[5][2] = 'l';
    ord_array[5][3] = '\0';

    class_array[5][0] = 'A';
    class_array[5][1] = 'D';
    class_array[5][2] = 'P';
    class_array[5][3] = '\0';

    ord_array[6][0] = 'r';
    ord_array[6][1] = 'e';
    ord_array[6][2] = 'c';
    ord_array[6][3] = 'e';
    ord_array[6][4] = 'p';
    ord_array[6][5] = 't';
    ord_array[6][6] = 'i';
    ord_array[6][7] = 'o';
    ord_array[6][8] = 'n';
    ord_array[6][9] = '\0';

    class_array[6][0] = 'N';
    class_array[6][1] = 'O';
    class_array[6][3] = 'U';
    class_array[6][4] = 'N';
    class_array[6][5] = '\0';

    ord_array[7][0] = 'i';
    ord_array[7][1] = '\0';

    class_array[7][0] = 'A';
    class_array[7][1] = 'D';
    class_array[7][2] = 'P';
    class_array[7][3] = '\0';

    ord_array[8][0] = 's';
    ord_array[8][1] = 'i';
    ord_array[8][2] = 'd';
    ord_array[8][3] = '-';
    ord_array[8][4] = 'h';
    ord_array[8][5] = 'u';
    ord_array[8][6] = 's';
    ord_array[8][7] = 'e';
    ord_array[8][8] = 't';
    ord_array[8][9] = '\0';

    class_array[8][0] = 'N';
    class_array[8][1] = 'O';
    class_array[8][2] = 'U';
    class_array[8][3] = 'N';
    class_array[8][4] = '\0';

    ord_array[9][0] = 'i';
    ord_array[9][1] = '\0';

    class_array[9][0] = 'A';
    class_array[9][1] = 'D';
    class_array[9][2] = 'P';
    class_array[9][4] = '\0';

    ord_array[10][0] = 'a';
    ord_array[10][1] = 'n';
    ord_array[10][2] = 'l';
    ord_array[10][3] = 'e';
    ord_array[10][4] = 'd';
    ord_array[10][5] = 'n';
    ord_array[10][6] = 'i';
    ord_array[10][7] = 'n';
    ord_array[10][8] = 'g';
    ord_array[10][9] = '\0';

    class_array[10][0] = 'N';
    class_array[10][1] = 'O';
    class_array[10][2] = 'U';
    class_array[10][3] = 'N';
    class_array[10][4] = '\0';

    ord_array[11][0] = 'a';
    ord_array[11][1] = 'f';
    ord_array[11][2] = '\0';

    class_array[11][0] = 'A';
    class_array[11][1] = 'D';
    class_array[11][2] = 'P';
    class_array[11][3] = '\0';

    ord_array[12][0] = 'a';
    ord_array[12][1] = 't';
    ord_array[12][2] = '\0';

    class_array[12][0] = 'S';
    class_array[12][1] = 'C';
    class_array[12][2] = 'O';
    class_array[12][3] = 'N';
    class_array[12][4] = 'J';
    class_array[12][5] = '\0';

    ord_array[13][0] = 'f';
    ord_array[13][1] = 'o';
    ord_array[13][2] = 'r';
    ord_array[13][3] = 'm';
    ord_array[13][4] = 'a';
    ord_array[13][5] = 'n';
    ord_array[13][6] = 'd';
    ord_array[13][7] = 'e';
    ord_array[13][8] = 'n';
    ord_array[13][9] = '\0';

    class_array[13][0] = 'N';
    class_array[13][1] = 'O';
    class_array[13][2] = 'U';
    class_array[13][3] = 'N';
    class_array[13][4] = '\0';

    ord_array[14][0] = 'K';
    ord_array[14][1] = 'j';
    ord_array[14][2] = 'e';
    ord_array[14][3] = 'l';
    ord_array[14][4] = 'd';
    ord_array[14][5] = '\0';

    class_array[14][0] = 'P';
    class_array[14][1] = 'R';
    class_array[14][2] = 'O';
    class_array[14][3] = 'P';
    class_array[14][4] = 'N';
    class_array[14][5] = '\0';

    ord_array[15][0] = 'c';
    ord_array[15][1] = 'h';
    ord_array[15][2] = 'r';
    ord_array[15][3] = 'i';
    ord_array[15][4] = 's';
    ord_array[15][5] = 't';
    ord_array[15][6] = 'e';
    ord_array[15][7] = 'n';
    ord_array[15][8] = 's';
    ord_array[15][9] = 'e';
    ord_array[15][10] = 'n';
    ord_array[15][11] = '\0';

    class_array[15][0] = 'P';
    class_array[15][1] = 'R';
    class_array[15][2] = 'O';
    class_array[15][3] = 'P';
    class_array[15][4] = 'N';
    class_array[15][5] = '\0';

    ord_array[16][0] = 'g';
    ord_array[16][1] = 'a';
    ord_array[16][2] = 'a';
    ord_array[16][3] = 'r';
    ord_array[16][4] = '\0';

    class_array[16][0] = 'V';
    class_array[16][1] = 'E';
    class_array[16][2] = 'R';
    class_array[16][3] = 'B';
    class_array[16][4] = '\0';

    ord_array[17][0] = 'i';
    ord_array[17][1] = 'n';
    ord_array[17][2] = 'd';
    ord_array[17][3] = '\0';

    class_array[17][0] = 'A';
    class_array[17][1] = 'D';
    class_array[17][2] = 'V';
    class_array[17][4] = '\0';

    ord_array[18][0] = 'i';
    ord_array[18][1] = '\0';

    class_array[18][0] = 'A';
    class_array[18][1] = 'D';
    class_array[18][2] = 'P';
    class_array[18][4] = '\0';

    ord_array[19][0] = 'd';
    ord_array[19][1] = 'e';
    ord_array[19][2] = '\0';

    class_array[19][0] = 'D';
    class_array[19][1] = 'E';
    class_array[19][2] = 'T';
    class_array[19][4] = '\0';

    ord_array[20][0] = 'g';
    ord_array[20][1] = 'l';
    ord_array[20][2] = 'a';
    ord_array[20][3] = 'd';
    ord_array[20][4] = 'e';
    ord_array[20][5] = '\0';

    class_array[20][0] = 'A';
    class_array[20][1] = 'D';
    class_array[20][2] = 'J';
    class_array[20][4] = '\0';

    ord_array[21][0] = 't';
    ord_array[21][1] = 'r';
    ord_array[21][2] = 'e';
    ord_array[21][3] = 's';
    ord_array[21][4] = 's';
    ord_array[21][5] = 'e';
    ord_array[21][6] = 'r';
    ord_array[21][7] = 'e';
    ord_array[21][8] = '\0';

    class_array[21][0] = 'N';
    class_array[21][1] = 'O';
    class_array[21][2] = 'U';
    class_array[21][3] = 'N';
    class_array[21][4] = '\0';

    ord_array[22][0] = '.';
    ord_array[22][1] = '\0';

    class_array[22][0] = 'P';
    class_array[22][1] = 'U';
    class_array[22][2] = 'N';
    class_array[22][3] = 'C';
    class_array[22][4] = 'T';
    class_array[22][5] = '\0';
}