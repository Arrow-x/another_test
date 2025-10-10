#include "example_node.h"
#include "example_ref.h"

using namespace godot;

ExampleNode::ExampleNode() {
	print_line("constructed MySpecialNode");
	// std::cout << "constructed me MySpecialNode\n";
}

void ExampleNode::_ready() {
	print_line("hi this is SpecialNode _ready");
	String s = "something";
	Ref<ExampleResource> m = memnew(ExampleResource);
	Ref<ExampleRef> f = memnew(ExampleRef);
	print_line("size of a Resource is**: ", sizeof(**m));
	print_line("size of a RefCounted is**: ", sizeof(**f));
}

void ExampleNode::_bind_methods() {
	REG_HINT(ExampleNode, Variant::OBJECT, my_example_rec, godot::PROPERTY_HINT_RESOURCE_TYPE, "ExampleResource");
}
