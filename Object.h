#pragma once
#include <SFML\Graphics.hpp>
class Object
{
public:
	Object();
	~Object();
	void SetStatus();

private:
	bool Status;
	sf::RectangleShape Shape;
};

