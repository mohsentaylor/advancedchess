#include "Queen.h"
Queen::Queen(int a,int b,char x):Chessman(a,b,x)
{   
}

Queen::Queen() {

}


bool Queen::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol)
{
    if (iSrcRow == iDestRow) 
    {
        return true;
	} 
    else if (iDestCol == iSrcCol) 
    {
        return true;
	}
    else if ((iDestCol - iSrcCol == iDestRow - iSrcRow) || (iDestCol - iSrcCol == iSrcRow - iDestRow)) 
    {
        return true;
	}
	return false;
}
