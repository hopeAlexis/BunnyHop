#pragma once
#include <SFML/Graphics.hpp>
#include "bunny.hpp"

namespace game {
	class Game {
	private:
		static Game* m_instance;
		Game();
		~Game();
	public:
		static Game* instance();
		int run();
	};
}