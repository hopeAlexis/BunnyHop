#include <iostream>
#include <SFML/Graphics.hpp>
#include "bunny.hpp"

using namespace game;

Bunny::Bunny(float x, float y, float movementSpeed, float hoppingSpeed) :
	m_x(x), m_y(y), m_movementSpeed(movementSpeed), m_hoppingSpeed(hoppingSpeed) {

	m_texture.loadFromFile("assets//chonk_spritesheet.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(sf::Vector2f(x, y));

	changeTextureRect(BunnyState::Idle);
}

sf::Sprite Bunny::getSprite() {
	return m_sprite;
}

void Bunny::setState(BunnyState state) {
	if (m_state != state) {
		m_state = state;
		changeTextureRect(state);
	}
}

void Bunny::changeTextureRect(BunnyState state) {
	switch (state) {
	case BunnyState::Idle:
		m_sprite.setTextureRect(sf::IntRect(0, 0, 130, 200));
		return;
	case BunnyState::MovingLeft:
		m_sprite.setTextureRect(sf::IntRect(260, 200, 130, 200));
		return;
	case BunnyState::MovingRight:
		m_sprite.setTextureRect(sf::IntRect(0, 200, 130, 200));
		return;
	case BunnyState::Hopping:
		m_sprite.setTextureRect(sf::IntRect(390, 0, 130, 200));
		return;
	}
}

void Bunny::hop() {
	setState(BunnyState::Hopping);
}

float Bunny::handleHop(float cooldown) {
	if (cooldown >= -1) {
		int neg = 1;
		changeTextureRect(BunnyState::Hopping);
		if (cooldown < 0) {
			neg = -1;
			changeTextureRect(BunnyState::Idle);
		}

		m_y = m_y - m_hoppingSpeed * m_hoppingSpeed * 0.5 * neg;

		m_sprite.setPosition(m_x, m_y);

		cooldown -= 0.1;
	}
	else {
		m_state = BunnyState::Idle;
	}
	return cooldown;
}

void Bunny::moveLeft() {
	setState(BunnyState::MovingLeft);

	float x = m_x - m_movementSpeed;

	if (x < 0) return;

	m_x = x;

	m_sprite.setPosition(m_x, m_y);
}

void Bunny::moveRight() {
	setState(BunnyState::MovingRight);

	float x = m_x + m_movementSpeed;

	if (x > 670) return;

	m_x = x;

	m_sprite.setPosition(m_x, m_y);
}

BunnyState Bunny::getState() {
	return m_state;
}
