#pragma once
namespace game
{
	class Bunny
	{
	private:
		float b_x0 = 150.f, b_y0 = 300.f;
		float b_vel;
		unsigned int b_sprite_width = 200, b_sprite_height = 200;
		sf::Texture b_texture;
		sf::Sprite b_sprite;

	public:
		Bunny(float x, float y, float vel);
		sf::Sprite getSprite();
		float getX();
		float getY();
		float getVel();
		void setPosition(float x, float y);
		bool checkCollision(float x, float y);
	};
}