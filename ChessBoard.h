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
        Cell *cells[8][8];//our board
        Player1 * pl1;
        Player2 * pl2;
        sf::Text pl1pos,pl1neg,pl2pos,pl2neg;//text for showing (pl1,pl2)with (posetive and negative)
        sf::Font fnt;
        char plturn='w';//declare every players turn
        bool Twomovement=false;//for checking that player want to move two times or not
        sf::RenderWindow * window;
        void ChangeTurn();//change the turn of players
        std::string switchname(std::string);//ke1e4->ke4e1
    public:
        ChessBoard(sf::RenderWindow *);
        std::string x="abcde";
        sf::Texture boardtxt;//texture for loading image of gameboard
        sf::Sprite boardsprite;//sprite for showing image of gameboard
        bool IsAttack;//show that player wants to attack or just move
        sf::Vector2f p1 = sf::Vector2f(0, 0), p2 = sf::Vector2f(0, 0);
        bool GameOver();//check that game is over or not
        void Moveit(int a,int b,int c,int d);//move one piece to a empty place
        void attack(int ,int,int,int);//move one piece to a full place(attack)
        void movePiece(std::string);//convert string to positions and find out that this movement is attack or just a movement
        bool KingCheck(char );//check that is king under attack or not
        void draw();//drow chessboard ,pieces , and pieces that destroyed
        void transformator(sf::Vector2f ,sf::Vector2f );//get two position and convert them to special string
        bool CheckIsPiece(sf::Vector2f);//check that is there piece on that position or not
        ~ChessBoard();
};
 
 
 
#endif

///////////////////////////////////////////////////////////////////////