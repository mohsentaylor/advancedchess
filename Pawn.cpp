#include "Pawn.h"
Pawn::Pawn(sf::Vector2i pos,sf::RenderWindow *s,char x):Chessman(pos,s,x)
{
    if(x=='w')
    {
        texture.loadFromFile("/Users/Taylor1989/Desktop/advancedchess/project/White/Pawn.png");
    }
    else
    {
        texture.loadFromFile("/Users/Taylor1989/Desktop/advancedchess/project/Black/Pawn.png");
    }
    TextureSprite.setTexture(texture);
}
bool Pawn::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol,Cell *cellBoard[8][8])
{
    Cell* qpDest = cellBoard[iDestRow][iDestCol];
            if (qpDest == 0)
            {
                // Destination square is unoccupied
                if (iSrcCol == iDestCol)
                {
                    if (GetColor() == 'w')
                    {
                        if (iDestRow == iSrcRow + 1)
                        {
                            DidMove=true;
                            return true;
                        }
                        if (iDestRow == iSrcRow + 2 && !DidMove)
                        {
                            DidMove=true;
                            return true;
                        }
                    }
                    else
                    {
                        if (iDestRow == iSrcRow - 1)
                        {
                            DidMove=true;
                            return true;
                        }
                        if (iDestRow == iSrcRow - 2 && !DidMove)
                        {
                            DidMove=true;
                            return true;
                        }
                    }
                }
            }
            else
            {
                // Dest holds piece of opposite color
                if ((iSrcCol == iDestCol + 1) || (iSrcCol == iDestCol - 1))
                {
                    if (GetColor() == 'w')
                    {
                        if (iDestRow == iSrcRow + 1)
                        {
                            DidMove=true;
                            return true;
                        }
                    }
                    else
                    {
                        if (iDestRow == iSrcRow - 1)
                        {
                            DidMove=true;
                            return true;
                        }
                    }
                }
            }
            return false;
}

