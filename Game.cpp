#include "Game.h"
Game::Game(sf::RenderWindow * window)
{
    this->window=window;
    GameBoard=new ChessBoard(window);
    SetName(GetInput());
    pl1=GetInput();
    pl2=GetInput();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Game::SetName(std::string name)
{
     gamename=name;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string Game::GetName()
{
    return gamename;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string Game::GetInput()
{
    std::string str;
    sf::RenderWindow window1({ 640 ,480 }, "enter name of game");
    //based on  count title of each window will change and will called
    if(count==1)
    {
        window1.setTitle("enter name of player1");
    }
    if(count==2)
    {
       window1.setTitle("enter name of player2");
    }
    count++;
    sf::Font font;
    font.loadFromFile("London.ttf");
    sf::Text text("", font);
    while (window1.isOpen())
    {
       sf::Event event;
       while (window1.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
           {
               window1.close();
           }
           if (event.type == sf::Event::TextEntered)
           {
               // Handle ASCII characters only
               if (event.text.unicode < 128)
               {
                   str += static_cast<char>(event.text.unicode);
                   text.setString(str);
               }
           }
       }
       window1.clear();
       window1.draw(text);
       window1.display();
   }
    return str;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Game::~Game()
{
    delete GameBoard;
}
///////////////////////////////////////////////////////////////////////