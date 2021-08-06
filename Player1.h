#ifndef PLAYER1_H
#define PLAYER1_H
#include <string>
#include <vector>
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
class Player1
{
    private:
        std::string name;
        unsigned int point=0;
        short int negativepoint=0;
    public:
        Player1();
        void SetName(std::string);
        std::string GetName();
        void AddPoint(int);
        unsigned int GetPoint();
        void AddNPoint(int);
        short int GetNPoint();
        Queen queen;
        King king;
        Rook rook1;
        Rook rook2;
        Knight knight1;
        Knight knight2;
        Bishop bishop1;
        Bishop bishop2;
        Pawn pawn1;
        Pawn pawn2;
        Pawn pawn3;
        Pawn pawn4;
        Pawn pawn5;
        Pawn pawn6;
        Pawn pawn7;
        Pawn pawn8;
        std::vector <std::string>stack;
        std::vector <Chessman*> graveyard;
        ~Player1();
};



#endif
