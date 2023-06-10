#include <SFML/Graphics.hpp>
#include "sound_player.hpp"
#include "paths.hpp"
#include "bunny.hpp"
#include "mushroom.hpp"
#include "game.hpp"

namespace game {
	Bunny::Bunny(float x, float y, float movementSpeed, float hoppingSpeed) :
		m_x(x),
		m_y(y),
		m_movementSpeed(movementSpeed),
		m_hoppingSpeed(hoppingSpeed),
		m_isHopping(false),
		m_isBackward(false),
		m_cooldown(1.f),
		m_bunnyAnimator(this, 250),
		m_isLongIdle(false),
		m_longIdleTimer(5000),
		m_mushroomInfluenceTimer(10000) {

		m_texture.loadFromFile(Paths::getBunnySpriteSheetTexturePath());
		m_sprite.setTexture(m_texture);
		m_sprite.setPosition(sf::Vector2f(x, y));

		setRect(m_bunnyAnimator.getRect(BunnySpriteSheetFrame::Idle1));
		m_longIdleTimer.restart();
		m_mushroomInfluenceTimer.restart();
	}

	void Bunny::restartLongIdleTimer() {
		m_longIdleTimer.restart();
		if (m_isLongIdle) m_isLongIdle = false;
	}

	void Bunny::setRect(sf::IntRect rect) {
		m_sprite.setTextureRect(rect);
	}

	sf::Sprite& Bunny::getSprite() {
		return m_sprite;
	}

	sf::FloatRect Bunny::getBounds() {
		return m_sprite.getGlobalBounds();
	}

	void Bunny::setMushroomInfluence(int value) {
		m_sprite.setColor(sf::Color(255, value, 255));
	}

	int Bunny::getMushroomInfluence() {
		return m_sprite.getColor().g;
	}

	void Bunny::resetMushroomInfluenceTimer() {
		m_mushroomInfluenceTimer.restart();
	}

	void Bunny::hop() {
		if (!m_isHopping) {
			m_bunnyAnimator.setAnimation(BunnyAnimation::None);

			setRect(m_bunnyAnimator.getRect(m_isBackward ?
				BunnySpriteSheetFrame::HoppingBackward :
				BunnySpriteSheetFrame::Hopping));

			m_isHopping = true;

			SoundPlayer::playJump();
		}
	}

	void Bunny::moveUp() {
		if (!m_isBackward) m_isBackward = true;

		m_bunnyAnimator.setAnimation(BunnyAnimation::IdleBackward);
		restartLongIdleTimer();

		float y = m_y - m_movementSpeed;
		if (y < 150) return;
		m_y = y;
	}

	void Bunny::moveDown() {
		if (m_isBackward) m_isBackward = false;

		m_bunnyAnimator.setAnimation(BunnyAnimation::Idle);
		restartLongIdleTimer();
		
		float y = m_y + m_movementSpeed;
		if (y >= 300) return;
		m_y = y;
	}

	void Bunny::moveLeft() {
		m_bunnyAnimator.setAnimation(BunnyAnimation::MovingLeft);
		restartLongIdleTimer();

		float x = m_x - m_movementSpeed;
		if (x < 0) return;
		m_x = x;
	}

	void Bunny::moveRight() {
		m_bunnyAnimator.setAnimation(BunnyAnimation::MovingRight);
		restartLongIdleTimer();

		float x = m_x + m_movementSpeed;
		if (x > 670) return;
		m_x = x;
	}

	void Bunny::update() {

		if (getMushroomInfluence() != 255 &&
			m_mushroomInfluenceTimer.update()) {
			setMushroomInfluence(255);
			m_mushroomInfluenceTimer.restart();
			Game::instance()->getMushroom()->resetCounter();
		}

		if (!m_isHopping) {
			if (!m_isLongIdle && m_longIdleTimer.update()) {
				m_isLongIdle = true;
				m_isBackward = false;
				m_bunnyAnimator.setAnimation(BunnyAnimation::None);
				setRect(m_bunnyAnimator.getRect(BunnySpriteSheetFrame::LongIdle));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				hop();
				return;
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				moveUp();
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				moveDown();
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				moveLeft();
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				moveRight();
			} else if (!m_isLongIdle) {
				m_bunnyAnimator.setAnimation(
					m_isBackward ?
					BunnyAnimation::IdleBackward :
					BunnyAnimation::Idle);
			}
		} else {
			if (m_cooldown >= -1) {
				int multiplier;
				if (m_cooldown < 0) {
					setRect(m_bunnyAnimator.getRect(m_isBackward ?
						BunnySpriteSheetFrame::IdleBackward1 :
						BunnySpriteSheetFrame::Idle1));
					multiplier = -1;
				} else {
					multiplier = 1;
				}
				m_y = m_y - m_hoppingSpeed * m_hoppingSpeed * 0.5 * multiplier;
				m_cooldown -= 0.1;
			} else {
				m_cooldown = 1.f;
				m_isHopping = false;

				m_bunnyAnimator.setAnimation(m_isBackward ?
					BunnyAnimation::IdleBackward : BunnyAnimation::Idle);
				restartLongIdleTimer();
			}
		}

		m_bunnyAnimator.update();
		m_sprite.setPosition(m_x, m_y);
	}
}