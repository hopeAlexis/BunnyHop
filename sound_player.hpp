#pragma once
#include <SFML/Audio.hpp>

namespace game {
	class SoundPlayer {
	public:
		static void playJump();
		static void playPickup();
		static void playMusic();
	};
}