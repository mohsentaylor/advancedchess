#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <stdexcept>
#include <Cell.cpp>
#include <Player1.cpp>
#include <Player2.cpp>
class ChessBoard
{
    private:
        Cell *cells[8][8];
        Player1 pl1;
        Player2 pl2;
        char plturn='w';
        bool IsAttack;
        bool Twomovement=false;
        void ChangeTurn();
        bool branches(int a,int b,int c,int d);
        std::string switchname(std::string);
    public:
        ChessBoard();
        void SetPlNames(std::string,std::string);
        void move(int a,int b);
        bool GameOver();
        void Moveit(int a,int b,int c,int d);
        void attack(int ,int,int,int);
        void movePiece(std::string);
        bool KingCheck(char );
        ~ChessBoard();
};
 
 
 
#endif
