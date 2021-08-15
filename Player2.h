#ifndef PLAYER2_H
#define PLAYER2_H
#include <string>
#include <vector>
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
class Player2
{
    private:
        int point;//posetive point of player
        short int negativepoint;//negative point of player
        sf::RenderWindow * window;

    public:
        Player2(sf::RenderWindow*);
        void AddPoint(unsigned int);
        int GetPoint();
        void AddNPoint(int);
        short int GetNPoint();
        std::string lastmove;
        ///////////
        Queen * queen;
        King * king;
        Rook * rook1;
        Rook * rook2;
        Knight * knight1;
        Knight * knight2;
        Bishop * bishop1;
        Bishop *bishop2;
        Pawn * pawn1;
        Pawn * pawn2;
        Pawn * pawn3;
        Pawn * pawn4;
        Pawn * pawn5;
        Pawn * pawn6;
        Pawn * pawn7;
        Pawn * pawn8;
        ///////////
        std::vector <std::string>stack;
        std::vector <Chessman*> graveyard;
     // std::vector <Chessman *>pieces;
        ~Player2();
};



#endif





///////////////////////////////////////////////////////////////////////