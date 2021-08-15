#ifndef GAME_H
#define GAME_H
#include "ChessBoard.h"
class Game
{
    private:
        std::string gamename;//name of game
        sf::RenderWindow * window;
    public:
        Game(sf::RenderWindow*);
        int count=0;//counted
        std::string pl1;//name of player 1
        std::string pl2;//name of player 2
        void SetName(std::string);//seting name of game
        std::string GetName();
        std::string GetInput();//******getting input for game names(gamename,playername1,playername2)//
        ChessBoard* GameBoard;//board of game
        ~Game();
};
#endif
