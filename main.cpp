#include <SFML/Graphics.hpp>
#include "Player.h"
#include <Windows.h>
#include "Menu.h"
using namespace sf;

void KeyReg();
int main()
{
	RenderWindow window(sf::VideoMode(840, 480), "Kursach");
	window.setFramerateLimit(30);
	Player Igrok;
	Menu menu;
	Keyboard Key;
	float dx, dy;
	dx = 5;
	dy = 5;
	Map map;
	char Look='r';
	Color Back(29, 40, 52);

	menu.IsMenu(window);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Key.isKeyPressed(Keyboard::Up))
		{
			Igrok.ChangeTexture(jump, Look);
			Igrok.Move(map, 0);

		}
		else if (Key.isKeyPressed(Keyboard::Left))
		{
			Igrok.Move(map,-dx);
			Look = 'l';
			Igrok.ChangeTexture(run,Look);
		}
		else
			if (Key.isKeyPressed(Keyboard::Right))
			{
				Igrok.Move(map,dx);
				Look = 'r';
				Igrok.ChangeTexture(run, Look);
			}
				else if (Key.isKeyPressed(Keyboard::Space))
				{
					Igrok.ChangeTexture(attack, Look);
				}
				else
				{
					Igrok.Move(map, 0);
					Igrok.ChangeTexture(idle, Look);
				}
	

		window.clear(Back);
		map.Draw(window);
		window.draw(Igrok.RetSprite());
		window.display();

	}

	return 0;
}

