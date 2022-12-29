#include <iostream>
#include <SFML/Graphics.hpp>
#include "bunny.hpp"

using namespace game;
 
Bunny::Bunny(float x, float y, float vel, float hop_vel)
	{
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

			void Bunny::setPosition(float x, float y)
			{
				b_x0 = x;
				b_y0 = y;
				std::cout << b_x0 << " " << b_y0 << "\n";
				b_sprite.setPosition(sf::Vector2f(b_x0, b_y0));
			}

			bool Bunny::checkCollision(float x, float y)
			{
				bool check = false;

				if ((x > -10) && (x + b_sprite_width < 810))
				{
					if ((y > -10) /*&& (b_y0 + b_sprite_height < 500 - b_vel)*/)
					{
						check = true;
						std::cout << "passed the check! ";
					}
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

			void Bunny::hop(float jumpCount)
			{
				std::cout << "Entered hop! " << b_y0 << "\n";
				if (jumpCount >= -10)
				{
					int neg = 1;
					if (jumpCount < 0)
						neg = -1;
					b_y0 -= (jumpCount*jumpCount) * 0.5 * neg;
					jumpCount -= 1;
					std::cout << jumpCount << " " << b_y0 << "\n";
				}
			}

			void Bunny::right()
			{
				if (checkCollision(getX() + getVel(), getY()))
				{
					setPosition(getX() + getVel(), getY());
					changeSprite(2);
				}
			}

			void Bunny::left()
			{
				if (checkCollision(getX() - getVel(), getY()))
				{
					setPosition(getX() - getVel(), getY());
					changeSprite(3);
				}
			}