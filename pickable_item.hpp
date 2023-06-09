#pragma once
#include <SFML/Graphics.hpp>
#include "timer.hpp"

namespace game {
	class PickableItem {
	protected:
		sf::Texture m_texture;
		sf::Sprite m_sprite;
		bool m_isVisible;
		Timer m_timer;
		float m_alpha;
		int m_counter;

		PickableItem();
		virtual void setAlpha(float value);
	public:
		virtual sf::FloatRect getBounds();
		virtual sf::Sprite& getSprite();
		virtual void setRandomPosition();
		virtual void update() = 0;

		void resetCounter();
		int getCounter();
	};
}