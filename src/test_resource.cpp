#include "test_resource.h"

using namespace godot;

TestResource::TestResource() {
	test_int = 0;
	test_string = "";
}

void TestResource::test_something() const {
	print_line("he");
}

void TestResource::_bind_methods() {
	EXPORT_REG(TestResource, Variant::INT, test_int)
	EXPORT_REG(TestResource, Variant::STRING, test_string)
}
