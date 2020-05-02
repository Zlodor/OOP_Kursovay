#include "Map.h"

using namespace sf;

Map::Map()
{
	texture.loadFromFile("Map/tile.png");
	std::string tile2[17] =
	{
		"w                          w",
		"w                          w",
		"w                          w",
		"w                          w",
		"w                          w",
		"w                          w",
		"w                          w",
		"w                          w",
		"w                          w",
		"w                          w",
		"w                          w",
		"w                          w",
		"w                          w",
		"w                 wwww     w",
		"w                 wwww     w",
		"gggggggggggggggggggggggggggg",
		"                            "
	};

	swap(tile,tile2);
}

Map::~Map()
{}

void Map::Draw(RenderWindow &window)
{
	RectangleShape rec(Vector2f(30, 30));
	rec.setTexture(&texture);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j <width; j++)
		{
			switch (tile[i][j])
			{
			case 'p':
				rec.setTextureRect(IntRect(460, 35, 30, 30));
				rec.setPosition(j * 30, i * 30);
				window.draw(rec);
				break;
			case 's':
				rec.setTextureRect(IntRect(450, 54, 30, 30));
				rec.setPosition(j * 30, i * 30);
				window.draw(rec);
				break;
			case 'g':
				rec.setTextureRect(IntRect(460, 0, 30, 30));
				rec.setPosition(j * 30, i * 30);
				window.draw(rec);
				break;
			case 'w':
				rec.setTextureRect(IntRect(673, 32, 30, 30));
				rec.setPosition(j * 30, i * 30);
				window.draw(rec);
				break;
			default:
				//rec.setTextureRect(IntRect(470, 55, 30, 30));
				//rec.setPosition(j * 30, i * 30);
				//window.draw(rec);
				break;
			}
		}
	}
}
