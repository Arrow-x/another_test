#pragma once

#include "macros.h"
#include <godot_cpp/classes/ref_counted.hpp>

class ExampleRef : public godot::RefCounted {
	GDCLASS(ExampleRef, godot::RefCounted)

	EXPORT_VAR(int, something)

public:
	ExampleRef();

protected:
	static void _bind_methods();
};
