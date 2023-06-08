#include "sound_player.hpp"

namespace game {
	void SoundPlayer::playJump() {
		static bool isLoaded = false;

		static sf::Sound jump;
		static sf::SoundBuffer buffer;

		if (!isLoaded) {
			buffer.loadFromFile("assets//jump.ogg");
			jump.setBuffer(buffer);
			isLoaded = true;
		}

		jump.play();
	}

	void SoundPlayer::playMusic() {
		static bool isLoaded = false;

		static sf::Music background;

		if (!isLoaded) {
			background.openFromFile("assets//background.ogg");
			background.setLoop(true);
			background.play();
			isLoaded = true;
		}
	}
}