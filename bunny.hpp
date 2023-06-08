#pragma once

namespace game {

	enum BunnyState {
		Idle,
		MovingLeft,
		MovingRight,
		Hopping
	};

	class Bunny {
	private:
		float m_x;
		float m_y;
		float m_movementSpeed;
		float m_hoppingSpeed;
		sf::Texture m_texture;
		sf::Sprite m_sprite;
		BunnyState m_state;

		void changeTextureRect(BunnyState state);
	public:
		Bunny(float x, float y, float movementSpeed, float hoppingSpeed);
		void hop();
		void moveLeft();
		void moveRight();
		float handleHop(float cooldown);

		void setState(BunnyState state);
		BunnyState getState();
		sf::Sprite getSprite();
	};
}