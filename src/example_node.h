#pragma once

#include "example_resource.h"
#include "macros.h"
#include <godot_cpp/classes/node.hpp>

class ExampleNode : public godot::Node {
	GDCLASS(ExampleNode, godot::Node)

public:
	ExampleNode();
	void _ready() override;

public:
	EXPORT_VAR(godot::Ref<ExampleResource>, my_example_rec);

protected:
	static void _bind_methods();
};
