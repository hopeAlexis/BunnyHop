#include "background.hpp"
#include "paths.hpp"

namespace game {
	Background::Background() : m_isChanging(false), m_alpha(1.f) {
		m_frontTexture.loadFromFile(Paths::getBackgroundTexturePath(1));
		m_frontSprite.setTexture(m_frontTexture);
	}

	void Background::setAlpha(float value) {
		if (value > 1.f) value = 1.f;
		m_frontSprite.setColor(sf::Color(255, 255, 255, 255 * value));
		m_alpha = value;
	}
	
	void Background::update(sf::RenderWindow& window) {
		if (m_isChanging) {
			setAlpha(m_alpha + 0.04);
			if (m_alpha >= 1.f) {
				m_isChanging = false;
			} else {
				window.draw(m_backSprite);
			}
		}

		window.draw(m_frontSprite);
	}

	void Background::change() {
		if (!m_isChanging) {
			static int currentBackground = 1;

			currentBackground++;

			if (currentBackground > 4) {
				currentBackground = 1;
			}

			setAlpha(0.f);

			m_backTexture = m_frontTexture;
			m_backSprite.setTexture(m_backTexture);

			m_frontTexture.loadFromFile(Paths::getBackgroundTexturePath(currentBackground));
			m_frontSprite.setTexture(m_frontTexture);

			m_isChanging = true;
		}
	}
}