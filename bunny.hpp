#pragma once
namespace game
{
	class Bunny
	{
	private:
		float b_x0 = 150.f, b_y0 = 300.f;
		float b_vel, b_hop_vel;
		bool b_is_hop = false;
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
		bool isHop();
		void setIsHop(bool fl);
		void setPosition(float x, float y);
		bool checkCollision(float x, float y);
		void changeSprite(int which);
		float hop(float cooldown);
		void moveRight();
		void moveLeft();
	};


	class Game
	{
	private:
		unsigned int w_width = 800, w_height = 500;
		sf::RenderWindow window;
		sf::Texture bg_texture;
		sf::Sprite bg_sprite;
		Bunny bunny;
		float cooldown;

	public:
		Game();
		void run();
		void processEvents();
		void handleKeyPressed(sf::Keyboard::Key key);
		void handleKeyReleased(sf::Keyboard::Key key);
		void update();
		void render();
	};

}