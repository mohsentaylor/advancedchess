#ifndef CELL_H
#define CELL_H
#include <chessman.h>
#include <iostream>
class Cell
{
    public:
        Chessman *ptr=nullptr;
        bool IsEmpty();
        void SetNut(Chessman *);
};
#endif
