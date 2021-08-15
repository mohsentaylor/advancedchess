#include <Cell.h>
bool Cell::IsEmpty()
{
    if(ptr==nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Cell::SetNut(Chessman* x)
{
    ptr=x;
}

Cell::Cell()
{
}
