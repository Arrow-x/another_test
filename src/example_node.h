#pragma once
//-------------------------------------------
#include "example_resource.h"
#include "macros.h"
#include <godot_cpp/classes/node.hpp>
//-------------------------------------------
namespace gutils {

class ExampleNode : public godot::Node {
	GDCLASS(ExampleNode, godot::Node)

	EXPORT_VAR(godot::Ref<ExampleResource>, my_example_rec);

public:
	ExampleNode();
	void _ready() override;

protected:
	static void _bind_methods();
};

} //namespace gutils
