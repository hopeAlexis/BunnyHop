#pragma once
#include <SFML/Graphics.hpp>
#include "timer.hpp"

namespace game {

	enum BunnySpriteSheetFrame {
		Idle1,
		Idle2,
		Idle3,
		IdleBackward1,
		IdleBackward2,
		IdleBackward3,
		Hopping,
		HoppingBackward,
		MovingLeft1,
		MovingLeft2,
		MovingRight1,
		MovingRight2,
		LongIdle
	};

	enum BunnyAnimation {
		None,
		Idle,
		IdleBackward,
		MovingLeft,
		MovingRight
	};

	class Bunny;

	class BunnyAnimator {
	private:
		BunnyAnimation m_currentAnimation;
		BunnySpriteSheetFrame* m_currentAnimationFrames;
		int m_amountOfFrames;
		int m_currentFrameIndex;
		Timer m_timer;
		Bunny* m_bunny;
	public:
		BunnyAnimator(Bunny* bunny, int delay);

		sf::IntRect getRect(BunnySpriteSheetFrame frame);
		void setAnimation(BunnyAnimation animation);
		BunnyAnimation getAnimation();
		void update();
	};
}