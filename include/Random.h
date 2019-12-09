/**
 *
 * 
 *
 * <p>
 * Rastgele sayi struct tanimi
 * </p>
 *
 */

#ifndef Random_h
#define Random_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


struct RANDOM {
    
    int seed;
    int (*RandomUNInt)(struct RANDOM *);
    void (*Delete)(struct RANDOM *);
    
};

typedef struct RANDOM* Random;

int RandomUNInt(Random this);
Random GetRandom();
void RandomDelete(Random);


#endif /* Random_h */
