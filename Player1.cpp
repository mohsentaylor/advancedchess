#include "Player1.h"
#include <string>
Player1::Player1(sf::RenderWindow * window)
{
    queen =new Queen(sf::Vector2i(0,4),window,'w');
    king=new King(sf::Vector2i(0,3),window,'w');
    rook1=new Rook(sf::Vector2i(0,0),window,'w');
    rook2=new Rook(sf::Vector2i(0,7),window,'w');
    knight1=new Knight(sf::Vector2i(0,1),window,'w');
    knight2=new Knight(sf::Vector2i(0,6),window,'w');
    bishop1=new Bishop(sf::Vector2i(0,2),window,'w');
    bishop2=new Bishop(sf::Vector2i(0,5),window,'w');
    pawn1=new Pawn(sf::Vector2i(1,0),window,'w');
    pawn2=new Pawn(sf::Vector2i(1,1),window,'w');
    pawn3=new Pawn(sf::Vector2i(1,2),window,'w');
    pawn4=new Pawn(sf::Vector2i(1,3),window,'w');
    pawn5=new Pawn(sf::Vector2i(1,4),window,'w');
    pawn6=new Pawn(sf::Vector2i(1,5),window,'w');
    pawn7=new Pawn(sf::Vector2i(1,6),window,'w');
    pawn8=new Pawn(sf::Vector2i(1,7),window,'w');
    pieces.push_back(queen );
    pieces.push_back(king );
    pieces.push_back(rook1 );
    pieces.push_back(rook2 );
    pieces.push_back(knight1 );
    pieces.push_back(knight2);
    pieces.push_back(bishop1);
    pieces.push_back(bishop2);
    pieces.push_back(pawn1);
    pieces.push_back(pawn2);
    pieces.push_back(pawn3);
    pieces.push_back(pawn4);
    pieces.push_back(pawn5);
    pieces.push_back(pawn6);
    pieces.push_back(pawn7);
    pieces.push_back(pawn8);
    this->window=window;
}
void Player1::SetName(std::string name)
{
    this->name=name;
}
std::string Player1::GetName()
{
    return name;
}
void Player1::AddPoint(int a)
{
    point+=a;
}
unsigned int Player1::GetPoint()
{
    return point;
}
void Player1::AddNPoint(int a)
{
    negativepoint+=a;
}
short int Player1::GetNPoint()
{
    return negativepoint;
}
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
std::vector <Chessman *>&Player1::getPieces()
{
    return pieces;
}
