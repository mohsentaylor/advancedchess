#include "Bishop.h"
Bishop::Bishop(int a,int b,char x):Chessman(a,b,x)
{   
}
bool Bishop::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol)
{
    if ((iDestCol - iSrcCol == iDestRow - iSrcRow) || (iDestCol - iSrcCol == iSrcRow - iDestRow)) 
    {
        return true;
    }
    return false;
}

