#ifndef QUEEN_H
#define QUEEN_H
#include "chessman.h"
class Queen:public Chessman
{
    public:
        Queen(int,int,char);
        Queen();
    protected:
        char namad='Q';
        int warn=5;
        int point=15;
        bool AreSquaresLegal(int,int,int,int,Cell *[8][8]);
};

    
#endif
