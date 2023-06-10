#include "pickable_item.hpp"
#include "randomizer.hpp"
#include "bunny.hpp"
#include "game.hpp"

namespace game {
	PickableItem::PickableItem() :
		m_counter(0), m_timer(1500), m_isVisible(false), m_alpha(0.f) {}

	void PickableItem::resetCounter() {
		m_counter = 0;
	}

	int PickableItem::getCounter() {
		return m_counter;
	}

	void PickableItem::setAlpha(float value) {								// set opacity
		if (value > 1.f) value = 1.f;
		m_sprite.setColor(sf::Color(255, 255, 255, 255 * value));
		m_alpha = value;
	}

	sf::Sprite& PickableItem::getSprite() {
		return m_sprite;
	}

	sf::FloatRect PickableItem::getBounds() {
		return m_sprite.getGlobalBounds();
	}

	void PickableItem::setRandomPosition() {
		sf::FloatRect bunnyBounds = Game::instance()->getBunny()->getBounds();
		bunnyBounds.left -= 50;
		bunnyBounds.top -= 50;
		bunnyBounds.width += 50;
		bunnyBounds.height += 50;

		sf::Vector2f position;

		do {
			position = sf::Vector2f(Randomizer::Next(0, 750), Randomizer::Next(150, 450));
		} while (bunnyBounds.contains(position));

		m_sprite.setPosition(position);
	}
}