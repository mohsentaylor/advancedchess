#include "Rook.h"
Rook::Rook(sf::Vector2i pos,sf::RenderWindow *s,char x):Chessman(pos,s,x)
{   
    if(x=='w')
    {
        texture.loadFromFile("/Users/Taylor1989/Desktop/advancedchess/project/White/Rook.png");
    }
    else
    {
        texture.loadFromFile("/Users/Taylor1989/Desktop/advancedchess/project/Black/Rook.png");
    }
    TextureSprite.setTexture(texture);
}
bool Rook::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol,Cell *cellBoard[8][8])
{
    if (iSrcRow == iDestRow)
    {
        // Make sure that all invervening squares are empty
        int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
        for (int iCheckCol = iSrcCol + iColOffset; iCheckCol !=  iDestCol; iCheckCol = iCheckCol + iColOffset)
        {
            if (cellBoard[iSrcRow][iCheckCol] != 0)
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
            if (cellBoard[iCheckRow][iSrcCol] != 0)
            {
                return false;
            }
        }
        DidMove=true;
        return true;
    }
    return false;
}
