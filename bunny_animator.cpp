#pragma once
#include <iostream>
#include "bunny_animator.hpp"
#include "bunny.hpp"

namespace game {
	BunnyAnimator::BunnyAnimator(Bunny* bunny, int delay) :
		m_currentAnimation(BunnyAnimation::None),
		m_currentAnimationFrames(new BunnySpriteSheetFrame[3]),
		m_amountOfFrames(-1),
		m_currentFrameIndex(-1),
		m_timer(250),
		m_bunny(bunny) {}

	sf::IntRect BunnyAnimator::getRect(BunnySpriteSheetFrame frame) {
		switch (frame) {
		case BunnySpriteSheetFrame::Idle1:
			return sf::IntRect(0, 0, 130, 200);
		case BunnySpriteSheetFrame::Idle2:
			return sf::IntRect(130, 0, 130, 200);
		case BunnySpriteSheetFrame::Idle3:
			return sf::IntRect(260, 0, 130, 200);

		case BunnySpriteSheetFrame::MovingLeft1:
			return sf::IntRect(260, 200, 130, 200);
		case BunnySpriteSheetFrame::MovingLeft2:
			return sf::IntRect(390, 200, 130, 200);

		case BunnySpriteSheetFrame::MovingRight1:
			return sf::IntRect(0, 200, 130, 200);
		case BunnySpriteSheetFrame::MovingRight2:
			return sf::IntRect(130, 200, 130, 200);

		case BunnySpriteSheetFrame::IdleBackward1:
			return sf::IntRect(0, 400, 130, 200);
		case BunnySpriteSheetFrame::IdleBackward2:
			return sf::IntRect(130, 400, 130, 200);
		case BunnySpriteSheetFrame::IdleBackward3:
			return sf::IntRect(260, 400, 130, 200);

		case BunnySpriteSheetFrame::Hopping:
			return sf::IntRect(390, 0, 130, 200);
		case BunnySpriteSheetFrame::HoppingBackward:
			return sf::IntRect(390, 400, 130, 200);

		case BunnySpriteSheetFrame::LongIdle:
			return sf::IntRect(0, 600, 130, 200);
		}

		throw std::exception();
	}

	void BunnyAnimator::setAnimation(BunnyAnimation animation) {
		if (m_currentAnimation != animation) {

			switch (animation) {
			case BunnyAnimation::Idle:
				m_amountOfFrames = 3;
				m_currentAnimationFrames[0] = BunnySpriteSheetFrame::Idle1;
				m_currentAnimationFrames[1] = BunnySpriteSheetFrame::Idle2;
				m_currentAnimationFrames[2] = BunnySpriteSheetFrame::Idle3;
				break;
			case BunnyAnimation::IdleBackward:
				m_amountOfFrames = 3;
				m_currentAnimationFrames[0] = BunnySpriteSheetFrame::IdleBackward1;
				m_currentAnimationFrames[1] = BunnySpriteSheetFrame::IdleBackward2;
				m_currentAnimationFrames[2] = BunnySpriteSheetFrame::IdleBackward3;
				break;
			case BunnyAnimation::MovingLeft:
				m_amountOfFrames = 2;
				m_currentAnimationFrames[0] = BunnySpriteSheetFrame::MovingLeft1;
				m_currentAnimationFrames[1] = BunnySpriteSheetFrame::MovingLeft2;
				break;
			case BunnyAnimation::MovingRight:
				m_amountOfFrames = 2;
				m_currentAnimationFrames[0] = BunnySpriteSheetFrame::MovingRight1;
				m_currentAnimationFrames[1] = BunnySpriteSheetFrame::MovingRight2;
				break;
			}

			m_currentAnimation = animation;

			if (animation != BunnyAnimation::None) {
				m_bunny->setRect(getRect(m_currentAnimationFrames[0]));
				m_currentFrameIndex = 0;
			}
			else {
				m_currentFrameIndex = m_amountOfFrames - 1;
			}
		}
	}

	BunnyAnimation BunnyAnimator::getAnimation() {
		return m_currentAnimation;
	}

	void BunnyAnimator::update() {
		if (m_currentAnimation != BunnyAnimation::None) {
			if (!m_timer.isStarted()) {
				m_timer.restart();
				return;
			}

			if (m_timer.update()) {
				m_bunny->setRect(
					getRect(m_currentAnimationFrames[m_currentFrameIndex]));

				if (++m_currentFrameIndex == m_amountOfFrames) {
					m_currentFrameIndex = 0;
				}

				m_timer.restart();
			}
		}
	}
}