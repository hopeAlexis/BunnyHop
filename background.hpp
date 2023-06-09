#pragma once
#include <SFML/Graphics.hpp>

namespace game {
	class Background {
	private:
		sf::Texture m_backTexture;
		sf::Texture m_frontTexture;
		sf::Sprite m_backSprite;
		sf::Sprite m_frontSprite;

		float m_alpha;
		bool m_isChanging;

		void setAlpha(float value);
	public:
		Background();

		void change();
		void update(sf::RenderWindow& window);
	};
}