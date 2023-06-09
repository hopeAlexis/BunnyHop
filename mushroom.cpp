#include "mushroom.hpp"
#include "paths.hpp"
#include "sound_player.hpp"
#include "game.hpp"
#include "bunny.hpp"

namespace game {
	Mushroom::Mushroom() {
		m_texture.loadFromFile(Paths::getMushroomTexturePath());
		m_sprite.setTexture(m_texture);
		
		setAlpha(0.f);

		m_timer.restart();
	}

	void Mushroom::update() {
		if (!m_isVisible) {
			if (m_timer.update()) {
				setRandomPosition();
				m_isVisible = true;
			}

			return;
		}

		if (m_alpha <= 1.f) setAlpha(m_alpha + 0.05f);

		Bunny* bunny = Game::instance()->getBunny();

		sf::FloatRect bunnyBounds = bunny->getBounds();
		bunnyBounds.height -= 130;
		bunnyBounds.top += 130;

		if (getBounds().intersects(bunnyBounds)) {
			m_isVisible = false;
			setAlpha(0.f);
			m_timer.restart();

			bunny->resetMushroomInfluenceTimer();

			m_counter++;

			if (m_counter == 5) {
				bunny->setMushroomInfluence(200);
			} else if (m_counter == 10) {
				bunny->setMushroomInfluence(150);
			} else if (m_counter == 15) {
				bunny->setMushroomInfluence(100);
			}

			SoundPlayer::playPickup();
		}
	}
}