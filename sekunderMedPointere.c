#include <stdio.h>

void omregner(int sek_in, int *sekp, int *minp, int *timp);

int main(void){
    int sek_in, sek, min, tim;

    printf("Indtast antal sekunder til beregneing.");
    scanf("%d", &sek_in);

    omregner(sek_in, &sek, &min, &tim);

    if (tim > 1) {
        printf("%d timer\n", tim);
    } else if(tim == 1) {
        printf("%d time\n", tim);
    } else {

    }

    if (min > 1) {

        printf("%d minutter\n", min);
    } else if(min == 1) {
        printf("%d minut\n", min);
    } else {

    }

    if (sek > 1) {
        printf("%d sekunder\n", sek);
    } else if(sek == 1) {
        printf("%d sekund\n", sek);
    } else {

    }
    
    return 0;
}

void 
omregner(int sek_in, int *sekp, int *minp, int *timp) {
int rest_sek = 0;

    *timp = sek_in / 3600;                   
    rest_sek = sek_in % 3600;
   
    *minp = rest_sek / 60;                    
    rest_sek = rest_sek % 60;

    *sekp = rest_sek; 

}