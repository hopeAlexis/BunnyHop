#include "pickable_item.hpp"

namespace game {
	class MagicBall : public PickableItem {
	public:
		MagicBall();
		void update() override;
	};
}