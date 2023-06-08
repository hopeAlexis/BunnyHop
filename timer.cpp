#include "timer.hpp"

namespace game {
	Timer::Timer(int delay) : m_delay(delay), m_isStarted(false) {}

	void Timer::restart() {
		m_clock.restart();

		if (!m_isStarted) {
			m_isStarted = true;
		}
	}

	bool Timer::update() {
		if (m_clock.getElapsedTime().asMilliseconds() >= m_delay) {
			return true;
		}
		return false;
	}

	bool Timer::isStarted() {
		return m_isStarted;
	}
}