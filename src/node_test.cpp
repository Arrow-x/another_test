#include "node_test.h"

using namespace godot;

MySpecialNode::MySpecialNode() {
	// print_line("constructed MySpecialNode");
	// std::cout << "constructed me MySpecialNode\n";
}
void MySpecialNode::_ready() {
	print_line("hi s");
}
/**
greeetings
**/
void MySpecialNode::testing() {
	print_line("testin");
}

void MySpecialNode::_bind_methods() {
}
