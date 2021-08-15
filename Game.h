#ifndef GAME_H
#define GAME_H
#include "ChessBoard.h"
class Game
{
    private:
        std::string gamename;
        sf::RenderWindow * window;
    public:
        Game(sf::RenderWindow*);
        int count=0;
        std::string pl1;
        std::string pl2;
        void SetName(std::string);
        std::string GetName();
        std::string GetInput();
        ChessBoard* GameBoard;
        ~Game();
};
#endif
