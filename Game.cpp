#include "Game.h"
Game::Game(std::string name)
{
    gamename=name;
    std::string pl1,pl2;
    std::cout<<"enter 1th player name:";
    getline(std::cin,pl1);
    std::cout<<"enter 2th player name:";
    getline(std::cin,pl2);
    GameBoard.SetPlNames(pl1,pl2);
}
bool IsGameOver() {
    // Check that the current player can move
    // If not, we have a stalemate or checkmate
    bool bCanMove(false);
    bCanMove = GameBoard.CanMove(mcPlayerTurn);
    if (!bCanMove) {
        if (mqGameBoard.IsInCheck(mcPlayerTurn)) {
            AlternateTurn();
            std::cout << "Checkmate, " << mcPlayerTurn << " Wins!" << std::endl;
        } else {
            std::cout << "Stalemate!" << std::endl;
        }
    }
    return !bCanMove;
}
void Start()
{
        do {
            GetNextMove(GameBoard.paaBoard);
            AlternateTurn();
        } while (!IsGameOver());
        mqGameBoard.Print();
}
void AlternateTurn() {
        mcPlayerTurn = (mcPlayerTurn == 'W') ? 'B' : 'W';
    }
Game::~Game()
{
}
