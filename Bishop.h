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
        char namad='B';
        int warn=2;
        int point=8;
        bool AreSquaresLegal(int,int,int,int,Cell *x[8][8]) override;
};

    
#endif

