#include <iostream>
#include <SFML/Graphics.hpp>
#include "bunny.hpp"

using namespace game;
 
Bunny::Bunny(float x, float y, float vel)
	{
		b_x0 = x;
		b_y0 = y;
		b_vel = vel;
		b_texture.loadFromFile("chonk.png", sf::IntRect(0, 0, b_sprite_width, b_sprite_height));
		b_sprite.setTexture(b_texture);
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

			void Bunny::setPosition(float x, float y)
			{
				b_x0 = x;
				b_y0 = y;
				std::cout << b_x0 << " " << b_y0 << "\n";
				b_sprite.setPosition(sf::Vector2f(b_x0, b_y0));
			}