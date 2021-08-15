#include "Player2.h"
#include <string>
Player2::Player2(sf::RenderWindow *window)
{
    point=0;
    negativepoint=0;
    queen =new Queen(sf::Vector2i(4,7),window,'b');
    king=new King(sf::Vector2i(3,7),window,'b');
    rook1=new Rook(sf::Vector2i(0,7),window,'b');
    rook2=new Rook(sf::Vector2i(7,7),window,'b');
    knight1=new Knight(sf::Vector2i(1,7),window,'b');
    knight2=new Knight(sf::Vector2i(6,7),window,'b');
    bishop1=new Bishop(sf::Vector2i(2,7),window,'b');
    bishop2=new Bishop(sf::Vector2i(5,7),window,'b');
    pawn1=new Pawn(sf::Vector2i(0,6),window,'b');
    pawn2=new Pawn(sf::Vector2i(1,6),window,'b');
    pawn3=new Pawn(sf::Vector2i(2,6),window,'b');
    pawn4=new Pawn(sf::Vector2i(3,6),window,'b');
    pawn5=new Pawn(sf::Vector2i(4,6),window,'b');
    pawn6=new Pawn(sf::Vector2i(5,6),window,'b');
    pawn7=new Pawn(sf::Vector2i(6,6),window,'b');
    pawn8=new Pawn(sf::Vector2i(7,6),window,'b');
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
void Player2::SetName(std::string name)
{
    this->name=name;
}
std::string Player2::GetName()
{
    return name;
}
void Player2::AddPoint(unsigned int a)
{
    point+=a;
}
unsigned int Player2::GetPoint()
{
    return point;
}
void Player2::AddNPoint(int a)
{
    negativepoint+=a;
}
short int Player2::GetNPoint()
{
    return negativepoint;
}
Player2::~Player2()
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
std::vector <Chessman *>&Player2::getPieces()
{
    return pieces;
}
