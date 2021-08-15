#include "Bishop.h"
Bishop::Bishop(sf::Vector2i pos,sf::RenderWindow* s,char x):Chessman(pos,s,x)
{
    namad='B';
    warn=2;
    point=8;
    if(x=='w')
    {
        texture.loadFromFile("White/Bishop.png");
    }
    else
    {
        texture.loadFromFile("Black/Bishop.png");
    }
    TextureSprite.setTexture(texture);
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
bool Bishop::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol,Cell *cellBoard[8][8])
{
    if ((iDestCol - iSrcCol == iDestRow - iSrcRow) || (iDestCol - iSrcCol == iSrcRow - iDestRow))
    {
        // Make sure that all invervening squares are empty
        int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
        int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
        int iCheckRow;
        int iCheckCol;
        for (iCheckRow = iSrcRow + iRowOffset, iCheckCol = iSrcCol + iColOffset;iCheckRow !=  iDestRow && iCheckRow >= 0 && iCheckRow < 8 && iCheckCol >= 0 && iCheckCol < 8;iCheckRow = iCheckRow + iRowOffset, iCheckCol = iCheckCol + iColOffset)
        {
            if ( !cellBoard[iCheckRow][iCheckCol]->IsEmpty())
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
Bishop::~Bishop()
{
}
