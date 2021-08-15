
#include "Queen.h"
Queen::Queen(sf::Vector2i pos,sf::RenderWindow *s,char x):Chessman(pos,s,x)
{
    namad='Q';
    warn=5;
    point=15;
    if(x=='w')
    {
        texture.loadFromFile("White/Queen.png");
    }
    else
    {
        texture.loadFromFile("Black/Queen.png");
    }
    TextureSprite.setTexture(texture);
}
Queen::Queen() {}
Queen::~Queen() {}

bool Queen::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol,Cell *cellBoard[8][8])
{
    if (iSrcRow == iDestRow)
    {
        // Make sure that all invervening squares are empty
        int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
        for (int iCheckCol = iSrcCol + iColOffset; iCheckCol !=  iDestCol; iCheckCol = iCheckCol + iColOffset)
        {
            if (!cellBoard[iSrcRow][iCheckCol]->IsEmpty())
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
            if (!cellBoard[iCheckRow][iSrcCol] ->IsEmpty())
            {
                return false;
            }
        }
        return true;
    }
    else if ((iDestCol - iSrcCol == iDestRow - iSrcRow) || (iDestCol - iSrcCol == iSrcRow - iDestRow))
    {
        // Make sure that all invervening squares are empty
        int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
        int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
        int iCheckRow;
        int iCheckCol;
        for (iCheckRow = iSrcRow + iRowOffset, iCheckCol = iSrcCol + iColOffset; iCheckRow !=  iDestRow;iCheckRow = iCheckRow + iRowOffset, iCheckCol = iCheckCol + iColOffset)
        {
            if (!cellBoard[iCheckRow][iCheckCol] ->IsEmpty())
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

