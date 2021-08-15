
#include "Rook.h"
Rook::Rook(sf::Vector2i pos,sf::RenderWindow *s,char x):Chessman(pos,s,x)
{
    DidMove = false;
    namad='R';
    warn=2;
    point=8;
    if(x=='w')
    {
        texture.loadFromFile("White/Rook.png");
    }
    else
    {
        texture.loadFromFile("Black/Rook.png");
    }
    TextureSprite.setTexture(texture);
}
Rook::Rook() {}
Rook::~Rook() {}

bool Rook::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol,Cell *cellBoard[8][8])
{
    if (iSrcRow == iDestRow)
    {
        // Make sure that all invervening squares are empty
        int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
        for (int iCheckCol = iSrcCol + iColOffset; iCheckCol !=  iDestCol && iSrcRow >= 0 && iSrcRow < 8 && iCheckCol >= 0 && iCheckCol < 8; iCheckCol = iCheckCol + iColOffset)
        {
            if (!cellBoard[iSrcRow][iCheckCol]->IsEmpty())
            {
                return false;
            }
        }
        DidMove=true;
        return true;
    }
    else if (iDestCol == iSrcCol)
    {
        // Make sure that all invervening squares are empty
        int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
        for (int iCheckRow = iSrcRow + iRowOffset; iCheckRow !=  iDestRow; iCheckRow = iCheckRow + iRowOffset)
        {
            if (!cellBoard[iCheckRow][iSrcCol] ->IsEmpty())
            {
                return false;
            }
        }
        DidMove=true;
        return true;
    }
    return false;
}
