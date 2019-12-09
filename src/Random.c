/**
 *
 *
 *
 * <p>
 * Rastgele Sayi Fonksiyonunun Tanimi
 * </p>
 *
 */

#include "Random.h"


Random GetRandom(){
    Random Obj;
    Obj = (Random) malloc(sizeof(struct RANDOM));
    Obj->Delete = &RandomDelete;
    Obj->RandomUNInt = &RandomUNInt;
    Obj->seed = (long) time(0);
    return Obj;
}

void RandomDelete(Random Obj){
    if (Obj ==NULL)
        return;
    free(Obj);
    Obj = NULL;
}
int RandomUNInt(Random Obj)
{
    int sonraki = Obj->seed*(unsigned int)Obj+Obj->seed;

    Obj->seed = sonraki;

    return sonraki < 0 ? -sonraki : sonraki;   
}


