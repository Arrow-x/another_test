#pragma once
#include <godot_cpp/classes/ref_counted.hpp>

namespace gutils {

class StatusEffect : public godot::RefCounted { //NOLINT
	GDCLASS(StatusEffect, godot::RefCounted) //NOLINT

protected:
	static void _bind_methods() {};
};
} //namespace gutils
