#pragma once
#include "randomizer.hpp"
#include <ctime>
#include <cstdlib>

namespace game {
	int Randomizer::Next(int min, int max) {
		static bool isSeedSetted = false;
		if (!isSeedSetted) {
			srand(time(NULL));
			isSeedSetted = true;
		}

		return min + rand() % ((max + 1) - min);
	}
}