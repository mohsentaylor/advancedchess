#include "Rook.h"
Rook::Rook(int a,int b,char x):Chessman(a,b,x)
{   
}
bool Rook::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol,Chessman * qpaaBoard[8][8])
{
    if (iSrcRow == iDestRow) 
    {
        // Make sure that all invervening squares are empty
        int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
        for (int iCheckCol = iSrcCol + iColOffset; iCheckCol !=  iDestCol; iCheckCol = iCheckCol + iColOffset) 
        {
            if (qpaaBoard[iSrcRow][iCheckCol] != 0) 
            {
                return false;
            }
        }
        return true;
	} 
    else if (iDestCol == iSrcCol) 
    {
        // Make sure that all invervening squares are empty
        int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
        for (int iCheckRow = iSrcRow + iRowOffset; iCheckRow !=  iDestRow; iCheckRow = iCheckRow + iRowOffset) 
        {
            if (qpaaBoard[iCheckRow][iSrcCol] != 0) 
            {
                return false;
            }
        }
        return true;
	}
    return false;
}
