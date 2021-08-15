#ifndef ROOK_H
#define ROOK_H
#include "chessman.h"
class Rook:public Chessman
{
    public:
        Rook(sf::Vector2i,sf::RenderWindow *,char);
        Rook();
        virtual ~Rook();
    protected:
        bool AreSquaresLegal(int,int,int,int,Cell *[8][8]) override;
};

    
#endif
