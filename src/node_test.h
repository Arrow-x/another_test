#pragma once

#include <godot_cpp/classes/node.hpp>

class MySpecialNode : public godot::Node {
	GDCLASS(MySpecialNode, Node);

public:
	MySpecialNode();
	void _ready() override;
	void test();

protected:
	static void _bind_methods();
};
