#include "chessman.h"
Chessman::Chessman(int x,int y,char color)
{
    this->x=x;
    this->y=y;
    this->color=color;
}

Chessman::Chessman() {

}
bool Chessman::GetInGame()
{
    return InGame;
}
void Chessman::SetInGame(bool x)
{
    InGame=x;
}
Chessman::~Chessman() {

}

void Chessman::SetParameter(int x,int y,char color)
{
    this->x=x;
    this->y=y;
    this->color=color;
}
char Chessman::GetNamad()
{
    return namad;
}
char Chessman::GetColor()
{
    return color;
}
int Chessman::GetPoint()
{
    return point;
}
int Chessman::GetWarn()
{
    return warn;
}
