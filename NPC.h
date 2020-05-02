#pragma once
#include <SFML\Graphics.hpp>
class NPC
{
private:
	int Health;
	float Speed;
	sf::Texture Texturka;
	sf::RectangleShape Collision;
public:
	NPC();
	virtual ~NPC();
};
