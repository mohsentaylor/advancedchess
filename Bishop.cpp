#include "Bishop.h"
Bishop::Bishop(sf::Vector2i pos,sf::RenderWindow* s,char x):Chessman(pos,s,x)
{
    if(x=='w')
    {
        texture.loadFromFile("/Users/Taylor1989/Desktop/advancedchess/project/White/Bishop.png");
    }
    else
    {
        texture.loadFromFile("/Users/Taylor1989/Desktop/advancedchess/project/Black/Bishop.png");
    }
    TextureSprite.setTexture(texture);
}
bool Bishop::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol,Cell *cellBoard[8][8])
{
    if ((iDestCol - iSrcCol == iDestRow - iSrcRow) || (iDestCol - iSrcCol == iSrcRow - iDestRow))
    {
        // Make sure that all invervening squares are empty
        int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
        int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
        int iCheckRow;
        int iCheckCol;
        for (iCheckRow = iSrcRow + iRowOffset, iCheckCol = iSrcCol + iColOffset;iCheckRow !=  iDestRow;iCheckRow = iCheckRow + iRowOffset, iCheckCol = iCheckCol + iColOffset)
        {
            if (cellBoard[iCheckRow][iCheckCol] != 0)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
Bishop::~Bishop()
{

}
