#include "Player2.h"
#include <string>
Player2::Player2()
{
    queen.SetParameter(7,4,'b');
    king.SetParameter(7,3,'b');
    rook1.SetParameter(7,0,'b');
    rook2.SetParameter(7,7,'b');
    knight1.SetParameter(7,1,'b');
    knight2.SetParameter(7,6,'b');
    bishop1.SetParameter(7,2,'b');
    bishop2.SetParameter(7,5,'b');
    pawn1.SetParameter(6,0,'b');
    pawn2.SetParameter(6,1,'b');
    pawn3.SetParameter(6,2,'b');
    pawn4.SetParameter(6,3,'b');
    pawn5.SetParameter(6,4,'b');
    pawn6.SetParameter(6,5,'b');
    pawn7.SetParameter(6,6,'b');
    pawn8.SetParameter(6,7,'b');
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
}
