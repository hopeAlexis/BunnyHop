#include "magic_ball.hpp"
#include "paths.hpp"
#include "game.hpp"
#include "bunny.hpp"
#include "background.hpp"
#include "sound_player.hpp"

namespace game {
	MagicBall::MagicBall() {
		m_texture.loadFromFile(Paths::getMagicBallTexturePath());
		m_sprite.setTexture(m_texture);

		setAlpha(0.f);

		m_timer.restart();
	}

	void MagicBall::update() {
		if (!m_isVisible) {
			if (m_timer.update()) {
				setRandomPosition();
				m_isVisible = true;
			}

			return;
		}

		if (m_alpha <= 1.f) setAlpha(m_alpha + 0.05f);

		sf::FloatRect bunnyBounds = Game::instance()->getBunny()->getBounds();
		bunnyBounds.height -= 130;
		bunnyBounds.top += 130;

		if (getBounds().intersects(bunnyBounds)) {
			m_isVisible = false;
			setAlpha(0.f);
			m_timer.restart();
			SoundPlayer::playPickup();

			if (++m_counter == 5) {
				resetCounter();
				Game::instance()->getBackground()->change();
			}
		}
	}
}