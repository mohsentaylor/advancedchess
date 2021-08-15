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
        std::string name;
        unsigned int point;
        short int negativepoint;
        sf::RenderWindow * window;
        std::vector<Chessman*>& getPieces();

    public:
        Player2(sf::RenderWindow*);
        void SetName(std::string);
        std::string GetName();
        void AddPoint(unsigned int);
        unsigned int GetPoint();
        void AddNPoint(int);
        short int GetNPoint();
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
        std::vector <std::string>stack;
        std::vector <Chessman*> graveyard;
        std::vector <Chessman *>pieces;
        ~Player2();
};



#endif




