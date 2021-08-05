#include "Pawn.h"
Pawn::Pawn(int a,int b,char x):Chessman(a,b,x)
{   
}
bool Pawn::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol)
{
			// Destination square is unoccupied
			if (iSrcCol == iDestCol) 
            {
				if (GetColor() == 'W') 
                {
					if (iDestRow == iSrcRow + 1) 
                    {
						return true;
					}
				} 
                else 
                {
					if (iDestRow == iSrcRow - 1) 
                    {
						return true;
					}
				}
			}
			// Dest holds piece of opposite color
			if ((iSrcCol == iDestCol + 1) || (iSrcCol == iDestCol - 1)) 
            {
				if (GetColor() == 'W') 
                {
					if (iDestRow == iSrcRow + 1) 
                    {
						return true;
					}
				} 
                else 
                {
					if (iDestRow == iSrcRow - 1) 
                    {
						return true;
					}
				}
			}

		return false;
	
}
