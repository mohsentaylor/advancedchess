#ifndef PAWN_H
#define PAWN_H
#include "chessman.h"
class Pawn: public Chessman
{
    public:
        Pawn(sf::Vector2i,sf::RenderWindow*,char);
        Pawn();
        virtual ~Pawn();
    protected:
        bool AreSquaresLegal(int,int,int,int,Cell *[8][8]) override;
};

    
#endif

///////////////////////////////////////////////////////////////////////