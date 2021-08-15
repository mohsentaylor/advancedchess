#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <SFML/Graphics.hpp>
class Chessman;
class Cell
{
    public:
        Cell();
        Chessman *ptr=nullptr;
        bool IsEmpty();
        void SetNut(Chessman *);
};
#endif

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////