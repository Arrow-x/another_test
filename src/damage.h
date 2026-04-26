#include <cstdint>
namespace gutils {

enum class DamageTypes : std::uint8_t { FIRE,
										ICE,
										ELECTRIC };

struct DamageInfo {
	int amount;
	DamageTypes type;
};
} //namespace gutils
