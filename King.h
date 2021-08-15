#ifndef KING_H
#define KING_H
#include "chessman.h"
class King:public Chessman
{
    public:
        King(sf::Vector2i,sf::RenderWindow *,char);
        King() {};
        virtual ~King();
    protected:
        bool AreSquaresLegal(int,int,int,int,Cell *[8][8]) override;
};

    
#endif

///////////////////////////////////////////////////////////////////////