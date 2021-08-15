#include "Pawn.h"
Pawn::Pawn(sf::Vector2i pos,sf::RenderWindow *s,char x):Chessman(pos,s,x)
{
    DidMove = false;
    warn=1;
    point=3;
    namad='P';
    if(x=='w')
    {
        texture.loadFromFile("White/Pawn.png");
    }
    else
    {
        texture.loadFromFile("Black/Pawn.png");
    }
    TextureSprite.setTexture(texture);
}
Pawn::Pawn() {}
Pawn::~Pawn() {}

bool Pawn::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol,Cell *cellBoard[8][8])
{
    Cell* qpDest = cellBoard[iDestRow][iDestCol];
    if (qpDest->ptr == 0)
    {
        // Destination square is unoccupied
        if (iSrcRow == iDestRow)
        {
            if (GetColor() == 'w')
            {
                if (iDestCol == iSrcCol + 1)
                {
                    DidMove=true;
                    return true;
                }
                if (iDestCol == iSrcCol + 2 && !DidMove)
                {
                    DidMove=true;
                    return true;
                }
            }
            else
            {
                if (iDestCol == iSrcCol - 1)
                {
                    DidMove=true;
                    return true;
                }
                if (iDestCol == iSrcCol - 2 && !DidMove)
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
        if ((iSrcRow == iDestRow + 1) || (iSrcRow == iDestRow - 1))
        {
            if (GetColor() == 'w')
            {
                if (iDestCol == iSrcCol + 1)
                {
                    DidMove=true;
                    return true;
                }
            }
            else
            {
                if (iDestCol == iSrcCol - 1)
                {
                    DidMove=true;
                    return true;
                }
            }
        }
    }
    return false;
}

