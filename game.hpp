#pragma once
#include <SFML/Graphics.hpp>
#include "bunny.hpp"

namespace game{
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
