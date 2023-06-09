#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

namespace game {
	class Bunny;
	class Mushroom;
	class MagicBall;
	class Background;

	class Game {
	private:
		static std::unique_ptr<Game> m_instance;
		Bunny* m_bunny;
		Mushroom* m_mushroom;
		MagicBall* m_magicBall;
		Background* m_background;
	public:
		static Game* instance();
		int run();

		Bunny* getBunny();
		Mushroom* getMushroom();
		MagicBall* getMagicBall();
		Background* getBackground();
	};
}