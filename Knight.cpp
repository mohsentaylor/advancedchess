#include "Knight.h"
Knight::Knight(int a,int b,char x):Chessman(a,b,x)
{   
}
bool Knight::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol)
{
    // Destination square is unoccupied or occupied by opposite color
    if ((iSrcCol == iDestCol + 1) || (iSrcCol == iDestCol - 1)) 
    {
        if ((iSrcRow == iDestRow + 2) || (iSrcRow == iDestRow - 2)) 
        {
            return true;
        }
    }
    if ((iSrcCol == iDestCol + 2) || (iSrcCol == iDestCol - 2)) 
    {
        if ((iSrcRow == iDestRow + 1) || (iSrcRow == iDestRow - 1)) 
        {
            return true;
        }
    }
    return false;
	
}
