#ifndef Chessman_H
#define Chessman_H

#include <iostream>
#include <string>

class Chessman
{
    protected:
        char color;
        char namad;
        bool InGame=true;
        int point;
        int warn;
        virtual bool AreSquaresLegal(int a,int  b,int c,int  d,Chessman * cellsBoard[8][8]) = 0;
    public:
        Chessman(int,int,char);
        Chessman();
        ~Chessman();
        void SetParameter(int,int,char);
        bool GetInGame();
        void SetInGame(bool);
        char GetNamad();
        char GetColor();
        int GetPoint();
        int GetWarn();
        bool IsLegalMove(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, Chessman* qpaaBoard[8][8]);
        unsigned int x;
        unsigned int y;
};
#endif /*Chessman*/
