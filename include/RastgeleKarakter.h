/**
 *
 * 
 *
 * <p>
 * Rastgele Karakter struct ana tanimi
 * </p>
 *
 */

#ifndef RastgeleKarakter_h
#define RastgeleKarakter_h

#include <stdio.h>
#include <stdarg.h>
#include "Random.h"


struct RASTGELEKARAKTER{
    Random super;
    void (*Delete)(struct RASTGELEKARAKTER *);
    int (*IsAlphabetic)(char a );
    char (*Char)(struct RASTGELEKARAKTER *);
    char* (*CharByLength)(struct RASTGELEKARAKTER *,int length);
    char (*CharBetween)(struct RASTGELEKARAKTER *,char A,char B);
    char* (*CharBetweenByLength)(struct RASTGELEKARAKTER *,int length,char A,char B);
    char* (*Sentence)(struct RASTGELEKARAKTER *);
    char* (*SentenceByLength)(struct RASTGELEKARAKTER *,int length);
    char (*CharFrom)(struct RASTGELEKARAKTER *,int,...);
    char* (*CharFromByLength)(struct RASTGELEKARAKTER *,int length,int,...);
    
};

typedef struct RASTGELEKARAKTER* RastgeleKarakter;

RastgeleKarakter GetRastgeleKarakter();
void DeleteRastgele(RastgeleKarakter);
int IsAlphabetic(char);
char Char(RastgeleKarakter);
char* CharByLength(RastgeleKarakter,int);
char CharBetween(RastgeleKarakter,char ,char );
char* CharBetweenByLength(RastgeleKarakter,int ,char ,char );
char* Sentence(RastgeleKarakter);
char* SentenceByLength(RastgeleKarakter,int );
char CharFrom(RastgeleKarakter,int,...);
char* CharFromByLength(RastgeleKarakter,int ,int,...);

#endif /* RastgeleKarakter_h */
