#pragma once
#include "pickable_item.hpp"

namespace game {
	class Mushroom : public PickableItem {
	public:
		Mushroom();
		void update() override;
	};
}