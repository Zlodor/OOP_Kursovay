#include <SFML/Graphics.hpp>
#include "Player.h"
//#include "Map.h"
#include <Windows.h>
using namespace sf;

void KeyReg();
int main()
{
	RenderWindow window(sf::VideoMode(840, 480), "Kursach");
	Player Igrok;
	Keyboard Key;
	float dx, dy;
	dx = 5;
	dy = 5;
	Map map;
	char Look='r';
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Key.isKeyPressed(Keyboard::Left))//клавиатура
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
			else
				if (Key.isKeyPressed(Keyboard::Up))
				{
					Igrok.ChangeTexture(jump, Look);
					Igrok.Move(map,0);
					
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
	

		window.clear();
		map.Draw(window);
		window.draw(Igrok.RetSprite());
		window.display();
		Sleep(50);

	}

	return 0;
}

