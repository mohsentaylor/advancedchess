#include "chessman.h"
Chessman::Chessman(sf::Vector2i pos,sf::RenderWindow* rwindow,char color)
{
    PosOnGrid=pos;
    window=rwindow;
    this->color=color;
}
bool Chessman::IsLegalMove(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, Cell* qpaaBoard[8][8])
{
    Cell* qpDest = qpaaBoard[iDestRow][iDestCol];
    if (qpDest->IsEmpty() || (color != qpDest->ptr->GetColor()))
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
Chessman::~Chessman()
{

}

/*void Chessman::SetParameter(int a,int b,char color)
{
    PosOnGrid.x=a;
    PosOnGrid.y=b;
    this->color=color;
}*/
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
sf::Vector2i Chessman::GetPosOnGrid()
{
    return PosOnGrid;
}
sf::Sprite& Chessman::GetTextureSprite()
{
    return TextureSprite;
}
void Chessman::draw()
{
    sf::Vector2f position;
    if(InGame)
    {
        position.x=(float)((PosOnGrid.x)*(125)*(0.675))+600;
        position.y=(float)((PosOnGrid.y)*(125)*(0.675))+100;
    }
    TextureSprite.setScale(sf::Vector2f(0.65,0.65));
    TextureSprite.setPosition(position);
    window->draw(TextureSprite);
}
