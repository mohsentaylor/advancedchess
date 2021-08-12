#include "King.h"
King::King(sf::Vector2i pos,sf::RenderWindow* s,char x):Chessman(pos,s,x)
{   
    if(x=='w')
    {
        texture.loadFromFile("/Users/Taylor1989/Desktop/advancedchess/project/White/King.png");
    }
    else
    {
        texture.loadFromFile("/Users/Taylor1989/Desktop/advancedchess/project/Black/King.png");
    }
    TextureSprite.setTexture(texture);
}
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
King::~King()
{

}
