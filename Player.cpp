#include "Player.h"
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;

Player::Player()
{

	TexIdle.loadFromFile("Player/idle.png");
	
	sprite.setTexture(TexIdle);
	TexRun.loadFromFile("Player/run.png");
	
	TexJump.loadFromFile("Player/jump.png");
	TexAtck.loadFromFile("Player/attack1.png");

	sprite.setTextureRect(IntRect(0, 0, 48, 48));
	collision.setSize(Vector2f(30, 48));
	frame_count = 0;
	Now = idle;
	BlokAnim = false;
	sprite.setPosition(400, 350);
	collision.setPosition(400 + 9, 350);
};
Player::~Player()
{};
void Player::ChangeTexture(Condition Get, char ch)
{
	VectorOfLook = ch;
	if (Get != Now && BlokAnim==false)
	{
		frame_count = 0;
		Now = Get;
		switch (Now)
		{
		case idle:
			sprite.setTexture(TexIdle);
			break;
		case run:
			sprite.setTexture(TexRun);
			break;
		case jump:
			sprite.setTexture(TexJump);
			break;
		case attack:
			sprite.setTexture(TexAtck);
			break;
		}
	}
};
Sprite Player::RetSprite()
{
		switch (Now)
		{
		case idle:
			AnimIdle();
			break;
		case run:
			AnimRun();
			break;
		case jump:
			AnimJump();
			break;
		case attack:
			AnimAttack();
			break;
		case fall:
			AnimFall();
		}
	return sprite;
};
void Player::AnimIdle()
{
	switch (VectorOfLook)
	{
	case 'r':
		sprite.setTextureRect(IntRect((0 + frame_count * 48), 0, 48, 48));
		frame_count++;
		if (frame_count >= 4) frame_count = 0;
		break;
	case 'l':
		sprite.setTextureRect(IntRect((0 + frame_count * 48)+48, 0, -48, 48));
		frame_count++;
		if (frame_count >= 4) frame_count = 0;
		break;
	}
};
void Player::AnimJump()
{
	if (OnGround)
	{
		BlokAnim = true;
		OnGround = false;
		G = -10;
	}
		switch (VectorOfLook)
		{
		case 'r':
			sprite.setTextureRect(IntRect(2 * 48, 0, 48, 48));
			frame_count++;
			break;
		case 'l':
			sprite.setTextureRect(IntRect(3 * 48, 0, -48, 48));
			frame_count++;
			break;
		}
		if (frame_count >= 8)
		{
			G = 5;
			frame_count = 0;
			BlokAnim = false;
			Now = fall;
		}
};
void Player::AnimFall()
{
	sprite.setTexture(TexJump);
	switch (VectorOfLook)
	{
	case 'r':
		sprite.setTextureRect(IntRect(4 * 48, 0, 48, 48));
		break;
	case 'l':
		sprite.setTextureRect(IntRect(5 * 48, 0, -48, 48));
		break;
	}
}
void Player::AnimRun()
{
	switch (VectorOfLook)
	{
	case 'r':
		sprite.setTextureRect(IntRect((0 + frame_count * 48), 0, 48, 48));
		frame_count++;
		if (frame_count >= 6) frame_count = 0;
		break;
	case 'l':
		sprite.setTextureRect(IntRect((0 + frame_count * 48) + 48, 0, -48, 48));
		frame_count++;
		if (frame_count >= 6) frame_count = 0;
	}
};
void Player::Move(Map karta,float x)
{
	sprite.move(x, G);
	collision.move(x, G);
	Collision(karta,  x);
};
void Player::AnimAttack()
{
	BlokAnim = true;
	switch (VectorOfLook)
	{
	case 'r':
		sprite.setTextureRect(IntRect((0 + frame_count * 48), 0, 48, 48));
		frame_count++;
		if (frame_count >= 6)
		{
			frame_count = 0;
			BlokAnim = false;
		}
		break;
	case 'l':
		sprite.setTextureRect(IntRect((0 + frame_count * 48)+48, 0, -48, 48));
		frame_count++;
		if (frame_count >= 6)
		{
			frame_count = 0;
			BlokAnim = false;
		}
		break;
	}
}
void Player::Collision(Map karta,float x)
{
	float dx = 0, dy = 0;//итоговая поправка после move
	int X,From_Y, To_Y;

	From_Y = collision.getPosition().y / 30;
	To_Y = (collision.getPosition().y + 48) / 30;

	//проверка столкновения снизу
	X = collision.getPosition().x;
	if (X % 30 != 0)
	{
		X /= 30;
		for (int j = X; j < (X + 2); j++)
		{
			switch (karta.tile[To_Y][j])
			{
			case 'g':
				dy = To_Y * 30 - 48;
				OnGround = true;
				BlokAnim = false;
				break;
			case 'w':
				dy = To_Y * 30 - 48;
				OnGround = true;
				BlokAnim = false;
				break;
			default:
				if (Now != jump)
				{
					Now = fall;
					OnGround = false;
					BlokAnim = true;
				}
				break;
			}
		}
	}
	else
	{
		X /= 30;
		switch (karta.tile[To_Y][X])
		{
		case 'g':
			dy = To_Y * 30 - 48;
			OnGround = true;
			BlokAnim = false;
			break;
		case 'w':
			dy = To_Y * 30 - 48;
			OnGround = true;
			BlokAnim = false;
			break;
		default:
			if (Now != jump)
			{
				Now = fall;
				OnGround = false;
				BlokAnim = true;
			}
			break;
		}
	}
	
	//проверка столкновений слева и справа
	if (x > 0)
		X = collision.getPosition().x/30 + 1;
	else
		X = collision.getPosition().x/30;

	for (int i=From_Y; i<To_Y; i++)
	{
		switch (karta.tile[i][X])
		{
		case 'w':
			if (x > 0) dx = X * 30 - 30;
			else dx = X * 30 + 30;
			break;
		default:
			break;
		}
	}


	if ((dx != 0) || (dy != 0))
	{
		if (dx == 0) dx = collision.getPosition().x;
		if (dy == 0) dy = collision.getPosition().y;
		collision.setPosition(dx, dy);
		sprite.setPosition(dx - 9, dy);
	}

	switch (Now)
	{
	case idle:
		std::cout << "idle" <<std::endl;
		break;
	case jump:
		std::cout << "jump" << std::endl;
		break;
	case run:
		std::cout << "run" << std::endl;
		break;
	case fall:
		std::cout << "fall" << std::endl;
		break;
	}
		
}