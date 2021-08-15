#include "Knight.h"
Knight::Knight(sf::Vector2i pos,sf::RenderWindow * s,char x):Chessman(pos,s,x)
{
    namad='H';
    warn=2;
    point=8;
    if(x=='w')
    {
        texture.loadFromFile("White/Knight.png");
    }
    else
    {
        texture.loadFromFile("Black/Knight.png");
    }
    TextureSprite.setTexture(texture);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Knight::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol,Cell *cellBoard[8][8])
{
    // Destination square is unoccupied or occupied by opposite color
    if ((iSrcCol == iDestCol + 1) || (iSrcCol == iDestCol - 1)) 
    {
        if ((iSrcRow == iDestRow + 2) || (iSrcRow == iDestRow - 2)) 
        {
            return true;
        }
    }
    if ((iSrcCol == iDestCol + 2) || (iSrcCol == iDestCol - 2)) 
    {
        if ((iSrcRow == iDestRow + 1) || (iSrcRow == iDestRow - 1)) 
        {
            return true;
        }
    }
    return false;	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Knight::~Knight()
{

}

///////////////////////////////////////////////////////////////////////