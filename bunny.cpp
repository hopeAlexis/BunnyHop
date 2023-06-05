#include <iostream>
#include <SFML/Graphics.hpp>
#include "bunny.hpp"

using namespace game;
 
Bunny::Bunny(float x, float y, float vel, float hop_vel) {
	b_x0 = x;
	b_y0 = y;
	b_vel = vel;
	b_hop_vel = hop_vel;
	b_texture_default.loadFromFile("chonk_default.png", sf::IntRect(0, 0, b_sprite_width, b_sprite_height));
	b_texture_right.loadFromFile("chonk_right.png", sf::IntRect(0, 0, b_sprite_width, b_sprite_height));
	b_texture_left.loadFromFile("chonk_left.png", sf::IntRect(0, 0, b_sprite_width, b_sprite_height));
	b_texture_hop.loadFromFile("chonk_hop.png", sf::IntRect(0, 0, b_sprite_width, b_sprite_height));
	b_sprite.setTexture(b_texture_default);
	b_sprite.setPosition(sf::Vector2f(b_x0, b_y0));
}

sf::Sprite Bunny::getSprite()
{
	return b_sprite;
}

float Bunny::getX()
{
	return b_x0;
}

float Bunny::getY()
{
	return b_y0;
}

float Bunny::getVel()
{
	return b_vel;
}

float Bunny::getHopVel()
{
	return b_hop_vel;
}

bool Bunny::isHop()
{
	return b_is_hop;
}

void Bunny::setIsHop(bool fl)
{
	b_is_hop = fl;
}

void Bunny::setPosition(float x, float y)
{
	b_x0 = x;
	b_y0 = y;
	b_sprite.setPosition(sf::Vector2f(b_x0, b_y0));
}

bool Bunny::checkCollision(float x, float y)
{
	bool check = false;
	if ((x > -10) && (x + b_sprite_width < 810))
	{
		check = true;
	}
	return check;
}

void Bunny::changeSprite(int which)
{
	switch (which)
	{
		case 1:
		{
			b_sprite.setTexture(b_texture_default);
			break;
		}
		case 2:
		{
			b_sprite.setTexture(b_texture_right);
			break;
		}
		case 3:
		{
			b_sprite.setTexture(b_texture_left);
			break;
		}
		case 4:
		{
			b_sprite.setTexture(b_texture_hop);
			break;
		}
		default:
		{
			b_sprite.setTexture(b_texture_default);
			break;
		}
	}
}

float Bunny::hop(float cooldown)
{
	if (cooldown >= -1)
	{
		int neg = 1;
		changeSprite(4);
		if (cooldown < 0)
		{
			neg = -1;
			changeSprite(1);
		}
		setPosition(getX(), getY() - (getHopVel() * getHopVel()) * 0.5 * neg);
		cooldown -= 0.1;
	}
	else
	{
		setIsHop(false);
	}
	return cooldown;
}

void Bunny::moveRight()
{
	if (checkCollision(getX() + getVel(), getY()))
	{
		setPosition(getX() + getVel(), getY());
		changeSprite(2);
	}
}

void Bunny::moveLeft()
{
	if (checkCollision(getX() - getVel(), getY()))
	{
		setPosition(getX() - getVel(), getY());
		changeSprite(3);
	}
}

