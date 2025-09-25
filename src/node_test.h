#pragma once

#include <godot_cpp/classes/node3d.hpp>

class MySpecialNode : public godot::Node3D {
	GDCLASS(MySpecialNode, godot::Node3D)

public:
	MySpecialNode();
	void _ready() override;
	void testing();

protected:
	static void _bind_methods();
};
