#include <iostream>
#include <string>
#include "ChessBoard.h"

ChessBoard::ChessBoard()
{

    //set pl1 nuts
    cells[0][4]->SetNut(&pl1.queen);
    cells[0][3]->SetNut(&pl1.king);
    cells[0][0]->SetNut(&pl1.rook1);
    cells[0][7]->SetNut(&pl1.rook2);
    cells[0][1]->SetNut(&pl1.knight1);
    cells[0][6]->SetNut(&pl1.knight2);
    cells[0][2]->SetNut(&pl1.bishop1);
    cells[0][5]->SetNut(&pl1.bishop2);
    cells[1][0]->SetNut(&pl1.pawn1);
    cells[1][1]->SetNut(&pl1.pawn2);
    cells[1][2]->SetNut(&pl1.pawn3);
    cells[1][3]->SetNut(&pl1.pawn4);
    cells[1][4]->SetNut(&pl1.pawn5);
    cells[1][5]->SetNut(&pl1.pawn6);
    cells[1][6]->SetNut(&pl1.pawn7);
    cells[1][7]->SetNut(&pl1.pawn8);
    //set pl2 nuts
    cells[7][4]->SetNut(&pl1.queen);
    cells[7][3]->SetNut(&pl1.king);
    cells[7][0]->SetNut(&pl1.rook1);
    cells[7][7]->SetNut(&pl1.rook2);
    cells[7][1]->SetNut(&pl1.knight1);
    cells[7][6]->SetNut(&pl1.knight2);
    cells[7][2]->SetNut(&pl1.bishop1);
    cells[7][5]->SetNut(&pl1.bishop2);
    cells[6][0]->SetNut(&pl1.pawn1);
    cells[6][1]->SetNut(&pl1.pawn2);
    cells[6][2]->SetNut(&pl1.pawn3);
    cells[6][3]->SetNut(&pl1.pawn4);
    cells[6][4]->SetNut(&pl1.pawn5);
    cells[6][5]->SetNut(&pl1.pawn6);
    cells[6][6]->SetNut(&pl1.pawn7);
    cells[6][7]->SetNut(&pl1.pawn8);
}
void ChessBoard::SetPlNames(std::string a,std::string b)
{
    pl1.SetName(a);
    pl2.SetName(b);
}
void ChessBoard::ChangeTurn()
{
   plturn = (plturn == 'w') ? 'b' : 'w';
}
std::string ChessBoard::switchname(std::string s)
{
    std::string x;
    x[0]=s[0];
    x[1]=s[3];
    x[2]=s[4];
    x[3]=s[1];
    x[4]=s[2];
    return x;
}
void ChessBoard::Moveit(int a,int b,int c, int d)
{

    cells[c][d]->ptr=cells[a][b]->ptr;
    cells[a][b]->ptr=0;
    if(cells[c][d]->ptr->GetNamad()=='P')
    {
        if(cells[c][d]->ptr->GetColor()=='w')
        {
            if(d==4)
            {
                pl1.AddPoint(3);
            }
            if(d==7)
            {
                  //queen or bishop or rook or knight
            }
        }
        else
        {
            if(d==3)
            {
                pl2.AddPoint(3);
            }
            if(d==0)
            {
                //queen or bishop or rook or knight
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(cells[c][d]->ptr->AreSquaresLegal(c, d, i, j,cells))
            {
                 if(cells[c][d]->ptr->GetColor()=='w')
                 {
                     pl1.AddPoint(cells[i][j]->ptr->GetWarn());
                 }
                 else
                 {
                     pl2.AddPoint(cells[i][j]->ptr->GetWarn());
                 }
            }
        }
    }
    if(Twomovement)
    {
        if(plturn == 'w')
        {
            pl1.AddNPoint(-30);
        }
        else
        {
            pl2.AddNPoint(-30);
        }
    }
    else
    {
        ChangeTurn();
    }

}
void ChessBoard::attack(int a, int b, int c, int d)
{
    if(cells[c][d]->ptr->GetColor()=='w')
    {
        pl2.AddPoint(cells[c][d]->ptr->GetPoint());
        pl1.graveyard.push_back(cells[c][d]->ptr);
    }
    else
    {
        pl1.AddPoint(cells[c][d]->ptr->GetPoint());
        pl2.graveyard.push_back(cells[c][d]->ptr);
    }
    cells[c][d]->ptr=0;
    Moveit(a,b,c,d);

}

bool ChessBoard::KingCheck(char cColor)
{
    // Find the king
    int iKingRow;
    int iKingCol;
    for (int iRow = 0; iRow < 8; ++iRow) {
        for (int iCol = 0; iCol < 8; ++iCol) {
            if (cells[iRow][iCol]->ptr!=0) {
                if (cells[iRow][iCol]->ptr->GetColor() == cColor) {
                    if (cells[iRow][iCol]->ptr->GetNamad() == 'K') {
                        iKingRow = iRow;
                        iKingCol = iCol;
                    }
                }
            }
        }
    }
    // Run through the opponent's pieces and see if any can take the king
    for (int iRow = 0; iRow < 8; ++iRow) {
        for (int iCol = 0; iCol < 8; ++iCol) {
            if (cells[iRow][iCol] != 0) {
                if (cells[iRow][iCol]->ptr->GetColor() != cColor) {
                    if (cells[iRow][iCol]->ptr->AreSquaresLegal(iRow, iCol, iKingRow, iKingCol,cells)) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}
bool ChessBoard::GameOver()
{
    // Run through all pieces
    for (int iRow = 0; iRow < 8; ++iRow)
    {
        for (int iCol = 0; iCol < 8; ++iCol)
        {
            // If it is a piece of the current player, see if it has a legal move
            if (cells[iRow][iCol]->ptr->GetColor() == plturn)
            {
                for (int iMoveRow = 0; iMoveRow < 8; ++iMoveRow)
                {
                    for (int iMoveCol = 0; iMoveCol < 8; ++iMoveCol)
                    {
                        if (cells[iRow][iCol]->ptr->IsLegalMove(iRow, iCol, iMoveRow, iMoveCol, cells))
                        {
                            // Make move and check whether king is in check
                            Chessman* qpTemp=(cells[iMoveRow][iMoveCol]->ptr) ;
                            cells[iMoveRow][iMoveCol] = cells[iRow][iCol];
                            cells[iRow][iCol] = 0;
                            bool bCanMove = !KingCheck(plturn);
                            // Undo the move
                            cells[iRow][iCol] = cells[iMoveRow][iMoveCol];
                            cells[iMoveRow][iMoveCol]->ptr = qpTemp;
                            if (bCanMove)
                            {
                                return true;
                            }
                        }
                    }
                }
            }

        }
    }
    if(plturn=='w')
    {
        pl2.AddPoint(70);
    }
    else
    {
        pl1.AddPoint(70);
    }
    return false;
}
void ChessBoard::movePiece(std::string move)
{
    int a,b,c,d;
    b=int(move[2]);
    d=int(move[4]);
    switch (move[1])
    {
        case 'a':
            a=1;
            break;
        case 'b':
            a=2;
            break;
        case 'c':
            a=3;
            break;
        case 'd':
            a=4;
            break;
        case 'e':
            a=5;
            break;
        case 'f':
            a=6;
            break;
        case 'g':
            a=7;
            break;
        case 'h':
            a=8;
            break;
    }
    switch (move[3])
    {
        case 'a':
            c=1;
            break;
        case 'b':
            c=2;
            break;
        case 'c':
            c=3;
            break;
        case 'd':
            c=4;
            break;
        case 'e':
            c=5;
            break;
        case 'f':
            c=6;
            break;
        case 'g':
            c=7;
            break;
        case 'h':
            c=8;
            break;
    }
    int s;
    s=a;
    a=b;
    b=s;
    s=c;
    c=d;
    d=s;
    if(move=="Kd1a1")
    {
        if(!(cells[a-1][b-1]->ptr->DidMove)&&(cells[c-1][d-1]->ptr->DidMove))
        {
            if(!(cells[1][7]->ptr==0)&&!(cells[2][7]->ptr==0))
            {
                if(cells[c-1][d-1]->ptr->GetNamad()=='R')
                {
                    Moveit(a-1,b-1,c-1,d-2);
                    Moveit(c-1,d-1,a-1,b-2);
                }
            }
        }
    }
    if(move=="Kd1h1")
    {
        if(!(cells[a-1][b-1]->ptr->DidMove)&&(cells[c-1][d-1]->ptr->DidMove))
        {
            if((!(cells[4][7]->ptr==0)&&!(cells[5][7]->ptr==0))&&cells[6][7]->ptr==0)
            {
                if(cells[c-1][d-1]->ptr->GetNamad()=='R')
                {
                    Moveit(a-1,b-1,c-1,d-2);
                    Moveit(c-1,d-1,a-1,b-3);
                }
            }
        }
    }
    if(move=="Kd8a8")
    {
        if(!(cells[a-1][b-1]->ptr->DidMove)&&(cells[c-1][d-1]->ptr->DidMove))
        {
            if(!(cells[1][0]->ptr==0)&&!(cells[2][0]->ptr==0))
            {
                if(cells[c-1][d-1]->ptr->GetNamad()=='R')
                {
                    Moveit(a-1,b-1,c-1,d-2);
                    Moveit(c-1,d-1,a-1,b-2);
                }
            }
        }
    }
    if(move=="Kd8h8")
    {
        if(!(cells[a-1][b-1]->ptr->DidMove)&&(cells[c-1][d-1]->ptr->DidMove))
        {
            if((!(cells[4][7]->ptr==0)&&!(cells[5][7]->ptr==0))&&cells[6][7]->ptr==0)
            {
                if(cells[c-1][d-1]->ptr->GetNamad()=='R')
                {
                    Moveit(a-1,b-1,c-1,d-2);
                    Moveit(c-1,d-1,a-1,b-3);
                }
            }
        }
    }

    if(cells[a-1][b-1]->ptr->GetColor()!=cells[c-1][d-1]->ptr->GetColor())
    {
        IsAttack=true;
    }
    else
    {
        IsAttack=false;
    }
            if(plturn=='w')
            {
                if(cells[a-1][b-1]->ptr->GetColor()=='w')
                {
                    if(!KingCheck('w'))
                    {
                        if(IsAttack)
                        {
                            attack(a-1,b-1,c-1,d-1);
                        }
                        else
                        {
                            Moveit(a-1,b-1,c-1,d-1);
                        }
                        pl1.stack.push_back(switchname(move));
                    }
                    else

                    {
                        if(IsAttack)
                        {
                            attack(a-1,b-1,c-1,d-1);
                        }
                        else
                        {
                            Moveit(a-1,b-1,c-1,d-1);
                        }
                        if(KingCheck('w'))
                        {
                            //undo();
                        }
                    }
                }
                else
                {
                    throw std::runtime_error("not your turn dude");
                }
            }
            if(plturn=='w')
            {
                if(cells[a-1][b-1]->ptr->GetColor()=='w')
                {
                    if(!KingCheck('w'))
                    {
                        if(IsAttack)
                        {
                            attack(a-1,b-1,c-1,d-1);
                        }
                        else
                        {
                            Moveit(a-1,b-1,c-1,d-1);
                        }
                        pl1.stack.push_back(switchname(move));
                    }
                    else

                    {
                        if(IsAttack)
                        {
                            attack(a-1,b-1,c-1,d-1);
                        }
                        else
                        {
                            Moveit(a-1,b-1,c-1,d-1);
                        }
                        if(KingCheck('w'))
                        {
                            //undo();
                        }
                    }
                }
                else
                {
                    throw std::runtime_error("not your turn dude");
                }
            }

}

ChessBoard::~ChessBoard()
{
}
