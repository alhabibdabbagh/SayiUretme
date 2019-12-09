

#include "RastgeleKarakter.h"


RastgeleKarakter GetRastgeleKarakter(){
    RastgeleKarakter Obj;
    Obj = (RastgeleKarakter)malloc(sizeof(struct RASTGELEKARAKTER));
    Obj->super = GetRandom();
    Obj->Delete = &DeleteRastgele;
    Obj->Char = &Char;
    Obj->CharByLength = &CharByLength;
    Obj->CharBetween = &CharBetween;
    Obj->CharBetweenByLength = &CharBetweenByLength;
    Obj->Sentence = &Sentence;
    Obj->SentenceByLength = &SentenceByLength;
    Obj->CharFrom = &CharFrom;
    Obj->CharFromByLength = &CharFromByLength;
    return Obj;
}


void DeleteRastgele(RastgeleKarakter Obj){   //heapte isgal edilmis olan hafiza yerlerini bosaltir
    if (Obj == NULL)
        return;
    Obj->super->Delete(Obj->super);
    free(Obj);
    Obj = NULL;
}

int IsAlphabetic(char a ){ //bir karakterin alfabetik olup olmadigini kontrol eden fonksiyon
    return  (a > 64 && a < 91 ) || (a >96 && a<123);
}

char Char(RastgeleKarakter Obj){  // rastgele karakter ureten fonksiyon
    int rand = Obj->super->RandomUNInt(Obj->super);   //bir rastgele deger uretilmistir
    int val = ((rand % 26) + 65); //rastgele degeri bir karakter kodu temsil edecek sekilde ayarlanmistir
    if (Obj->super->RandomUNInt(Obj->super)%3 == 0)   //rastgele bir sekilde karakterin kucuk veya buyuk durumu belirlenmistir
        val += 32;
    return (char)val;
}

char* CharByLength(RastgeleKarakter Obj,int length){  //belirli sayida rastgele karakter ureten fonksiyon
    char*ret = malloc(sizeof(char) * (length+1));
    for (int i = 0; i < length; i++) {    //istenen sayi kadar karakter uretilmistir
        ret[i] = Obj->Char(Obj);
    }
    ret[length] = '\0';
    return ret;
}

char CharBetween(RastgeleKarakter Obj,char A,char B){  //belirlenen iki karakter arasindan alfabetik siralamaya gore karakter ureten fonksiyon
    int a = A > 96 ? ((int)A - 32) :(int) A;    //karakter kucuk harf ise buyuk karaktere cevrilmistir
    int b = B > 96 ? ((int)B - 32) :(int) B;

    if (!IsAlphabetic(A) || !IsAlphabetic(B)) //parametre ile verilen karakterlerin alfabetik olup olmadigi kontrol edilmistir
        return ' ';
    int rand = Obj->super->RandomUNInt(Obj->super);
    int val = (rand % abs((b - a)) + (a > b ? b : a));  //verilen karakterlerin koduna gore bir rastgele deger uretilmistir

    if (Obj->super->RandomUNInt(Obj->super)%3 == 0)
        val += 32;
    return (char) val;
}

char* CharBetweenByLength(RastgeleKarakter Obj,int length,char A,char B){  //belirlenen iki karakter arasindan alfabetik siralamaya gore belirli sayida karakter ureten fonksiyon
    char*ret = malloc(sizeof(char) * (length+1));
    for (int i = 0; i < length; i++) {    //istenen sayi kadar karakter uretilmistir
        ret[i] = Obj->CharBetween(Obj,A,B);
    }
    ret[length] = '\0';
    return ret;
}

char* Sentence(RastgeleKarakter Obj){  //rastgele kelimelerden rastgele sayida kelimeli cumle ureten fonksiyon

    int length = Obj->super->RandomUNInt(Obj->super) % 9 + 2;   //cumlenin uzunlugu 2 ile 10 arasindan rastgele atanmistir
    char * sentence[length];
    int * wordLengths = (int *)malloc(sizeof(int) * length); //kelimelerin uzunluklari icin malloc kullanarak heapte yer acilmistir
    int TotalLength = 0;

    for (int i = 0; i < length; i++) {
        int len =Obj->super->RandomUNInt(Obj->super)%9 + 2;  //kelimelerin uzunlugu 2 ile 10 arasindan rastgele bir sayida olusturulmustur
        sentence[i] = Obj->CharByLength(Obj, len );
        TotalLength += len + 1;
        wordLengths[i] = len;
    }

    char * ret = (char *)malloc(sizeof(char) * TotalLength); //dondurulecek cumle icin heapte yer acilmistir
    int index = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < wordLengths[i]; j++) {
            ret[index] = sentence[i][j];index++;
        }
        ret[index] = ' ';index++;
    }
    ret[index] = '\0';

    for (int i = 0; i < length; i++) {
        free(sentence[i]); //kelimeler icin hafizada acilan yerler kapatilmistir
    }
    return ret;

}

char* SentenceByLength(RastgeleKarakter Obj,int length){  //rastgele kelimelerden verilen sayida kelimeli cumle ureten fonksiyon
    char * sentence[length];
    int * wordLengths = (int *)malloc(sizeof(int) * length); //kelimelerin uzunluklari icin malloc kullanarak heapte yer
    int TotalLength = 0;

    for (int i = 0; i < length; i++) {
        int len =Obj->super->RandomUNInt(Obj->super)%9 + 2;  //kelimelerin uzunlugu 2 ile 10 arasindan rastgele bir sayida olusturulmustur
        sentence[i] = Obj->CharByLength(Obj, len );
        TotalLength += len + 1;
        wordLengths[i] = len;
    }

    char * ret = (char *)malloc(sizeof(char) * TotalLength); //dondurulecek cumle icin heapte yer acilmistir
    int index = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < wordLengths[i]; j++) {
            ret[index] = sentence[i][j];index++;
        }
        ret[index] = ' ';index++;
    }
    ret[index] = '\0';

    for (int i = 0; i < length; i++) {
        free(sentence[i]);  //kelimeler icin hafizada acilan yerler kapatilmistir
    }
    return ret;
}

char CharFrom(RastgeleKarakter Obj,int num,...) {  //belirtilen karakterler arasından bir karakter ureten fonksiyon

    va_list valist;     //degisken sayida parametre verildigi icin liste yapisi tanimlanmistir
    char ret;
    int i;

    va_start(valist, num);
    int deger = Obj->super->RandomUNInt(Obj->super) % num + 1;

    for (i = 0; i < deger; i++) {
        ret = va_arg(valist, int);
    }
    va_end(valist);
    return ret;
}
char* CharFromByLength(RastgeleKarakter Obj,int length,int num,...){  //belirtilen karakterler arasından belirtilen sayıda karakter ureten fonksiyon


    va_list valist;     //degisken sayida parametre verildigi icin liste yapisi tanimlanmistir
    char * args = (char*)malloc(sizeof(char)*num);
    char * ret = (char*)malloc(sizeof(char)*length+1);

    va_start(valist, num);

    for (int i = 0; i < num; i++) {
        args[i] = (char) va_arg(valist, int);
    }
    va_end(valist);

    for (int i=0; i < length; i++) {
        int index = Obj->super->RandomUNInt(Obj->super)%num;
        ret[i] = args[index];
    }
    ret[length] = '\0';
    free(args);     //heapte acilan yerler kapatilmistir
    return ret;

}
