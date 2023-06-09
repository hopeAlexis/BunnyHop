#pragma once
#include <string>

namespace game {
	class Paths {
	private:
		static bool exists(const std::string& filePath);
		static std::string getAssetsFolderPath();
	public:
		static std::string getBackgroundMusicSoundPath();
		static std::string getJumpSoundPath();
		static std::string getPickupSoundPath();
		static std::string getBunnySpriteSheetTexturePath();
		static std::string getMushroomTexturePath();
		static std::string getMagicBallTexturePath();
		static std::string getBackgroundTexturePath(int background);
		static std::string getCurrentDirectoryPath();
	};
}