#pragma once
namespace game
{
	class Bunny
	{
	private:
		float b_x0 = 150.f, b_y0 = 300.f;
		float b_vel, b_hop_vel;
		unsigned int b_sprite_width = 130, b_sprite_height = 200;
		sf::Texture b_texture_default;
		sf::Texture b_texture_right;
		sf::Texture b_texture_left;
		sf::Texture b_texture_hop;
		sf::Sprite b_sprite;

	public:
		Bunny(float x, float y, float vel, float hop_vel);
		sf::Sprite getSprite();
		float getX();
		float getY();
		float getVel();
		float getHopVel();
		void setPosition(float x, float y);
		bool checkCollision(float x, float y);
		void changeSprite(int which);
		void hop(float jumpCount);
		void right();
		void left();
	};
}