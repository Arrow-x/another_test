#pragma once
//--------------------------------------------------------
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/wrapped.hpp>
//--------------------------------------------------------
namespace gutils {
//--------------------------------------------------------
class BaseEntity : public godot::Node { //NOLINT
	GDCLASS(BaseEntity, godot::Node) //NOLINT

protected:
	static void _bind_methods();
};
} //namespace gutils
