#pragma once
#include <SFML/Graphics.hpp>

namespace game {
	class Background {
	private:
		sf::Texture m_backTexture;
		sf::Texture m_frontTexture;
		sf::Sprite m_backSprite;		// background in the back
		sf::Sprite m_frontSprite;		// background in the front

		float m_alpha;
		bool m_isChanging;

		void setAlpha(float value);		// opacity of the background (front part)
	public:
		Background();

		void change();
		void update(sf::RenderWindow& window);
	};
}