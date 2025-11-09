#include "example_resource.h"

using namespace godot;
using namespace gutils;

ExampleResource::ExampleResource() {
	test_int = 0;
	test_string = "";
	somefunc({ .s = 3, .m = 0, .v = Vector3(3.4, 5, 5) });
}
float ExampleResource::new_function(const int idx) {
	return float(idx);
}

void ExampleResource::somefunc(const ExampleResource::Psomefunc &p) {
	print_line("the p.s is: ", p.s);
	print_line("the p.m is: ", p.m);
	print_line("the p.v is: ", p.v);
}

void ExampleResource::_bind_methods() {
	REG(ExampleResource, Variant::INT, test_int)
	REG(ExampleResource, Variant::STRING, test_string)
}
