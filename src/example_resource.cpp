#include "example_resource.h"
#include <godot_cpp/core/print_string.hpp>
#include <godot_cpp/variant/vector3.hpp>

using namespace godot;

ExampleResource::ExampleResource() {
	test_int = 0;
	test_string = "";
	somefunc({ .s = 3, .v = Vector3(3.4, 5, 5) });
}
void ExampleResource::somefunc(ExampleResource::Psomefunc p) {
	print_line("the p.s is: ", p.s);
	print_line("the p.m is: ", p.m);
	print_line("the p.v is: ", p.v);
}

void ExampleResource::_bind_methods() {
	REG(ExampleResource, Variant::INT, test_int)
	REG(ExampleResource, Variant::STRING, test_string)
}
