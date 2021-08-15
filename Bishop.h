#ifndef BISHOP_H
#define BISHOP_H
#include "chessman.h"
class Bishop:public Chessman
{
    public:
        Bishop(sf::Vector2i,sf::RenderWindow*,char);
        Bishop() {}
        virtual ~Bishop();
    protected:
        bool AreSquaresLegal(int,int,int,int,Cell *x[8][8]) override;
};


#endif

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////