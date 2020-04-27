#include <SFML\Graphics.hpp>
class Alive
{
private:
	int Health;
	float Speed;
	sf::Texture Texturka;
	sf::RectangleShape Rectangle;
public:
	Alive();
	virtual ~Alive();
};
