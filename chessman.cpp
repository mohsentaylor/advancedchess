#include "chessman.h"
Chessman::Chessman(int x,int y,char color)
{
    this->x=x;
    this->y=y;
    this->color=color;
}
bool Chessman::IsLegalMove(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, Cell* qpaaBoard[8][8]) {
    Cell* qpDest = qpaaBoard[iDestRow][iDestCol];
    if ((qpDest == 0) || (color != qpDest->ptr->GetColor()))
    {
        return AreSquaresLegal(iSrcRow, iSrcCol, iDestRow, iDestCol, qpaaBoard);
    }
    return false;
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
