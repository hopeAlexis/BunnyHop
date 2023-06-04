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

Game::Game() :
	window(sf::VideoMode(w_width, w_height), "Bunny Hop"),
	bg_texture(),
	bg_sprite(),
	bunny((w_width - 200) / 2, w_height - 200, 10.f, 6.f),
	cooldown(1)
{
	window.setFramerateLimit(30);
	bg_texture.loadFromFile("sky.png", sf::IntRect(0, 0, w_width, w_height));
	bg_sprite.setTexture(bg_texture);
}

void Game::run()
{
	while (window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::KeyPressed)
		{
			handleKeyPressed(event.key.code);
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			handleKeyReleased(event.key.code);
		}
	}
}

void Game::handleKeyPressed(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Space:
	{
		if (!bunny.isHop())
		{
			bunny.setIsHop(true);
			cooldown = 1;
		}
		break;
	}
	case sf::Keyboard::Right:
	{
		bunny.moveRight();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			bunny.setIsHop(true);
			bunny.moveRight(); // Add horizontal movement
		}
		break;
	}
	case sf::Keyboard::Left:
	{
		bunny.moveLeft();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			bunny.setIsHop(true);
			bunny.moveLeft(); // Add horizontal movement
		}
		break;
	}
	}
}

void Game::handleKeyReleased(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Right:
	case sf::Keyboard::Left:
	{
		bunny.changeSprite(1);
		break;
	}
	}
}

void Game::update()
{
	if (bunny.isHop())
		cooldown = bunny.hop(cooldown);
}

void Game::render()
{
	window.clear();
	window.draw(bg_sprite);
	window.draw(bunny.getSprite());
	window.display();
}
