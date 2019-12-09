/**
 *
 *
 *
 * <p>
 * Test icin yazilan program
 * </p>
 *
 */

#include <stdio.h>
#include "Random.h"
#include "RastgeleKarakter.h"



int main(int argc,char** argv){
    
    RastgeleKarakter test = GetRastgeleKarakter();
    
    printf("Rastgele Karakter Kutuphanesinin Testi :\n");
    printf("==============================================\n");
    
    printf("Rastgele Karakter :\n");
    for (int i =0; i < 100; i++) {
        if (i %20 ==0) {
            printf("\n");
        }
        printf("%c ",test->Char(test));
    }
    
    printf("\n==============================================\n");
    printf("Belirli sayida rastgele Karakter :\n");
    for (int i =0; i < 100; i++) {
        if (i %10 ==0) {
            printf("\n");
        }
        char * chars = test->CharByLength(test,3);
        printf("%s ",chars);
        free(chars);
    }
    
    printf("\n==============================================\n");
    printf("iki karakter arasindan alfabetik siralamaya gore karakter :\n");
    for (int i =0; i < 100; i++) {
        if (i %20 ==0) {
            printf("\n");
        }
        printf("%c ",test->CharBetween(test,'F','t'));
    }
    
    printf("\n==============================================\n");
    printf("iki karakter arasindan alfabetik siralamaya gore belirtilen sayida karakter :\n");
    for (int i =0; i < 100; i++) {
        if (i %10 ==0) {
            printf("\n");
        }
        char * chars = test->CharBetweenByLength(test,4,'F','t');
        printf("%s ",chars);
        free(chars);
    }
    
    printf("\n==============================================\n");
    printf("Rastgele cumle :\n\n");
    for (int i =0; i < 15; i++) {
        char * chars = test->Sentence(test);
        printf("%s\n",chars);
        free(chars);
    }
    
    printf("\n==============================================\n");
    printf("Belirtilen sayida rastgele kelimeli cumle :\n\n");
    for (int i =0; i < 15; i++) {
        char* chars = test->SentenceByLength(test,5);
        printf("%s\n",chars);
        free(chars);
    }
    
    printf("\n==============================================\n");
    printf("\nBelirtilen karakterler arasindan bir karakter ( 'a','v','E','S','T' ):");
    for (int i =0; i < 100; i++) {
        if (i %20 ==0) {
            printf("\n");
        }
        printf("%c ",test->CharFrom(test,5,'a','v','E','S','T'));
    }
    
    printf("\n==============================================\n");
    printf("\nBelirtilen karakterler arasindan 3 karakter ( 'q','T','m','D','R' ):");
    for (int i =0; i < 100; i++) {
        if (i %10 ==0) {
            printf("\n");
        }
        char * chars = test->CharFromByLength(test,3,5,'q','T','m','D','R');
        printf("%s ",chars);
        free(chars);
    }

    return 0;
}
