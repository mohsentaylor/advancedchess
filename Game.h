#ifndef GAME_H
#define GAME_H
#include "ChessBoard.h"
class Game
{
    private:
        ChessBoard GameBoard;
        std::string gamename;
    public:
    Game(std::string);
    ~Game();
    void Start();
    void GetNextMove(Chessman* qpaaBoard[8][8]) {
        using namespace std;
        bool bValidMove	= false;
        do {
            mqGameBoard.Print();

            // Get input and convert to coordinates
            cout << mcPlayerTurn << "'s Move: ";
            int iStartMove;
            cin >> iStartMove;
            int iStartRow = (iStartMove / 10) - 1;
            int iStartCol = (iStartMove % 10) - 1;

            cout << "To: ";
            int iEndMove;
            cin >> iEndMove;
            int iEndRow = (iEndMove / 10) - 1;
            int iEndCol = (iEndMove % 10) - 1;

            // Check that the indices are in range
            // and that the source and destination are different
            if ((iStartRow >= 0 && iStartRow <= 7) &&
                (iStartCol >= 0 && iStartCol <= 7) &&
                (iEndRow >= 0 && iEndRow <= 7) &&
                (iEndCol >= 0 && iEndCol <= 7)) {
                // Additional checks in here
                CAPiece* qpCurrPiece = qpaaBoard[iStartRow][iStartCol];
                // Check that the piece is the correct color
                if ((qpCurrPiece != 0) && (qpCurrPiece->GetColor() == mcPlayerTurn)) {
                    // Check that the destination is a valid destination
                    if (qpCurrPiece->IsLegalMove(iStartRow, iStartCol, iEndRow, iEndCol, qpaaBoard)) {
                        // Make the move
                        CAPiece* qpTemp					= qpaaBoard[iEndRow][iEndCol];
                        qpaaBoard[iEndRow][iEndCol]		= qpaaBoard[iStartRow][iStartCol];
                        qpaaBoard[iStartRow][iStartCol]	= 0;
                        // Make sure that the current player is not in check
                        if (!mqGameBoard.IsInCheck(mcPlayerTurn)) {
                            delete qpTemp;
                            bValidMove = true;
                        } else { // Undo the last move
                            qpaaBoard[iStartRow][iStartCol] = qpaaBoard[iEndRow][iEndCol];
                            qpaaBoard[iEndRow][iEndCol]		= qpTemp;
                        }
                    }
                }
            }
            if (!bValidMove) {
                cout << "Invalid Move!" << endl;
            }
        } while (!bValidMove);
    }

    void AlternateTurn();
    bool IsGameOver();
};



#endif
