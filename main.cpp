#include "Game.h"
#include <iostream>
using namespace std;


int main()
{
    sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(1900, 1000), "Chess");
    sf::Texture txtbackimage;
    txtbackimage.loadFromFile("gamepics/background.jpg");
    sf::Sprite sprtbackimage;
    sprtbackimage.setTexture(txtbackimage);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Game game(window);
    sf::Image rebegin;
    if (!(rebegin.loadFromFile("gamepics/Start again.png")))
        cout << "Cannot load image";   //Load Image
    sf::Texture regn;
    regn.loadFromImage(rebegin);  //Load Texture from image
    sf::Sprite rebgn;
    rebgn.setTexture(regn);
    rebgn.setScale(0.5f, 0.5f);
    rebgn.setPosition(50, 600);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Image dispense;
        if (!(dispense.loadFromFile("gamepics/Enseraf.png")))
            cout << "cannot load image" << endl;
    sf::Texture enseraf;
    enseraf.loadFromImage(dispense);
    sf::Sprite ens;
    ens.setTexture(enseraf);
    ens.setScale(0.7f,0.5f);
    ens.setPosition(50,700);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Image Exit;
    if (!(Exit.loadFromFile("gamepics/Exit.png")))
        cout << "cannot load image" << endl;
    sf::Texture Ext;
    Ext.loadFromImage(Exit);
    sf::Sprite EXIT;
    EXIT.setTexture(Ext);
    EXIT.setScale(0.5f,0.5f);
    EXIT.setPosition(85,800);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Image Name;
    if (!(Name.loadFromFile("gamepics/name.png")))
        cout << "cannot open name image" << endl;
    sf::Texture NAME;
    NAME.loadFromImage(Name);
    sf::Sprite name;
    name.setTexture(NAME);
    name.setScale(0.5f,0.5f);
    name.setPosition(50,10);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Image Point;
    if (!(Point.loadFromFile("gamepics/point.png")))
        cout << "cannot open point image" << endl;
    sf::Texture POint;
    POint.loadFromImage(Point);
    sf::Sprite point;
    point.setTexture(POint);
    point.setScale(0.9f,0.9f);
    point.setPosition(1600,30);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Image Left;
    if (!(Left.loadFromFile("gamepics/Left.png")))
        cout << "cannot open  left image" << endl;
    sf::Texture L;
    L.loadFromImage(Left);
    sf::Sprite LEFT;
    LEFT.setTexture(L);
    LEFT.setScale(0.9f, 0.9f);
    LEFT.setPosition(200,300);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    sf::Font font;
    font.loadFromFile("London.ttf");
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    sf::Text plyr1pos,plyr1neg;
    plyr1pos.setFont(font);
    plyr1pos.setString("+ Point for " + game.pl1);
    plyr1neg.setFont(font);
    plyr1neg.setString("- Point for " + game.pl1);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    sf::Text plyr2pos,plyr2neg;
    plyr2pos.setFont(font);
    plyr2pos.setString("+ Point for " + game.pl2);
    plyr2neg.setFont(font);
    plyr2neg.setString("- Point for " + game.pl2);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    plyr1pos.setFillColor(sf::Color::Black);
    plyr2pos.setFillColor(sf::Color::Black);
    plyr1neg.setFillColor(sf::Color::Black);
    plyr2neg.setFillColor(sf::Color::Black);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    plyr1pos.setPosition(1600,200);
    plyr1neg.setPosition(1600,300);
    plyr2pos.setPosition(1600,400);
    plyr2neg.setPosition(1600,500);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Text whowins;
    whowins.setFont(font);
    whowins.setString(game.GetName());
    whowins.setFillColor(sf::Color::White);
    whowins.setPosition(50,150);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::RectangleShape textbox;
    textbox.setFillColor(sf::Color::White);
    textbox.setSize(sf::Vector2f(300,500));
    textbox.setPosition(1600,150);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    while (window->isOpen())
    {

        sf::Event event;
        while (window->pollEvent(event))
        {
            auto pos = sf::Mouse::getPosition(*window);
            if(event.type == sf::Event::Closed)
            {
                  window->close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                  window->close();
            }
            if(EXIT.getGlobalBounds().contains((static_cast<sf::Vector2f>(sf::Mouse::getPosition())))&&(event.key.code == sf::Mouse::isButtonPressed(sf::Mouse::Left)))
            {
                window->close();
            }
            if(ens.getGlobalBounds().contains((static_cast<sf::Vector2f>(sf::Mouse::getPosition())))&&(event.key.code == sf::Mouse::isButtonPressed(sf::Mouse::Left)))
            {
                window->close();
            }
            if((game.GameBoard->boardsprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))&&(event.key.code == sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
                //check that first point receved or not
                if(game.GameBoard->p1==sf::Vector2f(0,0))
                {
                    //check that is there any piece on this position
                    if(game.GameBoard->CheckIsPiece(static_cast<sf::Vector2f>(pos)))
                    {
                       game.GameBoard->p1=(static_cast<sf::Vector2f>(pos));
                    }
                }
                else
                {
                    game.GameBoard->p2=(static_cast<sf::Vector2f>(pos));
                    game.GameBoard->IsAttack=game.GameBoard->CheckIsPiece(static_cast<sf::Vector2f>(pos));
                    try
                    {
                         game.GameBoard->transformator(game.GameBoard->p1,game.GameBoard->p2);
                    }
                    catch (runtime_error &error)
                    {
                        std::cout << "Exception occurred: " <<error.what()<< std:: endl;
                    }
                    //make this points empty for next movement
                    game.GameBoard->p2=sf::Vector2f(0,0);
                    game.GameBoard->p1=sf::Vector2f(0,0);
                }
            }
        }

        window->clear();
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        window->draw(sprtbackimage);
        window->draw(textbox);
        //game board and pieces
        game.GameBoard->draw();
        /////////////////////////////////bottons//////////////////////////////////////////////////////////////////////////////////////////////////
        window->draw(rebgn);
        window->draw(ens);
        window->draw(EXIT);
        window->draw(name);
        window->draw(point);
        window->draw(LEFT);
        ///////////////////////////////////////texts///////////////////////////////////////////////////////////////////////////////
        window->draw(plyr1pos);
        window->draw(plyr1neg);
        window->draw(plyr2pos);
        window->draw(plyr2neg);
        window->draw(whowins);
        window->display();
    }
    delete window;
    return 0;
}


///////////////////////////////////////////////////////////////////////