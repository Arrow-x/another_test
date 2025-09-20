#pragma once
#include "macros.h"
#include <godot_cpp/classes/resource.hpp>

class TestResource : public godot::Resource {
	GDCLASS(TestResource, godot::Resource);

	EXPORT_VAR(int, test_int)
	EXPORT_VAR(godot::String, test_string)
public:
	TestResource();
	void test_something() const;

protected:
	static void _bind_methods();
};
