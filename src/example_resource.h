#pragma once
#include "macros.h"
#include <godot_cpp/classes/resource.hpp>

class ExampleResource : public godot::Resource {
	GDCLASS(ExampleResource, godot::Resource)

	EXPORT_VAR(int, test_int)
	EXPORT_VAR(godot::String, test_string)
public:
	ExampleResource();
	struct Psomefunc {
		int s;
		float m;
		godot::Vector3 v;
	};
	void somefunc(Psomefunc p);

protected:
	static void _bind_methods();
};
