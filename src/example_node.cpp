#include "example_node.h"
#include <godot_cpp/core/print_string.hpp>

using namespace godot;

ExampleNode::ExampleNode() {
	print_line("constructed MySpecialNode");
	// std::cout << "constructed me MySpecialNode\n";
}

void ExampleNode::_ready() {
	print_line("hi this is SpecialNode _ready");
	String s = "something";
	print_line("size of a Resource is: ", sizeof(ExampleResource));
}

void ExampleNode::_bind_methods() {
	EXPORT_REG_HINT(ExampleNode, Variant::OBJECT, my_example_rec, godot::PROPERTY_HINT_RESOURCE_TYPE, "ExampleResource");
}
