// This is where we start writing out functions
// Members who have worked on this file:

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDS_IN_ORDBOG 64896
#define WORDS_COUNT 300
#define CHAR_COUNT 50
#define SUB_END_COUNT 9
#define SUB_END_LEN 4
#define ADJ_END_COUNT 8
#define ADJ_END_LEN 5
#define VER_END_COUNT 11
#define VER_END_LEN 5
#define ADV_END_COUNT 5
#define ADV_END_LEN 4
#define ORDBOG_CLASS_COUNT 15
#define ORDBOG_CLASS_LEN 11

int str_ending_compare(char *ord, char *ending);
char *capitol_to_lowercase(char *ord);
char *class_switch(int i, char *ord);

int substantiver(char *ord);  // navneord
int is_capitol_letter(char first_letter);
int sub_correct_ending(char *ord);

int adjektiver(char *ord);  // tillaegsord
int adj_correct_ending(char *ord);

int verber(char *ord);  // udsagnsord
int ver_correct_ending(char *ord);  

int adverbier(char *ord);  // biord
int adv_correct_ending(char *ord);

int artikler(char *ord);  // kendeord
int is_article(char *ord);

int konjunktioner(char *ord);  // bindeord
int is_conjunction(char *ord);

int praepositioner(char *ord);  // forholdsord
int is_preposition(char *ord);

int udraabsord(char *ord);  // udraabsord
int is_yelling(char *ord);

int lydord(char *ord);  // lydord
int is_sound(char *ord);

int talord(char *ord);  // talord
int cmp_talord(char *ord);
int str_talord(char *ord);

int pronomener(char *ord); // stedord 
int is_pronomener(char *ord);

char * BinSearch(char ** ord_array, char ** word_class, char * ord);

int * get_our_estimate(char ** book_array_words, char ** book_array_class, char * ord);



void testord(char **ord_array, char **class_array);

/*
//Test main for functions
int main(void){
    char **ord_array = (char **)malloc(WORDS_COUNT * sizeof(char *));
    char **class_array = (char **)malloc(WORDS_COUNT * sizeof(char *));
    char **vores_klaase_array = (char **)malloc(WORDS_COUNT * sizeof(char *));


    testord(ord_array, class_array);

    substantiver(ord_array[0]);

    adjektiver(ord_array[21]);

    verber(ord_array[21]);

    adverbier(ord_array[21]);

    artikler(ord_array[21]);

    konjunktioner(ord_array[21]);

    praepositioner(ord_array[21]);

    udraabsord(ord_array[21]);

    lydord(ord_array[21]);

    talord(ord_array[21]);

    pronomener(ord_array[2]);

    printf(" %d", is_capitol_letter(ord_array[24][3]));
}
*/

/*char * get_our_estimate(char ** book_array_words, char ** book_array_class, char * ord){
    
    char * ordbogs_class = BinSearch(book_array_words, book_array_class, ord);
    //printf("%s\n", ordbogs_class);
    ordbogs_class[strlen(ordbogs_class)-1] = '\0';
    printf("%s\n", ordbogs_class);
    
    char * token = strtok(ordbogs_class, ",");
    char * midlertidig = token;
    printf("midertidig: %s\n", midlertidig);
    char * token2 = strtok(ordbogs_class, ";");
    printf("Token: %s\n",  token2);
    token = strtok(NULL, "\r");
    printf("Token: %s\n",  token2);
    token = strtok(NULL, "\r");
    printf("Token: %s\n",  token2);
    token = strtok(NULL, "\r;");
    printf("Token: %s\n",  token2);

    return "";
}*/

int * get_our_estimate(char ** book_array_words, char ** book_array_class, char * ord){
    char ordbog_classes[ORDBOG_CLASS_COUNT][ORDBOG_CLASS_LEN] = {
        "artikel", "sb", "vb", "adj", "adv", "konj", "pron", "prop", "praep", "praefiks", "udraabsord", "talord", "lydord", "fork"};
    int *ord_class_list = (int)calloc(ORDBOG_CLASS_COUNT, sizeof(int));
    char *ordbogs_class = (char *)malloc(CHAR_COUNT * sizeof(char));
    
    
    /*for (int c = 0; c < ORDBOG_CLASS_COUNT; c++) {
         if(c = ORDBOG_CLASS_COUNT) {
             ord_class_list[c] = '\0';
         }
         ord_class_list[c] = 0;
     }*/

    ordbogs_class = BinSearch(book_array_words, book_array_class, ord);

    printf("BinReturn: %s\n", ordbogs_class);

    printf("Test\n");

    for(int c = 0; c < ORDBOG_CLASS_COUNT; c++) {
        char *tempt = calloc(ORDBOG_CLASS_LEN, sizeof(char));
        // char *token = calloc(ORDBOG_CLASS_LEN, sizeof(char));
    
    //printf("Ordbogs_class: %s ordbog_classes: %s\n", ordbogs_class, ordbog_classes);
            tempt = strstr(ordbogs_class, ordbog_classes[c]); //tempt token
            tempt = strtok(tempt, ",");
            tempt = strtok(tempt, ";");
            printf("Ordbogs_class: %s");
            printf("strstr %s\n", tempt);
            //printf("Token: %s\n", token);
            printf("classes2 %s\n", ordbog_classes[c]);

        if (strcmp(tempt, ordbog_classes[c]) == 0) { 
            printf("Ordbogs_class: %s ordbog_classes: %s\n", ordbogs_class, ordbog_classes);
            printf("TestEfterIF. C er lig: %d\n", c);
    
            ord_class_list[c] = 1;
        }
    }
    for(int c = 0; c < ORDBOG_CLASS_COUNT; c++) {
    printf("Array: %d\n", ord_class_list[c]);
    }
    return ord_class_list;
}


int str_ending_compare(char *ord, char *ending) {
    int c;
    // int result;
    int ord_len = (strlen(ord) + 1);
    int ending_len = (strlen(ending) + 1);
    char ord_ending[ending_len];

    // printf(" %s, %s\n", ord, ending);

    for (c = 1; c <= ending_len; c++) {
        ord_ending[ending_len - c] = ord[ord_len - c];
    }

    // printf(" %s, %s\n", ending, ord_ending);

    return strcmp(ending, ord_ending);
}

char *class_switch(int i, char *ord) {
        switch(i) {

        case 0:
            pronomener(ord);
            break;
        case 1:
            artikler(ord);
            break;
        case 2:
            substantiver(ord);
            break;
        case 3:
            verber(ord);
            break;
        case 4:
            adjektiver(ord);
            break;
        case 5:
            adverbier(ord);
            break;
        case 6:
            konjunktioner(ord);
            break;
        case 7:
            substantiver(ord); // Dette er specifikt proprier (mangler funktion)
            break;
        case 8:
            praepositioner(ord);
            break;
        case 9:
            // praefiks(ord); // Dette skal 
            break;
        case 10:
            talord(ord);
            break;
        case 11:
            lydord(ord);
            break;
        case 12:
            udraabsord(ord);
            break;
        case 13:
            // fork(ord);
            break;
    }
    return "test";
}

char *capitol_to_lowercase(char *ord) {
    int ord_len = strlen(ord) + 1;
    int c;

    for (c = 0; c < ord_len; c++) {
        ord[c] = tolower(ord[c]);
    }
    printf("Omskrevet ord er %s.\n", ord);
    return ord;
}

int substantiver(char *ord) {
    printf(" %s\n\n", ord);

    if (is_capitol_letter(ord[0]) == 2) {
        printf("capitol er opfyldt\n\n");
        printf("nyt ord er %s\n\n", capitol_to_lowercase(ord));
    } else {
        printf("capitol er ikke opfyldt\n\n");
    }

    if (sub_correct_ending(ord) == 1) {
        printf("sub_ending er opfyldt\n\n");
    } else {
        printf("sub_ending er ikke opfyldt\n\n");
    }

    return 0;
}

int is_capitol_letter(char first_letter) {
    if (first_letter >= 'A' && first_letter <= 'Z') {
        return 2;
    } else if (first_letter >= 'a' && first_letter <= 'z') {
        return 1;
    } else {
        return 0;
    }
}

int sub_correct_ending(char *ord) {
    // int c;
    char sub_endings[SUB_END_COUNT][SUB_END_LEN] = {"ene", "ne", "er", "et",
                                                    "en",  "r",  "s",  "e"};

    for (int c = 0; c < SUB_END_COUNT; c++) {
        if (str_ending_compare(ord, sub_endings[c]) == 0) {
            return 1;
        }
    }
    return 0;
}

int adjektiver(char *ord) {
    if (adj_correct_ending(ord) == 1) {
        printf("adj_ending er opfyldt\n\n");
    } else {
        printf("adj_ending er ikke opfyldt\n\n");
    }
    return 0;
}

int adj_correct_ending(char *ord) {
    // int c;
    char adj_endings[ADJ_END_COUNT][ADJ_END_LEN] = {"este", "est", "ere", "st",
                                                    "re",   "t",   "e"};

    for (int c = 0; c < ADJ_END_COUNT; c++) {
        if (str_ending_compare(ord, adj_endings[c]) == 0) {
            return 1;
        }
    }
    return 0;
}

int verber(char *ord) {
    if (ver_correct_ending(ord) == 1) {
        printf("ver_ending er opfyldt\n\n");
    } else {
        printf("ver_ending er ikke opfyldt\n\n");
    }
    return 0;
}

int ver_correct_ending(char *ord) {
    // int c;
    char ver_endings[VER_END_COUNT][VER_END_LEN] = {
        "ende", "tes", "ede", "es", "te", "et", "de", "er", "t", "r", "e"};

    for (int c = 0; c < VER_END_COUNT; c++) {
        if (str_ending_compare(ord, ver_endings[c]) == 0) {
            return 1;
        }
    }
    return 0;
}

int adverbier(char *ord) {
    if (adv_correct_ending(ord) == 1) {
        printf("adv_ending er opfyldt\n\n");
    } else {
        printf("adv_ending er ikke opfyldt\n\n");
    }
    return 0;
}

int adv_correct_ending(char *ord) {
    // int c;
    char adv_endings[ADV_END_COUNT][ADV_END_LEN] = {"vis", "lig", "ig", "t"};

    for (int c = 0; c < ADV_END_COUNT; c++) {
        if (str_ending_compare(ord, adv_endings[c]) == 0) {
            return 1;
        }
    }
    return 0;
}

int artikler(char *ord) {
    if (is_article(ord) == 1) {
        printf("article er opfyldt\n\n");
    } else {
        printf("article er ikke opfyldt\n\n");
    }

    return 0;
}

int is_article(char *ord) {
    char article[5][6] = {"den", "det", "en", "et", "de"};

    for (int i = 0; i < (int)sizeof(article); i++) {
        if (strcmp(ord, article[i]) ==
            0)  // strcmp(ene_string, anden_string) tjekker om første-string
                // tilsvarer anden-string {
            return 1;
    }
    return 0;
}

int konjunktioner(char *ord) {
    if (is_conjunction(ord) == 1) {
        printf("conjunction er opfyldt\n\n");
    } else {
        printf("conjunction er ikke opfyldt\n\n");
    }
    return 0;
}

int is_conjunction(char *ord) {
    char sideordnende[5][8] = {"eller", "for", "men", "saa", "og"};
    char underordnende[12][8] = {"hvorfor", "hvordan", "hvilken", "hvilket",
                                 "fordi",   "hvor",    "hvad",    "hvis",
                                 "naar",    "mens",    "der",     "som"};
    char saa[3][6] = {"om", "at", "da"};

    for (int i = 0; i < (int)sizeof(sideordnende); i++) {
        if (strcmp(ord, sideordnende[i]) == 0) {
            return 1;
        }
    }
    for (int i = 0; i < (int)sizeof(underordnende); i++) {
        if (strcmp(ord, underordnende[i]) == 0) {
            return 1;
        }
    }
    for (int i = 0; i < (int)sizeof(saa); i++) {
        if (strcmp(ord, saa[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int praepositioner(char *ord) {
    if (is_preposition(ord) == 1) {
        printf("preposition er opfyldt\n\n");
    } else {
        printf("preposition er ikke opfyldt\n\n");
    }
    return 0;
}

int is_preposition(char *ord) {
    char preposition[26][14] = {
        "omkring", "mellem", "gennem", "under", "efter", "foran", "forbi",
        "inden",   "langs",  "over",   "imod",  "uden",  "foer",  "til",
        "fra",     "ved",    "for",    "med",   "hos",   "mod",   "bag",
        "paa",     "om",     "af",     "ad",    "i"};

    for (int i = 0; i < (int)sizeof(preposition); i++) {
        if (strcmp(ord, preposition[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int udraabsord(char *ord) {
    if (is_yelling(ord) == 1) {
        printf("udraabsord er opfyldt\n\n");
    } else {
        printf("udraabsord er ikke opfyldt\n\n");
    }
    return 0;
}

int is_yelling(char *ord) {
    char yelling[17][9] = {"tillykke", "fandens", "satans", "farvel", "barvo",
                           "fuck",     "lort",    "roev",   "hej",    "nej",
                           "aah",      "ja",      "av",     "wow",    "shh",
                           "hmm",      "ih"};

    for (int i = 0; i < (int)sizeof(yelling); i++) {
        if (strcmp(ord, yelling[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int lydord(char *ord) {
    if (is_sound(ord) == 1) {
        printf("lydord er opfyldt\n\n");
    } else {
        printf("lydord er ikke opfyldt\n\n");
    }
    return 0;
}

int is_sound(char *ord) {
    char sound[9][11] = {"dingeling", "kykliky", "pladask", "hvisle", "bipper",
                         "miav",      "atju",    "muh",     "bip"};

    for (int i = 0; i < (int)sizeof(sound); i++) {
        if (strcmp(ord, sound[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int talord(char *ord) {
    if (cmp_talord(ord) == 1 || str_talord(ord) == 1) {
        printf("talord er opfyldt\n\n");
    } else {
        printf("talord er ikke opfyldt\n\n");
    }
    return 0;
}

int cmp_talord(char *ord) {
    char talord[33][11] = {
        "nul",      "en",      "to",         "tre",     "fire",     "fem",
        "seks",     "syv",     "otte",       "ni",      "ti",       "elleve",
        "tolv",     "tretten", "fjorten",    "femten",  "seksten",  "sytten",
        "atten",    "nitten",  "tyve",       "tredive", "fyrre",    "halvtreds",
        "tres",     "treds",   "halvfjerds", "firs",    "halvfems", "hundred",
        "hundrede", "tusind",  "tudsinde"};

    for (int i = 0; i < (int)sizeof(talord); i++) {
        if (strcmp(ord, talord[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int str_talord(char *ord) {
    char tal_ord[22][11] = {
        "enog",    "toog",       "treog",   "fireog",  "femog",     "seksog",
        "syvog",   "otteog",     "niog",    "hundred", "hundrede",  "tusind",
        "tusinde", "tyve",       "tredive", "fyrre",   "halvtreds", "tres",
        "treds",   "halvfjerds", "firs",    "halvfems"};

    for (int i = 0; i < (int)sizeof(tal_ord); i++) {
        if (strstr(ord, tal_ord[i])) {
            return 1;
        }
    }
    return 0;
}

int pronomener(char *ord) {
    if (is_pronomener(ord) == 1) {
        printf("pronomener er opfyldt\n\n");
    } else {
        printf("pronomener er ikke opfyldt\n\n");
    }
    return 0;
}

int is_pronomener(char *ord) {
    char personlige[18][6] = {"jeg", "du",    "han", "hun", "det", "den",
                              "vi",  "i",     "de",  "mig", "dig", "dem",
                              "ham", "hende", "os",  "jer", "dem"};
    char ejestedord[16][7] = {
        "min",  "mit",  "mine",  "din",   "dit",   "dine", "hans", "hendes",
        "dens", "dets", "vores", "jeres", "deres", "sin",  "sit",  "sine"};
    char henvisende[2][6] = {"der", "som"};

    for (int i = 0; i < (int)sizeof(personlige); i++) {
        if (strcmp(ord, personlige[i]) == 0) {
            return 1;
        }
    }

    for (int i = 0; i < (int)sizeof(ejestedord); i++) {
        if (strcmp(ord, ejestedord[i]) == 0) {
            return 1;
        }
    }

    for (int i = 0; i < (int)sizeof(henvisende); i++) {
        if (strcmp(ord, henvisende[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

char * BinSearch(char ** ord_array, char ** word_class, char * ord){
    char *class = (char *)malloc(CHAR_COUNT*sizeof(char));
    //printf("\n");
    int lower;
    int max;
    int midt;
    lower = 1;
    max = WORDS_IN_ORDBOG;
    while (lower < max){
        midt = (lower + max)/2;
        
        //printf("Min:\t%d\nMidt:\t%d\nMax:\t%d\n", lower, midt, max);
        //printf("strcmp: %d\n", strcmp(ord, ord_array[midt]));


        if ((strcmp(ord, ord_array[midt]) >= 0)){
            //printf("ordet: %s, ligger højere end ordet: %s\n", ord, ord_array[midt]);
            lower = midt + 1;
        } else{
            //printf("ordet: %s, ligger lavere end ordet: %s\n", ord, ord_array[midt]);
            max = midt;
        }
        //printf("\n");

  }
    //printf("Min:\t%d\nMidt:\t%d\nMax:\t%d\n ord_array:\t %s\n", lower, midt, max, ord_array[midt]);
    
    //Tjekker om omkringliggende ord matcher, det vi leder efter og tilføjer det til class
    int x = midt - 5;
    int y = midt + 5;
    if (midt <= 5){
        x = 0;
        y = x + 9;
    } else if (midt >= WORDS_IN_ORDBOG - 5){
        y = WORDS_IN_ORDBOG;
        x = WORDS_IN_ORDBOG - 10;
    }

    //strcat(class,ord);
    //strcat(class,";");
    //printf("Tjekker for om der er flere ord, med anden ordklasse\n");
    while (x != y){
        if (strcmp(ord, ord_array[x]) == 0){
            //printf("Ordet på plads %d matcher!\n%s og %s\n",x ,ord , ord_array[x]);
            //printf("Tilføjer ordklassen til 'class'-arrayet\n");
            strcat(class,word_class[x]);
            strcat(class,";");
            x++;
        } else {
            //printf("Ordet på plads %d matcher ikke!\n%s og %s\n",x ,ord , ord_array[x]);
            x++;
        }
 
    }
    //printf("Class er %s\n", class);

    if (strcmp(ord, ord_array[lower - 1]) == 0){
        class[strlen(class) +1] = '\0';
        //printf("BinSeach: %s er på position %d\n",ord,lower);'
        return class;
    }
    return "";
}


// funktion for endelse(artikel) 
// funktion for artikel - tjek forrige ord
// funktion for første ord i sætning - tjek forrige ord for punktum
// funktion for ordklassesandsynlighed - tjek returværdier




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

    ord_array[8][0] = 'S';
    ord_array[8][1] = 'I';
    ord_array[8][2] = 'D';
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

    ord_array[15][0] = 'C';
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