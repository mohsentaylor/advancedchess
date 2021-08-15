#include "Game.h"
#include <iostream>
using namespace std;


int main()
{



    sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(1900, 1000), "Chess");
    Game game(window);
    sf::Image rebegin;
    if (!(rebegin.loadFromFile("gamepics/Start again.png")))
        cout << "Cannot load image";   //Load Image

    sf::Texture rgn;
    rgn.loadFromImage(rebegin);  //Load Texture from image

    sf::Sprite rebgn;
    rebgn.setTexture(rgn);
    rebgn.setScale(0.5f, 0.5f);
    rebgn.setPosition(50, 600);

    sf::Image dispense;
        if (!(dispense.loadFromFile("gamepics/Enseraf.png")))
            cout << "cannot load image" << endl;
    sf::Texture enseraf;
    enseraf.loadFromImage(dispense);
    sf::Sprite ens;
    ens.setTexture(enseraf);
    ens.setScale(0.7f,0.5f);
    ens.setPosition(50,700);

    sf::Image Exit;
    if (!(Exit.loadFromFile("gamepics/Exit.png")))
        cout << "cannot load image" << endl;
    sf::Texture Ext;
    Ext.loadFromImage(Exit);
    sf::Sprite EXIT;
    EXIT.setTexture(Ext);
    EXIT.setScale(0.5f,0.5f);
    EXIT.setPosition(85,800);

    sf::Image Name;
    if (!(Name.loadFromFile("gamepics/name.png")))
        cout << "cannot open name image" << endl;
    sf::Texture NAME;
    NAME.loadFromImage(Name);
    sf::Sprite name;
    name.setTexture(NAME);
    name.setScale(0.5f,0.5f);
    name.setPosition(50,10);
    sf::Image Point;
    if (!(Point.loadFromFile("gamepics/point.png")))
        cout << "cannot open point image" << endl;
    sf::Texture POint;
    POint.loadFromImage(Point);
    sf::Sprite P;
    P.setTexture(POint);
    P.setScale(0.9f,0.9f);
    P.setPosition(1600,30);

    sf::Image Left;
    if (!(Left.loadFromFile("gamepics/Left.png")))
        cout << "cannot open  left image" << endl;
    sf::Texture L;
    L.loadFromImage(Left);
    sf::Sprite LEFT;
    LEFT.setTexture(L);
    LEFT.setScale(0.9f, 0.9f);
    LEFT.setPosition(200,300);


    sf::Font font;
    font.loadFromFile("London.ttf");


    sf::Text T1,T3;
    T1.setFont(font);
    T1.setString("+ Point for " + game.pl1);
    T3.setFont(font);
    T3.setString("- Point for " + game.pl1);


    sf::Text T2,T4;
    T2.setFont(font);
    T2.setString("+ Point for " + game.pl2);
    T4.setFont(font);
    T4.setString("- Point for " + game.pl2);

    T1.setFillColor(sf::Color::White);
    T2.setFillColor(sf::Color::White);
    T3.setFillColor(sf::Color::White);
    T4.setFillColor(sf::Color::White);


    T1.setPosition(1600,200);
    T3.setPosition(1600,300);
    T2.setPosition(1600,400);
    T4.setPosition(1600,500);

    sf::Text T5;
    T5.setFont(font);
    T5.setString(game.GetName());
    T5.setFillColor(sf::Color::White);
    T5.setPosition(50,150);
    //???? ?? ???? ?? ????? 650*650 ???? ?? setscale(0.125f,0.125f) ??????? ????
    /*
    sf::Image R;
    if (!(R.loadFromFile("rokh.png")))
        cout << "" << endl;
    sf::Texture Ro;
    Ro.loadFromImage(R);
    sf::Sprite Rokh;
    Rokh.setTexture(Ro);
    Rokh.setScale(0.125f, 0.125f);
    Rokh.setPosition(500,500);
    */
    while (window->isOpen())
    {
        auto tr = game.GameBoard->boardsprite.getGlobalBounds();
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
                if(game.GameBoard->p1==sf::Vector2f(0,0))
                {
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
                    game.GameBoard->p2=sf::Vector2f(0,0);
                    game.GameBoard->p1=sf::Vector2f(0,0);
                }
            }
        }
        window->clear();

        game.GameBoard->draw();
        window->draw(rebgn);
        window->draw(ens);
        window->draw(EXIT);
        window->draw(name);
        window->draw(P);
        window->draw(LEFT);


        window->draw(T1);
        window->draw(T3);
        window->draw(T2);
        window->draw(T4);
        window->draw(T5);
        window->display();
    }
    delete window;
    return 0;
}
