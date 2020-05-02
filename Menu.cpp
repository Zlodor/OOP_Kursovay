#include "Menu.h"
#include <SFML\Graphics.hpp>
#include <array>
#include <iostream>
using namespace sf;
Menu::Menu()
{}

Menu::~Menu()
{}

void Menu::IsMenu(RenderWindow &window)
{
	std::array<RectangleShape, 2> Bottoms;
	Bottoms[0].setSize(Vector2f(300, 100));
	Bottoms[0].setFillColor(Color::Cyan);
	Bottoms[0].setPosition(270,100);
	Bottoms[1].setSize(Vector2f(300, 100));
	Bottoms[1].setFillColor(Color::Cyan);
	Bottoms[1].setPosition(270, 280);
	Color Back(50, 120, 164);
	Font font;
	font.loadFromFile("Font.ttf");
	std::array<Text, 2> Mesage;
	Mesage[0].setFont(font);
	Mesage[1].setFont(font);
	Mesage[0].setString("Start");
	Mesage[1].setString("Exit");
	Mesage[0].setColor(Color::Black);
	Mesage[1].setColor(Color::Black);
	Mesage[0].setCharacterSize(50);
	Mesage[1].setCharacterSize(50);
	Mesage[0].setPosition(355, 120);
	Mesage[1].setPosition(380, 300);

	Bottoms[0].setOutlineThickness(10);
	Bottoms[0].setOutlineColor(Color::Magenta);
	Bottoms[1].setOutlineThickness(0);
	Bottoms[1].setOutlineColor(Color::Magenta);

	int Possition = 0;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
			if (event.type == Event::Closed)
				window.close();
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			Bottoms[0].setOutlineThickness(10);
			Bottoms[1].setOutlineThickness(0);
			Possition = 0;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			Bottoms[1].setOutlineThickness(10);
			Bottoms[0].setOutlineThickness(0);
			Possition = 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			if (Possition == 0)
			{
				return;
			}
			if (Possition == 1)
			{
				window.close();
			}
		}
	
		window.clear(Back);
		window.draw(Bottoms[0]);
		window.draw(Bottoms[1]);
		window.draw(Mesage[0]);
		window.draw(Mesage[1]);
		window.display();
	}

}
