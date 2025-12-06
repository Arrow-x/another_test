#pragma once
#include <godot_cpp/classes/ref_counted.hpp>

namespace gutils {

class Damage : public godot::RefCounted { //NOLINT

	GDCLASS(Damage, godot::RefCounted) //NOLINT
protected:
	static void _bind_methods() {};
};
} //namespace gutils
