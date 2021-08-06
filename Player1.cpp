#include "Player1.h"
#include <string>
Player1::Player1()
{
    queen.SetParameter(0,4,'w');
    king.SetParameter(0,3,'w');
    rook1.SetParameter(0,0,'w');
    rook2.SetParameter(0,7,'w');
    knight1.SetParameter(0,1,'w');
    knight2.SetParameter(0,6,'w');
    bishop1.SetParameter(0,2,'w');
    bishop2.SetParameter(0,5,'w');
    pawn1.SetParameter(1,0,'w');
    pawn2.SetParameter(1,1,'w');
    pawn3.SetParameter(1,2,'w');
    pawn4.SetParameter(1,3,'w');
    pawn5.SetParameter(1,4,'w');
    pawn6.SetParameter(1,5,'w');
    pawn7.SetParameter(1,6,'w');
    pawn8.SetParameter(1,7,'w');
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
}
