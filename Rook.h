#ifndef ROOK_H
#define ROOK_H
#include "chessman.h"
class Rook:public Chessman
{
    public:
        Rook(int,int,char);
        Rook() {}
        bool DidMove = false;
    protected:
        char namad='R';
        int warn=2;
        int point=8;
        bool AreSquaresLegal(int,int,int,int,Cell *[8][8]);
};

    
#endif
