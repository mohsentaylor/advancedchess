#include "King.h"
King::King(int a,int b,char x):Chessman(a,b,x)
{   
}
bool King::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol)
{
    int iRowDelta = iDestRow - iSrcRow;
    int iColDelta = iDestCol - iSrcCol;
    if (((iRowDelta >= -1) && (iRowDelta <= 1)) && ((iColDelta >= -1) && (iColDelta <= 1)))
    {
        return true;
    }
    return false;	
}
