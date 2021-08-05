#ifndef Chessman_H
#define Chessman_H
#include <iostream>
#include <string>
struct pos{
    int x;
    int y;
};
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
        virtual bool AreSquaresLegal(int a,int  b,int c,int  d) = 0;
        void SetParameter(int,int,char);
        bool GetInGame();
        void SetInGame(bool);
        char GetNamad();
        char GetColor();
        int GetPoint();
        int GetWarn();
        unsigned int x;
        unsigned int y;
};
#endif /*Chessman*/
