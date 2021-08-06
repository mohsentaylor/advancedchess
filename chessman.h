#ifndef Chessman_H
#define Chessman_H
#include <iostream>
#include <string>
#include "Cell.h"
class Chessman
{
    protected:
        char color;
        char namad;
        bool InGame=true;
        int point;
        int warn;

    public:
        Chessman(int,int,char);
        Chessman();
        ~Chessman();
        bool IsLegalMove(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, Cell* [8][8]);
        virtual bool AreSquaresLegal(int a,int  b,int c,int  d ,Cell* [8][8]) = 0;
        void SetParameter(int,int,char);
        bool GetInGame();
        void SetInGame(bool);
        char GetNamad();
        char GetColor();
        int GetPoint();
        int GetWarn();
        bool DidMove;
        unsigned int x;
        unsigned int y;
};
#endif /*Chessman*/
