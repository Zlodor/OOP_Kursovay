#pragma once
#include <string>
#include <SFML\Graphics.hpp>
using namespace sf;

class Map
{
public:
	Map();
	~Map();
	void Draw(RenderWindow &window);
	std::string tile[17];//����������� ����, ����� �������� �� ��������
private:
	Texture texture;
	int width = 28;
	int height = 16;
};

