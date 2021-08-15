#include "King.h"
King::King(sf::Vector2i pos,sf::RenderWindow* s,char x):Chessman(pos,s,x)
{
    DidMove = false;
    namad='K';
    warn=10;
    point=50;
    if(x=='w')
    {
        texture.loadFromFile("White/King.png");
    }
    else
    {
        texture.loadFromFile("Black/King.png");
    }
    TextureSprite.setTexture(texture);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool King::AreSquaresLegal(int iSrcRow,int iSrcCol,int iDestRow,int iDestCol,Cell * cellBoard[8][8])
{
    int iRowDelta = iDestRow - iSrcRow;
    int iColDelta = iDestCol - iSrcCol;
    if (((iRowDelta >= -1) && (iRowDelta <= 1)) && ((iColDelta >= -1) && (iColDelta <= 1)))
    {
        DidMove=true;
        return true;
    }
    return false;	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
King::~King()
{

}

///////////////////////////////////////////////////////////////////////