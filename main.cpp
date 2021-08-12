#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(1900, 1000), "Chess");
	
	sf::Image image;
	if (!(image.loadFromFile("board.jpg")))
		cout << "Cannot load image";   //Load Image

	sf::Texture texture;
	texture.loadFromImage(image);  //Load Texture from image

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale(0.65f,0.65f);
	sprite.setPosition(600,100);

	sf::Image rebegin;
	if (!(rebegin.loadFromFile("rebegin.png")))
		cout << "Cannot load image";   //Load Image

	sf::Texture rgn;
	rgn.loadFromImage(rebegin);  //Load Texture from image

	sf::Sprite rebgn;
	rebgn.setTexture(rgn);
	rebgn.setScale(0.5f, 0.5f);
	rebgn.setPosition(50, 600);

	sf::Image dispense;
		if (!(dispense.loadFromFile("enseraf.png")))
			cout << "cannot load image" << endl;
	sf::Texture enseraf;
	enseraf.loadFromImage(dispense);
	sf::Sprite ens;
	ens.setTexture(enseraf);
	ens.setScale(0.7f,0.5f);
	ens.setPosition(50,700);

	sf::Image Exit;
	if (!(Exit.loadFromFile("exit.png")))
		cout << "cannot load image" << endl;
	sf::Texture Ext;
	Ext.loadFromImage(Exit);
	sf::Sprite EXIT;
	EXIT.setTexture(Ext);
	EXIT.setScale(0.5f,0.5f);
	EXIT.setPosition(85,800);

	sf::Image Name;
	if (!(Name.loadFromFile("name.png")))
		cout << "cannot open image" << endl;
	sf::Texture NAME;
	NAME.loadFromImage(Name);
	sf::Sprite name;
	name.setTexture(NAME);
	name.setScale(0.5f,0.5f);
	name.setPosition(50,10);
	sf::Image Point;
	if (!(Point.loadFromFile("point.png")))
		cout << "cannot open image" << endl;
	sf::Texture POint;
	POint.loadFromImage(Point);
	sf::Sprite P;
	P.setTexture(POint);
	P.setScale(0.9f,0.9f);
	P.setPosition(1600,30);

	sf::Image Left;
	if (!(Left.loadFromFile("Left.png")))
		cout << "cannot open image" << endl;
	sf::Texture L;
	L.loadFromImage(Left);
	sf::Sprite LEFT;
	LEFT.setTexture(L);
	LEFT.setScale(0.9f, 0.9f);
	LEFT.setPosition(200,300);

	sf::Image UNDO;
	if (!(UNDO.loadFromFile("undo.png")))
		cout << "cannot open image" << endl;
	sf::Texture undo;
	undo.loadFromImage(UNDO);
	sf::Sprite u;
	u.setTexture(undo);
	u.setScale(0.9f,0.9f);
	u.setPosition(60,400);

	/*
	sf::Font font;
	font.loadFromFile("London.ttf");
	cout << "enter name 1:" << endl;
	string name1;
	cin >> name1;

	cout << "enter name 2:" << endl;
	string name2;
	cin >> name2;

	sf::Text T1,T3;
	T1.setFont(font);
	T1.setString("+Point for "+name1);
	T3.setFont(font);
	T3.setString("-Point for " + name1);

	sf::Text T2,T4;
	T2.setFont(font);
	T2.setString("+Point for "+name2);
	T4.setFont(font);
	T4.setString("-Point for " + name2);

	T1.setFillColor(sf::Color::White);
	T2.setFillColor(sf::Color::White);
	T3.setFillColor(sf::Color::White);
	T4.setFillColor(sf::Color::White);
	
	
	T1.setPosition(1600,200);
	T3.setPosition(1600,300);
	T2.setPosition(1600,400);
	T4.setPosition(1600,500);
	*/

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
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.draw(rebgn);
		window.draw(ens);
		window.draw(EXIT);
		window.draw(name);
		window.draw(P);
		window.draw(LEFT);
		window.draw(u);
		//window.draw(Rokh);
		/*
		window.draw(T1);
		window.draw(T3);
		window.draw(T2);
		window.draw(T4);
		*/
		window.display();
	}

	return 0;
}