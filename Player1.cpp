#include "Player1.h"
#include <string>
Player1::Player1(sf::RenderWindow * window)
{
    point=0;
    negativepoint=0;
    queen =new Queen(sf::Vector2i(4,0),window,'w');
    king=new King(sf::Vector2i(3,0),window,'w');
    rook1=new Rook(sf::Vector2i(0,0),window,'w');
    rook2=new Rook(sf::Vector2i(7,0),window,'w');
    knight1=new Knight(sf::Vector2i(1,0),window,'w');
    knight2=new Knight(sf::Vector2i(6,0),window,'w');
    bishop1=new Bishop(sf::Vector2i(2,0),window,'w');
    bishop2=new Bishop(sf::Vector2i(5,0),window,'w');
    pawn1=new Pawn(sf::Vector2i(0,1),window,'w');
    pawn2=new Pawn(sf::Vector2i(1,1),window,'w');
    pawn3=new Pawn(sf::Vector2i(2,1),window,'w');
    pawn4=new Pawn(sf::Vector2i(3,1),window,'w');
    pawn5=new Pawn(sf::Vector2i(4,1),window,'w');
    pawn6=new Pawn(sf::Vector2i(5,1),window,'w');
    pawn7=new Pawn(sf::Vector2i(6,1),window,'w');
    pawn8=new Pawn(sf::Vector2i(7,1),window,'w');
    this->window=window;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Player1::AddPoint(int a)
{
    point+=a;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Player1::GetPoint()
{
    return point;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Player1::AddNPoint(int a)
{
    negativepoint+=a;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
short int Player1::GetNPoint()
{
    return negativepoint;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Player1::~Player1()
{
    delete king;
    delete queen;
    delete rook1;
    delete rook2;
    delete knight1;
    delete knight2;
    delete bishop1;
    delete bishop2;
    delete pawn1;
    delete pawn2;
    delete pawn3;
    delete pawn4;
    delete pawn5;
    delete pawn6;
    delete pawn7;
    delete pawn8;
}


///////////////////////////////////////////////////////////////////////