#include "Rook.h"
Rook::Rook(int a,int b,char x):Chessman(a,b,x)
{   
}
bool Rook::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol)
{
    if (iSrcRow == iDestRow) 
    {
        return true;
	} 
    else if (iDestCol == iSrcCol) 
    {
        return true;
	}
    return false;
}
