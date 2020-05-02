#pragma once
#include <SFML\Graphics.hpp>
#include "Map.h"
enum Condition  { idle, run, jump , attack,fall};

class Player
{
private:
	int Health;
	float  G = 5;
	int frame_count;
	sf::Texture TexIdle;
	sf::Texture TexRun;
	sf::Texture TexJump;
	sf::Texture TexAtck;
	sf::Sprite sprite;
	RectangleShape collision;
	bool OnGround;
	bool BlokAnim;//блокировка смены анимации
	char VectorOfLook='r';//направление взгляда
	Condition Now;//проигрываемая анимация
	void AnimRun();
	void AnimIdle();
	void AnimJump();
	void AnimAttack();
	void AnimFall();
public:
	Player();
	~Player();
	sf::Sprite RetSprite();
	void Move(Map karta,float x);
	void ChangeTexture(Condition Get,char ch);
	void Collision(Map karta, float x);
};

