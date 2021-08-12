#ifndef Chessman_H
#define Chessman_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Cell.h"
class Chessman
{
    protected:
        char color;//color of pieces
        char namad;//symbol of any pieces
        bool InGame=true;//showing that is this piece alive or not
        int point;//point for enemy for get  beated
        int warn;//point for enmey for make this piece in dangerous mode
        sf::Texture texture;
        sf::RenderWindow* window;
        sf::Sprite TextureSprite;

    public:
        Chessman(sf::Vector2i,sf::RenderWindow* ,char);
        Chessman();
        ~Chessman();
        sf::Vector2i PosOnGrid;
        bool IsLegalMove(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, Cell* [8][8]);//can go that point(is that place empty or enemy)
        virtual bool AreSquaresLegal(int a,int  b,int c,int  d ,Cell* [8][8]) = 0;//based on types of pieces
        //void SetParameter(int a,int,char);
        bool GetInGame();
        void SetInGame(bool);
        char GetNamad();
        char GetColor();
        int GetPoint();
        int GetWarn();
        bool DidMove;//is this piece move or not
        virtual void draw();
        virtual sf::Sprite& GetTextureSprite();
        sf::Vector2i GetPosOnGrid() ;
};
#endif /*Chessman*/
