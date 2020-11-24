//This is where we start writing out functions
//Members who have worked on this file: 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORDS_COUNT 300
#define CHAR_COUNT 50
#define SUB_END_COUNT 9
#define SUB_END_LEN 4
#define ADJ_END_COUNT 8
#define ADJ_END_LEN 5
#define VER_END_COUNT 11
#define VER_END_LEN 5

int str_ending_compare(char *ord, char *ending);
int capitol_to_lowercase(char *ord);

int substantiver(char *ord); // navneord
int is_capitol_letter(char first_letter);
int sub_correct_ending(char *ord);

int adjektiver(char *ord); // tillaegsord
int adj_correct_ending(char *ord);

int verber(char *ord); // udsagnsord
int ver_correct_ending(char *ord);

int adverbier(char *ord); // biord
int adv_correct_ending(char *ord);

int artikler(char *ord); // kendeord
int is_article(char *ord);

int konjunktioner(char *ord); // bindeord
int is_conjunction(char *ord);

int praepositioner(char *ord); // forholdsord
int is_preposition(char *ord);

int udraabsord(char *ord); // udraabsord
int is_yelling(char *ord);

int lydord(char *ord); // lydord
int is_sound(char *ord);

int talord(char *ord); // talord
int cmp_talord(char *ord);
int str_talord(char *ord);


// int pronomener(char *ord); // stedord


void testord(char ** ord_array, char ** class_array);


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
    
    printf(" %d", is_capitol_letter(ord_array[24][3]));
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

int substantiver(char *ord) {
    printf(" %s\n\n", ord);

    if(is_capitol_letter(ord[0]) == 2) {
        printf("capitol er opfyldt\n\n");
        printf("nyt ord er %s\n\n", capitol_to_lowercase(ord));
    } else {
        printf("capitol er ikke opfyldt\n\n");
    }

    if(sub_correct_ending(ord) == 1) {
        printf("sub_ending er opfyldt\n\n");
    } else {
        printf("sub_ending er ikke opfyldt\n\n");
    }

    return 0;
}

int capitol_to_lowercase(char *ord) {
    int ord_len = strlen(ord) + 1;
    int c;

    for(c = 0; c < ord_len; c++) {
        ord[c] = tolower(ord[c]);
    }
    printf("Omskrevet ord er %s.\n", ord);
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

/*int str_ending_compare(char *ord, char *ending) {
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
} */

int sub_correct_ending(char *ord) {
    int c;
    char sub_endings[SUB_END_COUNT][SUB_END_LEN] = {"ene","ne", "er", "et", "en", "r", "s", "e"};


    for(int c = 0; c < SUB_END_COUNT; c++) {
        if(str_ending_compare(ord, sub_endings[c]) == 0) {
            return 1;
        }
    }
    return 0;
}

/*int sub_correct_ending(char *ord) {
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
    /*
    if((str_ending_compare(ord, ene) == 0)) {            // strstr(ord, segment) tjekker om første-string(ord) tilsvarer anden-string(segment)
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
    }*/
    
    /*
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
    
}*/


int adjektiver(char *ord) {
    if(adj_correct_ending(ord) == 1) {
        printf("adj_ending er opfyldt\n\n");
    } else {
        printf("adj_ending er ikke opfyldt\n\n");
    }
    return 0;
}

int adj_correct_ending(char *ord) {
    int c;
    char adj_endings[ADJ_END_COUNT][ADJ_END_LEN] = {"este","est", "ere", "st", "re", "t", "e"};


    for(int c = 0; c < ADJ_END_COUNT; c++) {
        if(str_ending_compare(ord, adj_endings[c]) == 0) {
            return 1;
        }
    }
    return 0;
}

/*int adj_correct_ending(char *ord) {
    char este[] = "este";
    char est[] = "est";
    char ere[] = "ere";
    char st[] = "st";
    char re[] = "re";
    char t[] = "t";
    char e[] = "e";
    
    if((str_ending_compare(ord, este) == 0)) {        
        return 1;
    } else if((str_ending_compare(ord, est) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, ere) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, st) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, re) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, t) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, e) == 0)) {
        return 1;
    } else {
        return 0;
    }
}
*/

int verber(char *ord) {
    if(ver_correct_ending(ord) == 1) {
        printf("ver_ending er opfyldt\n\n");
    } else {
        printf("ver_ending er ikke opfyldt\n\n");
    }
    return 0;
}

int ver_correct_ending(char *ord) {
    int c;
    char ver_endings[VER_END_COUNT][VER_END_LEN] = {"ende","tes", "ede", "es", "te", "et", "de", "er", "t", "r", "e"};


    for(int c = 0; c < VER_END_COUNT; c++) {
        if(str_ending_compare(ord, ver_endings[c]) == 0) {
            return 1;
        }
    }
    return 0;
}

/*
int ver_correct_ending(char *ord) {
    char ende[] = "ende";
    char tes[] = "tes";
    char ede[] = "ede";
    char es[] = "es";
    char te[] = "te";
    char et[] = "et";
    char de[] = "de";
    char er[] = "er";
    char t[] = "t";
    char r[] = "r";
    char e[] = "e";
    
    if((str_ending_compare(ord, ende) == 0)) {        
        return 1;
    } else if((str_ending_compare(ord, tes) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, ede) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, es) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, te) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, et) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, de) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, er) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, t) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, r) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, e) == 0)) {
        return 1;
    } else {
        return 0;
    }

}
*/

int adverbier(char *ord) {
    if(adv_correct_ending(ord) == 1) {
        printf("adv_ending er opfyldt\n\n");
    } else {
        printf("adv_ending er ikke opfyldt\n\n");
    }
    return 0;
}

int adv_correct_ending(char *ord) {
    char vis[] = "vis";
    char lig[] = "lig";
    char ig[] = "ig";
    char t[] = "t";

    if((str_ending_compare(ord, vis) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, lig) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, ig) == 0)) {
        return 1;
    } else if((str_ending_compare(ord, t) == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int artikler(char *ord) {
    
    if(is_article(ord) == 1) {
        printf("article er opfyldt\n\n");
    } else {
        printf("article er ikke opfyldt\n\n");
    }
    
    return 0;
}

int is_article(char *ord) {
    char article[5][] = {"den", "det", "en", "et", "de"};
    /*char den[] = "den";
    char det[] = "det";
    char en[] = "en";
    char et[] = "et";
    char de[] = "de";*/
    
    for (int i = 0; i < sizeof(article); i++)
    {
        if(strcmp(ord, article[i]) == 0)
            return 1;
        }
    }
    

    /*if((strcmp(ord, den) == 0)) {                                      // strcmp(ene_string, anden_string) tjekker om første-string tilsvarer anden-string 
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
    }*/

    return 0;
}

int konjunktioner(char *ord) {
    
    if(is_conjunction(ord) == 1) {
        printf("conjunction er opfyldt\n\n");
    } else {
        printf("conjunction er ikke opfyldt\n\n");
    }
    
    return 0;
}

int is_conjunction(char *ord) {
    char sideordnende[5][8] = {"eller", "for", "men", "saa", "og"};
    /* sideordnende
    char eller[] = "eller";
    char o_for[] = "for";
    char men[] = "men";
    char saa[] = "saa"; // betydning "derfor"
    char og[] = "og";*/

    char underordnende[12][6] = {"hvorfor", "hvordan", "hvilken", "hvilket", "fordi", "hvor", "hvad", "hvis", "naar", "mens", "der", "som"};
    /*underordnende
    char hvorfor[] = "hvorfor";
    char hvordan[] = "hvordan";
    char hvilken[] = "hvilken";
    char hvilket[] = "hvilket";
    char fordi[] = "fordi";
    char hvor[] = "hvor";
    char hvad[] = "hvad";
    char hvis[] = "hvis";
    char naar[] = "naar";
    char mens[] = "mens";
    char der[] = "der";
    char som[] = "som"; */

    char saa[3][6] = {"om", "at", "da"};
    /* char saa[] = "saa"; // betydning "saadan at"
    char om[] = "om";
    char at[] = "at";
    char da[] = "da";*/

    for (int i = 0; i < sizeof(sideordnende); i++)
    {
        if (strcmp(ord, sideordnende[i]) == 0)
        {
            return 1;
        }
        
    }

    for (int i = 0; i < sizeof(underordnende); i++)
    {
        if (strcmp(ord, underordnende[i]) == 0)
        {
            return 1;
        }
        
    }
    
    for (int i = 0; i < sizeof(saa) i++)
    {
        if (strcmp(ord, saa[i]) == 0)
        {
            return 1;
        }
        
    }
    
    return 0;
    
    /*
    if((strcmp(ord, eller) == 0)) { 
        return 1;
    } else if((strcmp(ord, o_for) == 0)) {
        return 1;
    } else if((strcmp(ord, men) == 0)) {
        return 1;
    } else if((strcmp(ord, saa) == 0)) {
        return 1;
    } else if((strcmp(ord, og) == 0)) {
        return 1;
    } else if((strcmp(ord, hvorfor) == 0)) {
        return 1;
    } else if((strcmp(ord, hvordan) == 0)) {
        return 1;
    } else if((strcmp(ord, hvilken) == 0)) {
        return 1;
    } else if((strcmp(ord, hvilket) == 0)) {
        return 1;
    } else if((strcmp(ord, fordi) == 0)) {
        return 1;
    } else if((strcmp(ord, hvor) == 0)) {
        return 1;
    } else if((strcmp(ord, hvad) == 0)) {
        return 1;
    } else if((strcmp(ord, hvis) == 0)) {
        return 1;
    } else if((strcmp(ord, naar) == 0)) {
        return 1;
    } else if((strcmp(ord, mens) == 0)) {
        return 1;
    } else if((strcmp(ord, der) == 0)) {
        return 1;
    } else if((strcmp(ord, som) == 0)) {
        return 1;
    } else if((strcmp(ord, om) == 0)) {
        return 1;
    }  else if((strcmp(ord, at) == 0)) {
        return 1;
    } else if((strcmp(ord, da) == 0)) {
        return 1;
    } else {
        return 0;
    }*/
}

int praepositioner(char *ord) {
    
    if(is_preposition(ord) == 1) {
        printf("preposition er opfyldt\n\n");
    } else {
        printf("preposition er ikke opfyldt\n\n");
    }
    return 0;
}

int is_preposition(char *ord) {
    char preposition[26][14] = {"omkring", "mellem", "gennem", "under", "efter", "foran", "forbi", "inden", "langs", "over", "imod", "uden", "foer", "til", "fra", "ved", "for", "med", "hos", "mod", "bag", "paa", "om", "af", "ad", "i"};
    /*
    char omkring[] = "omkring";
    char mellem[] = "mellem";
    char gennem[] = "gennem";
    char under[] = "under";
    char efter[] = "efter";
    char foran[] = "foran";
    char forbi[] = "forbi";
    char inden[] = "inden";
    char langs[] = "langs";
    char over[] = "over";
    char imod[] = "imod";
    char uden[] = "uden";
    char foer[] = "foer";
    char til[] = "til";
    char fra[] = "fra";
    char ved[] = "ved";
    char o_for[] = "for";
    char med[] = "med";
    char hos[] = "hos";
    char mod[] = "mod";
    char bag[] = "bag";
    char paa[] = "paa";
    char om[] = "om";
    char af[] = "af";
    char ad[] = "ad";
    char i[] = "i";   */

    for (int i = 0; i < sizeof(preposition); i++)
    {
        if (strcmp(ord, preposition[i]) == 0)
        {
            return 1;
        }
        
    }
    
    return 0;
    /*
    if((strcmp(ord, omkring) == 0)) { 
        return 1;
    } else if((strcmp(ord, mellem) == 0)) {
        return 1;
    } else if((strcmp(ord, gennem) == 0)) {
        return 1;
    } else if((strcmp(ord, under) == 0)) {
        return 1;
    } else if((strcmp(ord, efter) == 0)) {
        return 1;
    } else if((strcmp(ord, foran) == 0)) {
        return 1;
    } else if((strcmp(ord, forbi) == 0)) {
        return 1;
    } else if((strcmp(ord, inden) == 0)) {
        return 1;
    } else if((strcmp(ord, langs) == 0)) {
        return 1;
    } else if((strcmp(ord, over) == 0)) {
        return 1;
    } else if((strcmp(ord, imod) == 0)) {
        return 1;
    } else if((strcmp(ord, uden) == 0)) {
        return 1;
    } else if((strcmp(ord, foer) == 0)) {
        return 1;
    } else if((strcmp(ord, til) == 0)) {
        return 1;
    } else if((strcmp(ord, fra) == 0)) {
        return 1;
    } else if((strcmp(ord, ved) == 0)) {
        return 1;
    } else if((strcmp(ord, o_for) == 0)) {
        return 1;
    } else if((strcmp(ord, med) == 0)) {
        return 1;
    } else if((strcmp(ord, hos) == 0)) {
        return 1;
    } else if((strcmp(ord, mod) == 0)) {
        return 1;
    } else if((strcmp(ord, bag) == 0)) {
        return 1;
    } else if((strcmp(ord, paa) == 0)) {
        return 1;
    } else if((strcmp(ord, om) == 0)) {
        return 1;
    } else if((strcmp(ord, af) == 0)) {
        return 1;
    }  else if((strcmp(ord, ad) == 0)) {
        return 1;
    } else if((strcmp(ord, i) == 0)) {
        return 1;
    } else {
        return 0;
    }*/
}

int udraabsord(char *ord) {
    
    if(is_yelling(ord) == 1) {
        printf("udraabsord er opfyldt\n\n");
    } else {
        printf("udraabsord er ikke opfyldt\n\n");
    }
    return 0;
}

int is_yelling(char *ord) {
    char yelling[17][9] = {"tillykke", "fandens", "satans", "farvel", "barvo", "fuck", "lort", "roev", "hej", "nej", "aah", "ja", "av", "wow", "shh", "hmm", "ih"};
    /*char tillykke[] = "tillykke";
    char fandens[] = "fandens";
    char satans[] = "satans";
    char farvel[] = "farvel";
    char bravo[] = "bravo";
    char fuck[] = "fuck";
    char lort[] = "lort";
    char roev[] = "roev";
    char hej[] = "hej";
    char nej[] = "nej";
    char aah[] = "aah";
    char ja[] = "ja";
    char av[] = "av";
    char wow[] = "wow";
    char shh[] = "shh";
    char hmm[] = "hmm";
    char ih[] = "ih";*/

    for (int i = 0; i < sizeof(yelling); i++)
    {
        if (strcmp(ord, yelling[i]) == 0)
        {
            return 1;
        }
        
    }
    
    return 0;
    /*
    if((strcmp(ord, tillykke) == 0)) {                                   
        return 1;
    } else if((strcmp(ord, fandens) == 0)) {
        return 1;
    } else if((strcmp(ord, satans) == 0)) {
        return 1;
    } else if((strcmp(ord, farvel) == 0)) {
        return 1;
    } else if((strcmp(ord, bravo) == 0)) {
        return 1;
    } else if((strcmp(ord, fuck) == 0)) {
        return 1;
    } else if((strcmp(ord, lort) == 0)) {
        return 1;
    } else if((strcmp(ord, roev) == 0)) {
        return 1;
    } else if((strcmp(ord, hej) == 0)) {
        return 1;
    } else if((strcmp(ord, nej) == 0)) {
        return 1;
    } else if((strcmp(ord, aah) == 0)) {
        return 1;
    } else if((strcmp(ord, av) == 0)) {
        return 1;
    } else if((strcmp(ord, wow) == 0)) {
        return 1;
    } else if((strcmp(ord, shh) == 0)) {
        return 1;
    } else if((strcmp(ord, hmm) == 0)) {
        return 1;
    } else if((strcmp(ord, ih) == 0)) {
        return 1;
    } else {
        return 0;
    }*/
}

int lydord(char *ord) {
    
    if(is_sound(ord) == 1) {
        printf("lydord er opfyldt\n\n");
    } else {
        printf("lydord er ikke opfyldt\n\n");
    }
    return 0;
}

int is_sound(char *ord) {
    char sound[9][11] = {"dingeling", "kykliky", "pladask", "hvisle", "bipper", "miav", "atju", "muh", "bip"};
    /*char dingeling[] = "dingeling";
    char kykliky[] = "kykliky";
    char pladask[] = "pladask";
    char hvisle[] = "hvisle";
    char bipper[] = "bipper";
    char miav[] = "miav";
    char atju[] = "atju";
    char muh[] = "muh";
    char bip[] = "bip";*/

    for (int i = 0; i < sizeof(sound); i++)
    {
        if (strcmp(ord, sound[i]) == 0)
        {
            return 1;
        }
        
    }
    
    return 0;
    /*
    if((strcmp(ord, dingeling) == 0)) {                                   
        return 1;
    } else if((strcmp(ord, kykliky) == 0)) {
        return 1;
    } else if((strcmp(ord, pladask) == 0)) {
        return 1;
    } else if((strcmp(ord, hvisle) == 0)) {
        return 1;
    } else if((strcmp(ord, bipper) == 0)) {
        return 1;
    } else if((strcmp(ord, miav) == 0)) {
        return 1;
    } else if((strcmp(ord, atju) == 0)) {
        return 1;
    } else if((strcmp(ord, muh) == 0)) {
        return 1;
    } else if((strcmp(ord, bip) == 0)) {
        return 1;
    } else {
        return 0;
    }*/
}

int talord(char *ord) {
    
    if(cmp_talord(ord) == 1 || str_talord(ord) == 1) {
        printf("talord er opfyldt\n\n");
    } else {
        printf("talord er ikke opfyldt\n\n");
    }
    return 0;
}

int cmp_talord(char *ord) {
    char talord[][] = {"nul", "en", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni", "ti", "elleve", "tolv", ""}
    char en[] = "en";
    char to[] = "to";
    char tre[] = "tre";
    char fire[] = "fire";
    char fem[] = "fem";
    char seks[] = "seks";
    char syv[] = "syv";
    char otte[] = "otte";
    char ni[] = "ni";
    char ti[] = "ti";
    char elleve[] = "elleve";
    char tolv[] = "tolv";
    char tretten[] = "tretten";
    char fjorten[] = "fjorten";
    char femten[] = "femten";
    char seksten[] = "seksten";
    char sytten[] = "sytten";
    char atten[] = "atten";
    char nitten[] = "nitten";
    char tyve[] = "tyve";
    char tredive[] = "tredive";
    char fyrre[] = "fyrre";
    char halvtreds[] = "halvtreds";
    char tres[] = "tres";
    char treds[] = "treds";
    char halvfjerds[] = "halvfjerds";
    char firs[] = "firs";
    char halvfems[] = "halvfems";
    char hundred[] = "hundred";
    char hundrede[] = "hundrede";
    char tusind[] = "tusind";
    char tusinde[] = "tusinde";

    if((strcmp(ord, en) == 0)) { 
        return 1;
    } else if((strcmp(ord, to) == 0)) {
        return 1;
    } else if((strcmp(ord, tre) == 0)) {
        return 1;
    } else if((strcmp(ord, fire) == 0)) {
        return 1;
    } else if((strcmp(ord, fem) == 0)) {
        return 1;
    } else if((strcmp(ord, seks) == 0)) {
        return 1;
    } else if((strcmp(ord, syv) == 0)) {
        return 1;
    } else if((strcmp(ord, otte) == 0)) {
        return 1;
    } else if((strcmp(ord, ni) == 0)) {
        return 1;
    } else if((strcmp(ord, ti) == 0)) {
        return 1;
    } else if((strcmp(ord, elleve) == 0)) {
        return 1;
    } else if((strcmp(ord, tolv) == 0)) {
        return 1;
    } else if((strcmp(ord, tretten) == 0)) {
        return 1;
    } else if((strcmp(ord, fjorten) == 0)) {
        return 1;
    } else if((strcmp(ord, femten) == 0)) {
        return 1;
    } else if((strcmp(ord, seksten) == 0)) {
        return 1;
    } else if((strcmp(ord, sytten) == 0)) {
        return 1;
    } else if((strcmp(ord, atten) == 0)) {
        return 1;
    } else if((strcmp(ord, nitten) == 0)) {
        return 1;
    } else if((strcmp(ord, tyve) == 0)) {
        return 1;
    } else if((strcmp(ord, tredive) == 0)) {
        return 1;
    } else if((strcmp(ord, fyrre) == 0)) {
        return 1;
    } else if((strcmp(ord, halvtreds) == 0)) {
        return 1;
    } else if((strcmp(ord, tres) == 0)) {
        return 1;
    } else if((strcmp(ord, treds) == 0)) {
        return 1;
    } else if((strcmp(ord, halvfjerds) == 0)) {
        return 1;
    } else if((strcmp(ord, firs) == 0)) {
        return 1;
    } else if((strcmp(ord, halvfems) == 0)) {
        return 1;
    } else if((strcmp(ord, hundred) == 0)) {
        return 1;
    } else if((strcmp(ord, hundrede) == 0)) {
        return 1;
    } else if((strcmp(ord, tusind) == 0)) {
        return 1;
    } else if((strcmp(ord, tusinde) == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int str_talord(char *ord) {
    char enog[] = "enog";
    char toog[] = "toog";
    char treog[] = "treog";
    char fireog[] = "fireog";
    char femog[] = "femog";
    char seksog[] = "seksog";
    char syvog[] = "syvog";
    char otteog[] = "otteog";
    char niog[] = "niog";
    char hundred[] = "hundred";
    char hundrede[] = "hundrede";
    char tusind[] = "tusind";
    char tusinde[] = "tusinde";
    /* Sikkert udnoedvendigt, men kan ogsaa compare med disse strings for oeget praecition
    char tyve[] = "tyve";
    char tredive[] = "tredive";
    char fyrre[] = "fyrre";
    char halvtreds[] = "halvtreds";
    char tres[] = "tres";
    char treds[] = "treds";
    char halvfjerds[] = "halvfjerds";
    char firs[] = "firs";
    char halvfems[] = "halvfems";
    */

    if(strstr(ord, enog)) {
        return 1;
    } else if(strstr(ord, toog)) {
        return 1;
    } else if(strstr(ord, treog)) {
        return 1;
    } else if(strstr(ord, fireog)) {
        return 1;
    } else if(strstr(ord, femog)) {
        return 1;
    } else if(strstr(ord, seksog)) {
        return 1;
    } else if(strstr(ord, syvog)) {
        return 1;
    } else if(strstr(ord, otteog)) {
        return 1;
    } else if(strstr(ord, niog)) {
        return 1;
    } else if(strstr(ord, hundred)) {
        return 1;
    } else if(strstr(ord, hundrede)) {
        return 1;
    } else if(strstr(ord, tusind)) {
        return 1;
    } else if(strstr(ord, tusinde)) {
        return 1;
    } else {
        return 0;
    }
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