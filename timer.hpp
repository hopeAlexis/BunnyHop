#pragma once
#include <SFML/Graphics.hpp>

namespace game {
	class Timer {
	private:
		sf::Clock m_clock;
		int m_delay;
		bool m_isStarted;
	public:
		Timer(int delay);

		void restart();
		bool update();
		bool isStarted();
	};
}