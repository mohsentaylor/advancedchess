#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <stdexcept>
#include <Cell.h>
#include <Player1.h>
#include <Player2.h>
#include <math.h>
class ChessBoard
{
    private:
        Cell *cells[8][8];
        Player1 * pl1;
        Player2 * pl2;
        sf::Text pl1pos,pl1neg,pl2pos,pl2neg;
        sf::Font fnt;
        char plturn='w';
        bool Twomovement=false;
        sf::RenderWindow * window;
        void ChangeTurn();
       // bool branches(int a,int b,int c,int d);
        std::string switchname(std::string);//ke1e4->ke4e1
    public:
        ChessBoard(sf::RenderWindow *);
        sf::Texture boardtxt;
        sf::Sprite boardsprite;
        bool IsAttack;
        sf::Vector2f p1 = sf::Vector2f(0, 0), p2 = sf::Vector2f(0, 0);
        void SetPlNames(std::string,std::string);
        void move(int a,int b);
        bool GameOver();
        void Moveit(int a,int b,int c,int d);
        void attack(int ,int,int,int);
        void movePiece(std::string);
        bool KingCheck(char );
        void draw();
        void transformator(sf::Vector2f ,sf::Vector2f pos2);
        bool CheckIsPiece(sf::Vector2f);
        ~ChessBoard();
};
 
 
 
#endif
