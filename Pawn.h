#ifndef PAWN_H
#define PAWN_H
#include "chessman.h"
class Pawn:public Chessman
{
    public:
        Pawn(int,int,char);
        Pawn();
        bool DidMove = false;
    protected:
        char namad='P';
        int warn=1;
        int point=3;
        bool AreSquaresLegal(int,int,int,int,Cell *[8][8]);
};

    
#endif
