#ifndef KNIGHT_H
#define KNIGHT_H
#include "chessman.h"
class Knight:public Chessman
{
    public:
        Knight(sf::Vector2i,sf::RenderWindow *,char);
        Knight() {}
        virtual ~Knight();
    protected:
        bool AreSquaresLegal(int,int,int,int,Cell *[8][8]) override;
};

    
#endif

///////////////////////////////////////////////////////////////////////