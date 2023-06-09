#include "paths.hpp"
#include <filesystem>
#include <iostream>

namespace game {
	bool Paths::exists(const std::string& filePath) {
		return std::filesystem::exists(filePath);
	}

	std::string Paths::getAssetsFolderPath() {
		return Paths::getCurrentDirectoryPath() + "\\assets";
	}

	std::string Paths::getCurrentDirectoryPath() {
		return std::filesystem::current_path().string();
	}

	std::string Paths::getBackgroundMusicSoundPath() {
		std::string path = getAssetsFolderPath() + "\\background.ogg";
		if (!exists(path)) {
			throw std::exception("background music is not found");
		}
		return path;
	}

	std::string Paths::getJumpSoundPath() {
		std::string path = getAssetsFolderPath() + "\\jump.ogg";
		if (!exists(path)) {
			throw std::exception("jump sound is not found");
		}
		return path;
	}

	std::string Paths::getPickupSoundPath() {
		std::string path = getAssetsFolderPath() + "\\pickup.ogg";
		if (!exists(path)) {
			throw std::exception("pickup sound is not found");
		}
		return path;
	}

	std::string Paths::getBunnySpriteSheetTexturePath() {
		std::string path = getAssetsFolderPath() + "\\bunny_spritesheet.png";
		if (!exists(path)) {
			throw std::exception("bunny spritesheet is not found");
		}
		return path;
	}

	std::string Paths::getMushroomTexturePath() {
		std::string path = getAssetsFolderPath() + "\\mushroom.png";
		if (!exists(path)) {
			throw std::exception("mushroom texture is not found");
		}
		return path;
	}

	std::string Paths::getMagicBallTexturePath() {
		std::string path = getAssetsFolderPath() + "\\magic_ball.png";
		if (!exists(path)) {
			throw std::exception("magic ball texture is not found");
		}
		return path;
	}

	std::string Paths::getBackgroundTexturePath(int background) {
		std::string path = getAssetsFolderPath() + "\\" + std::to_string(background) + ".png";
		if (!exists(path)) {
			throw std::exception("background texture is not found");
		}
		return path;
	}
}