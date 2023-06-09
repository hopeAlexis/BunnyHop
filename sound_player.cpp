#include "sound_player.hpp"
#include "paths.hpp"

namespace game {
	void SoundPlayer::playJump() {
		static bool isLoaded = false;

		static sf::Sound jump;
		static sf::SoundBuffer buffer;

		if (!isLoaded) {
			buffer.loadFromFile(Paths::getJumpSoundPath());
			jump.setBuffer(buffer);
			isLoaded = true;
		}
		
		jump.play();
	}

	void SoundPlayer::playPickup() {
		static bool isLoaded = false;

		static sf::Sound pickup;
		static sf::SoundBuffer buffer;

		if (!isLoaded) {
			buffer.loadFromFile(Paths::getPickupSoundPath());
			pickup.setBuffer(buffer);
			isLoaded = true;
		}

		pickup.play();
	}

	void SoundPlayer::playMusic() {
		static bool isLoaded = false;

		static sf::Music background;

		if (!isLoaded) {
			background.openFromFile(Paths::getBackgroundMusicSoundPath());
			background.setLoop(true);
			background.play();
			isLoaded = true;
		}
	}
}