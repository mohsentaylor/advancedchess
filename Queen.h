#ifndef QUEEN_H
#define QUEEN_H
#include "chessman.h"
class Queen:public Chessman
{
    public:
        Queen(sf::Vector2i,sf::RenderWindow *,char);
        Queen();
        virtual ~Queen();
    protected:
        bool AreSquaresLegal(int,int,int,int,Cell *[8][8]) override;
};

    
#endif

///////////////////////////////////////////////////////////////////////