#ifndef KING_H
#define KING_H
#include "chessman.h"
class King:public Chessman
{
    public:
        King(int,int,char);
        King() {};
    protected:
        char namad='K';
        int warn=10;
        int point=50;
        bool AreSquaresLegal(int,int,int,int);
};

    
#endif
