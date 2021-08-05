#ifndef BISHOP_H
#define BISHOP_H
#include "chessman.h"
class Bishop:public Chessman
{
    public:
        Bishop(int,int,char);
        Bishop() {}
    protected:
        char namad='B';
        int warn=2;
        int point=8;
        bool AreSquaresLegal(int,int,int,int);
};

    
#endif

