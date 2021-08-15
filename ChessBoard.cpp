#include <iostream>
#include <string>
#include "ChessBoard.h"

ChessBoard::ChessBoard(sf::RenderWindow * window)
{
    fnt.loadFromFile("London.ttf");
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    pl1pos.setFont(fnt);
    pl1pos.setFillColor(sf::Color::Blue);
    pl1pos.setPosition(1600,250);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    pl1neg.setFont(fnt);
    pl1neg.setFillColor(sf::Color::Blue);
    pl1neg.setPosition(1600,350);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    pl2pos.setFont(fnt);
    pl2pos.setFillColor(sf::Color::Red);
    pl2pos.setPosition(1600,450);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    pl2neg.setFont(fnt);
    pl2neg.setFillColor(sf::Color::Red);
    pl2neg.setPosition(1600,550);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Image image;
    if (!(image.loadFromFile("gamepics/ChessBoard.jpg")))
    {
        std::cout << "Cannot ChessBoard.jpg image";   //Load Image
    }
    boardtxt.loadFromImage(image);  //Load Texture from image
    boardsprite.setTexture(boardtxt);
    boardsprite.setScale(0.65f,0.65f);
    boardsprite.setPosition(600,100);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    this->window=window;
    pl1=new Player1(this->window);
    pl2=new Player2(this->window);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    for (int i=0; i<8 ; i++)
    {
        for (int j=0;j<8; j++)
        {
            cells[i][j] = new Cell();
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //set pl1 nuts
    cells[4][0]->SetNut(pl1->queen);
    cells[3][0]->SetNut(pl1->king);
    cells[0][0]->SetNut(pl1->rook1);
    cells[7][0]->SetNut(pl1->rook2);
    cells[1][0]->SetNut(pl1->knight1);
    cells[6][0]->SetNut(pl1->knight2);
    cells[2][0]->SetNut(pl1->bishop1);
    cells[5][0]->SetNut(pl1->bishop2);
    cells[0][1]->SetNut(pl1->pawn1);
    cells[1][1]->SetNut(pl1->pawn2);
    cells[2][1]->SetNut(pl1->pawn3);
    cells[3][1]->SetNut(pl1->pawn4);
    cells[4][1]->SetNut(pl1->pawn5);
    cells[5][1]->SetNut(pl1->pawn6);
    cells[6][1]->SetNut(pl1->pawn7);
    cells[7][1]->SetNut(pl1->pawn8);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //set pl2 nuts
    cells[4][7]->SetNut(pl2->queen);
    cells[3][7]->SetNut(pl2->king);
    cells[0][7]->SetNut(pl2->rook1);
    cells[7][7]->SetNut(pl2->rook2);
    cells[1][7]->SetNut(pl2->knight1);
    cells[6][7]->SetNut(pl2->knight2);
    cells[2][7]->SetNut(pl2->bishop1);
    cells[5][7]->SetNut(pl2->bishop2);
    cells[0][6]->SetNut(pl2->pawn1);
    cells[1][6]->SetNut(pl2->pawn2);
    cells[2][6]->SetNut(pl2->pawn3);
    cells[3][6]->SetNut(pl2->pawn4);
    cells[4][6]->SetNut(pl2->pawn5);
    cells[5][6]->SetNut(pl2->pawn6);
    cells[6][6]->SetNut(pl2->pawn7);
    cells[7][6]->SetNut(pl2->pawn8);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ChessBoard::ChangeTurn()
{
   plturn = (plturn == 'w') ? 'b' : 'w';
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string ChessBoard::switchname(std::string s)
{
    x[0]=s[0];
    x[1]=s[3];
    x[2]=s[4];
    x[3]=s[1];
    x[4]=s[2];
    return x;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ChessBoard::Moveit(int a,int b,int c, int d)
{
    cells[c][d]->SetNut(cells[a][b]->ptr);
    cells[c][d]->ptr->PosOnGrid = sf::Vector2i(c, d);
//    if(KingCheck(plturn))
//    {
//        if(IsAttack)
//        {
//            cells[a][b]->SetNut(cells[c][d]->ptr);
//            cells[a][b]->ptr->PosOnGrid = sf::Vector2i(a,b);
//            if(cells[c][d]->ptr->GetColor()=='w')
//            {
//                pl2->AddPoint(-cells[c][d]->ptr->GetPoint());
//                cells[c][d]->SetNut(pl1->graveyard.back());
//                pl1->graveyard.pop_back();
//                cells[c][d]->ptr->PosOnGrid = sf::Vector2i(c,d);
//                cells[c][d]->ptr->SetInGame(true);
//            }
//            else if(cells[c][d]->ptr->GetColor()=='b')
//            {
//                pl1->AddPoint(-cells[c][d]->ptr->GetPoint());
//                pl2->graveyard.push_back(cells[c][d]->ptr);
//                cells[c][d]->SetNut(pl2->graveyard.back());
//                pl2->graveyard.pop_back();
//                cells[c][d]->ptr->PosOnGrid = sf::Vector2i(c,d);
//                cells[c][d]->ptr->SetInGame(true);
//            }

//        }
//        else
//        {
//            cells[a][b]->SetNut(cells[c][d]->ptr);
//            cells[a][b]->ptr->PosOnGrid = sf::Vector2i(a,b);
//            cells[c][d]->SetNut(nullptr);
//        }
//        throw std::runtime_error("u cant move like this cuz your king will be under danger");
//    }
    cells[a][b]->ptr=nullptr;
    if(cells[c][d]->ptr->GetNamad()=='P')
    {
        if(cells[c][d]->ptr->GetColor()=='w')
        {
            if(d==4)
            {
                pl1->AddPoint(3);
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
                pl2->AddPoint(3);
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
                 if(cells[c][d]->ptr->GetColor()=='w'&&!cells[i][j]->IsEmpty())
                 {
                     if(cells[i][j]->ptr->GetColor()=='b')
                     {
                         pl1->AddPoint(cells[i][j]->ptr->GetWarn());
                     }
                 }
                 else if(cells[c][d]->ptr->GetColor()=='b'&&!cells[i][j]->IsEmpty())
                 {
                     if(cells[i][j]->ptr->GetColor()=='w')
                     {
                         pl2->AddPoint(cells[i][j]->ptr->GetWarn());
                     }
                 }
            }
        }
    }
//    if(Twomovement)
//    {
//        if(plturn == 'w')
//        {
//            pl1->AddNPoint(-30);
//        }
//        else
//        {
//            pl2->AddNPoint(-30);
//        }
//    }
//    else
//    {
//        ChangeTurn();
//    }
    if(pl1->GetNPoint()<-15)
    {
        throw std::runtime_error("pl1 has so much negetive point");
        pl1->AddNPoint(+15);
    }
    if(pl2->GetNPoint()<-15)
    {
        throw std::runtime_error("pl1 has so much negetive point");
        pl2->AddNPoint(+15);
    }
    ChangeTurn();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ChessBoard::attack(int a, int b, int c, int d)
{
    // not killing king
    if(cells[c][d]->ptr->GetNamad()=='K')
    {
        throw std::runtime_error("you cant kill the king :)");
    }
    //calculate points of killing and add to player
    if(cells[c][d]->ptr->GetColor()=='w')
    {
        pl2->AddPoint(cells[c][d]->ptr->GetPoint());
        pl1->graveyard.push_back(cells[c][d]->ptr);
    }
    else
    {
        pl1->AddPoint(cells[c][d]->ptr->GetPoint());
        pl2->graveyard.push_back(cells[c][d]->ptr);
    }
    //take peice to the out of gameboard
    cells[c][d]->ptr->SetInGame(false);
    cells[c][d]->ptr=nullptr;
    Moveit(a,b,c,d);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ChessBoard::KingCheck(char cColor)
{
    // Find the king
    int iKingRow;
    int iKingCol;
    for (int iRow = 0; iRow < 8; ++iRow)
    {
        for (int iCol = 0; iCol < 8; ++iCol)
        {
            if (!cells[iRow][iCol]->IsEmpty())
            {
                if (cells[iRow][iCol]->ptr->GetColor() == cColor)
                {
                    if (cells[iRow][iCol]->ptr->GetNamad() == 'K')
                    {
                        iKingRow = iRow;
                        iKingCol = iCol;
                    }
                }
            }
        }
    }
    // Run through the opponent's pieces and see if any can take the king
    for (int iRow = 0; iRow < 8; ++iRow)
    {
        for (int iCol = 0; iCol < 8; ++iCol)
        {
            if (!cells[iRow][iCol]->IsEmpty()) {
                if (cells[iRow][iCol]->ptr->GetColor() != cColor)
                {
                    if (cells[iRow][iCol]->ptr->AreSquaresLegal(iRow, iCol, iKingRow, iKingCol,cells))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ChessBoard::GameOver()
{
    // Run through all pieces
    for (int iRow = 0; iRow < 8; ++iRow)
    {
        for (int iCol = 0; iCol < 8; ++iCol)
        {
            // If it is a piece of the current player, see if it has a legal move
            if(!cells[iRow][iCol]->IsEmpty())
            {
                if (cells[iRow][iCol]->ptr->GetColor() == plturn )
                {
                    for (int iMoveRow = 0; iMoveRow < 8; ++iMoveRow)
                    {
                        for (int iMoveCol = 0; iMoveCol < 8; ++iMoveCol)
                        {
                            if (cells[iRow][iCol]->ptr->IsLegalMove(iRow, iCol, iMoveRow, iMoveCol, cells))
                            {
                                // Make move and check whether king is in check
                                Chessman* qpTemp=(cells[iMoveRow][iMoveCol]->ptr) ;
                                sf::Vector2i x=cells[iMoveRow][iMoveCol]->ptr->PosOnGrid;
                                cells[iMoveRow][iMoveCol]->SetNut(cells[iRow][iCol]->ptr);
                                cells[iMoveRow][iMoveCol]->ptr->PosOnGrid=cells[iRow][iCol]->ptr->PosOnGrid;
                                cells[iRow][iCol]->ptr = nullptr;

                                bool bCanMove = !KingCheck(plturn);
                                // Undo the move
                                cells[iRow][iCol]->SetNut(cells[iMoveRow][iMoveCol]->ptr);
                                cells[iRow][iCol]->ptr->PosOnGrid=cells[iMoveRow][iMoveCol]->ptr->PosOnGrid;
                                cells[iMoveRow][iMoveCol]->SetNut(qpTemp);
                                cells[iMoveRow][iMoveCol]->ptr->PosOnGrid=x;
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
    }
    if(plturn=='w')
    {
        pl2->AddPoint(70);
    }
    else
    {
        pl1->AddPoint(70);
    }
    return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ChessBoard::movePiece(std::string move)
{
    if(plturn=='w')
    {
        if(move==pl1->lastmove)
        {
            pl1->AddNPoint(-1);
        }
        pl1->lastmove=switchname(move);
    }
    else if(plturn=='b')
    {
        if(move==pl2->lastmove)
        {
            pl2->AddNPoint(-1);
        }
                pl2->lastmove=switchname(move);
    }

    int a,b,c,d;
    b=int(move[2])-'0';
    b=fabs(b-9);
    d=int(move[4])-'0';
    d=fabs(d-9);
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
    a--;
    b--;
    c--;
    d--;
    if(move=="Kd1a1")
    {
        if(!(cells[a][b]->ptr->DidMove)&&(cells[c][d]->ptr->DidMove))
        {
            if((cells[1][7]->IsEmpty())&&(cells[2][7]->IsEmpty()))
            {
                if(cells[c][d]->ptr->GetNamad()=='R')
                {
                    Moveit(a,b,c,d-1);
                    Moveit(c,d,a,b-1);
                    ChangeTurn();
                    return;

                }
            }
        }
    }
    if(move=="Kd1h1")
    {
        if(!(cells[a][b]->ptr->DidMove)&&(cells[c][d]->ptr->DidMove))
        {
            if(((cells[4][7]->IsEmpty())&&(cells[5][7]->IsEmpty()))&&cells[6][7]->IsEmpty())
            {
                if(cells[c][d]->ptr->GetNamad()=='R')
                {
                    Moveit(a,b,c,d-1);
                    Moveit(c,d,a,b-2);
                    ChangeTurn();
                    return;
                }
            }
        }
    }
    if(move=="Kd8a8")
    {
        if(!(cells[a][b]->ptr->DidMove)&&(cells[c][d]->ptr->DidMove))
        {
            if((cells[1][0]->IsEmpty())&&(cells[2][0]->IsEmpty()))
            {
                if(cells[c][d]->ptr->GetNamad()=='R')
                {
                    Moveit(a,b,c,d-1);
                    Moveit(c,d,a,b-1);
                    ChangeTurn();
                    return;
                }
            }
        }
    }
    if(move=="Kd8h8")
    {
        if(!(cells[a][b]->ptr->DidMove)&&(cells[c][d]->ptr->DidMove))
        {
            if(((cells[4][7]->IsEmpty())&&(cells[5][7]->IsEmpty()))&&cells[6][7]->IsEmpty())
            {
                if(cells[c][d]->ptr->GetNamad()=='R')
                {
                    Moveit(a,b,c,d-1);
                    Moveit(c,d,a,b-2);
                    ChangeTurn();
                    return;
                }
            }
        }
    }
    if(cells[a][b]->ptr->AreSquaresLegal(a,b,c,d,cells))
    {
        if(plturn=='w')
        {
            if(IsAttack)
            {
                attack(a,b,c,d);
            }
            else
            {
                Moveit(a,b,c,d);
            }
            pl1->stack.push_back(switchname(move));
            if(KingCheck('w'))
            {
                throw std::runtime_error(" white king is in danger");
            }
        }
        else if(plturn=='b')
        {
            if(IsAttack)
            {
                attack(a,b,c,d);
            }
            else
            {
                Moveit(a,b,c,d);
            }
            pl2->stack.push_back(switchname(move));
            if(KingCheck('b'))
            {
                throw std::runtime_error(" black king is in danger");
            }
        }
    }
    else
    {
        throw std::runtime_error("invalid movement");
    }
//    if(GameOver())
//    {
//        sf::Text endgame;
//        endgame.setFont(fnt);
//        endgame.setFillColor(sf::Color::Yellow);
//        endgame.setPosition(600,50);
//        if(pl1->GetPoint()>pl2->GetPoint())
//        {
//            endgame.setString(pl1->GetName()+"won with"+std::to_string(pl1->GetPoint())+"point");
//        }
//        if(pl2->GetPoint()>pl1->GetPoint())
//        {
//            endgame.setString(pl2->GetName()+"won with"+std::to_string(pl2->GetPoint())+"point");
//        }
//        window->draw(endgame);
//    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ChessBoard::transformator(sf::Vector2f pos1,sf::Vector2f pos2)
{
    char a=0;
    char b=0;
    char c=0;
    char d=0;
    char e=0;
    bool find2=false;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (cells[i][j]->ptr != nullptr && cells[i][j]->ptr->GetTextureSprite().getGlobalBounds().contains(pos1))
            {
                find2=true;
                if(cells[i][j]->ptr->GetColor()==plturn)
                {
                    a=cells[i][j]->ptr->GetNamad();
                    std::cout << "a: " << a << std::endl;
                    c=(char)fabs((j+1)-9) + '0';
                    switch (i+1)
                    {
                        case 1:
                            b='a';
                            break;
                        case 2:
                            b='b';
                            break;
                        case 3:
                            b='c';
                            break;
                        case 4:
                            b='d';
                            break;
                        case 5:
                            b='e';
                            break;
                        case 6:
                            b='f';
                            break;
                        case 7:
                            b='g';
                            break;
                        case 8:
                            b='h';
                            break;
                        default:
                            throw std::runtime_error("cant switch case in transformator in pos1");
                            break;
                    }
                }
                else
                {
                    throw std::runtime_error("not your turn in transformator");
                }

            }
        }
    }
    if(!find2)
    {
        throw std::runtime_error("not choose a piece in first pos in transformator");
    }
    //////////////////////////////////////////////////////////////////////////////////////////////
    bool find=false;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (cells[i][j]->ptr != nullptr && cells[i][j]->ptr->GetTextureSprite().getGlobalBounds().contains(pos2))
            {
                find=true;
                if(cells[i][j]->ptr->GetColor()!=plturn)
                {
                    e=(char)fabs((j+1)-9)+'0';
                    switch (i+1)
                    {
                        case 1:
                            d='a';
                            break;
                        case 2:
                            d='b';
                            break;
                        case 3:
                            d='c';
                            break;
                        case 4:
                            d='d';
                            break;
                        case 5:
                            d='e';
                            break;
                        case 6:
                            d='f';
                            break;
                        case 7:
                            d='g';
                            break;
                        case 8:
                            d='h';
                            break;
                        default:
                            throw std::runtime_error("cant switch case in transformator in pos2");
                            break;
                    }
                }
                else
                {
                    throw std::runtime_error("its same color in transparent in pos2");
                }

            }
        }
    }
    int x=0,y=0;
    if(!find)
    {
        for (int i = 0; i < 8; i++)
        {
            if (((float)(i*(125)*(0.675)+600))<pos2.x)
            {
                if (((float)((i+2)*(125)*(0.675)+600))>pos2.x)
                {
                    x=i+1;
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            if (((float)(i*(125)*(0.675)+100))<pos2.y)
            {
                if (((float)((i+2)*(125)*(0.675)+100))>pos2.y)
                {
                    y=i+1;
                }
            }
        }
        e=(char)fabs((y)-9)+'0';
        switch (x)
        {
            case 1:
                d='a';
                break;
            case 2:
                d='b';
                break;
            case 3:
                d='c';
                break;
            case 4:
                d='d';
                break;
            case 5:
                d='e';
                break;
            case 6:
                d='f';
                break;
            case 7:
                d='g';
                break;
            case 8:
                d='h';
                break;
            default:
                throw std::runtime_error("cant switch case in transformator in pos2");
                break;
        }

    }
    char* concattedString;
    sprintf(concattedString, "%c%c%c%c%c", a, b, c, d, e);
    std::string name22(concattedString);
    movePiece(name22);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ChessBoard::CheckIsPiece(sf::Vector2f pos)
{
    int x,y;
    //find i in cells[i][j](width)
    for (int i = 0; i < 8; i++)
    {
        if (((float)(i*(125)*(0.675)+600))<pos.x)
        {
            if (((float)((i+2)*(125)*(0.675)+600))>pos.x)
            {
                x=i;
            }
        }
    }
    //find j in cells[i][j](length)
    for (int i = 0; i < 8; i++)
    {
        if (((float)(i*(125)*(0.675)+100))<pos.y)
        {
            if (((float)((i+2)*(125)*(0.675)+100))>pos.y)
            {
                y=i;
            }
        }
    }
    if (!cells[x][y]->IsEmpty())
    {
        return true;
    }
    return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ChessBoard::draw()
{
    //drawing pieces that exist in the game(not killed)
    boardsprite.setTexture(boardtxt);
    boardsprite.setScale(0.65f,0.65f);
    boardsprite.setPosition(600,100);
    window->draw(boardsprite);
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(!cells[i][j]->IsEmpty())
            {
                 cells[i][j]->ptr->draw();
            }
        }
    }
    //drawing + and - points of two players
    pl1pos.setString("                  "+std::to_string(pl1->GetPoint()));
    pl1neg.setString("                  "+std::to_string(pl1->GetNPoint()));
    pl2pos.setString("                  "+std::to_string( pl2->GetPoint()));
    pl2neg.setString("                  "+std::to_string( pl2->GetNPoint()));
    window->draw(pl1pos);
    window->draw(pl1neg);
    window->draw(pl2pos);
    window->draw(pl2neg);
    //make background for dead peices
    sf::RectangleShape rectangle1;
    rectangle1.setFillColor(sf::Color::Black);
    rectangle1.setSize(sf::Vector2f(1270,85));
    rectangle1.setPosition(600,777);
    window->draw(rectangle1);
    ///////////////////////////////////////////////////////////////////////////////////////
    sf::RectangleShape rectangle2;
    rectangle2.setFillColor(sf::Color::White);
    rectangle2.setSize(sf::Vector2f(1270,85));
    rectangle2.setPosition(600,865);
    window->draw(rectangle2);
    ////////////////////////////////////////////////////////////////////////////////////////
    if (!pl1->graveyard.empty())
    {
        for(unsigned int i=0; i<pl1->graveyard.size(); i++)
        {
            pl1->graveyard[i]->GetTextureSprite().setPosition(float((((i)*(125)*(0.675))+600)),float(775));
            window->draw(pl1->graveyard[i]->GetTextureSprite());
        }
    }
    if (!pl2->graveyard.empty())
    {
        for(unsigned int i=0; i<pl2->graveyard.size(); i++)
        {
            pl2->graveyard[i]->GetTextureSprite().setPosition(float((((i)*(125)*(0.675))+600)),float(865));
            window->draw(pl2->graveyard[i]->GetTextureSprite());
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ChessBoard::~ChessBoard()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            delete cells[i][j];
        }
    }
}
