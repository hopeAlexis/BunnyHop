#pragma once
#include "bunny_animator.hpp"

namespace game {
	class Bunny {
	private:
		float m_x;
		float m_y;
		float m_movementSpeed;
		float m_hoppingSpeed;
		bool m_isBackward;
		bool m_isHopping;
		float m_cooldown;
		sf::Texture m_texture;
		sf::Sprite m_sprite;
		BunnyAnimator m_bunnyAnimator;
		bool m_isLongIdle;
		Timer m_longIdleTimer;
		Timer m_mushroomInfluenceTimer;

		void restartLongIdleTimer();
	public:
		Bunny(float x, float y, float movementSpeed, float hoppingSpeed);
		
		void hop();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void update();

		void setRect(sf::IntRect rect);		
		sf::Sprite& getSprite();
		sf::FloatRect getBounds();

		void setMushroomInfluence(int value);
		int getMushroomInfluence();
		void resetMushroomInfluenceTimer();
	};
}