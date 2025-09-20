#pragma once

#include "macros.h"
#include <godot_cpp/classes/ref_counted.hpp>

class ExampleClass : public godot::RefCounted {
	GDCLASS(ExampleClass, RefCounted)

protected:
	static void _bind_methods();
	EXPORT_VAR(int, something)

public:
	ExampleClass();
	~ExampleClass() override = default;

	static void test_static();

	void print_type(const godot::Variant &p_variant) const;
	void hello_something() const;
};
