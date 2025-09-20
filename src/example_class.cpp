#include "example_class.h"
#include <godot_cpp/core/class_db.hpp>
// #include "gutils.hpp"
// #include "summator.h"

using namespace godot;

ExampleClass::ExampleClass() {
	print_line("we are constructing ExampleClass");
	something = 0;
	print_line(get_class());
}

void ExampleClass::print_type(const Variant &p_variant) const {
	print_line(vformat("Type: %d", p_variant.get_type()));
}
void ExampleClass::hello_something() const {
	print_line("how it's going dudes lol");
}

void ExampleClass::_bind_methods() {
	ClassDB::bind_method(D_METHOD("hello_something"), &ExampleClass::hello_something);
	ClassDB::bind_static_method("ExampleClass", D_METHOD("test_static"), &ExampleClass::test_static);
	EXPORT_REG(ExampleClass, Variant::INT, something);
}

void ExampleClass::test_static() {
	print_line("static function ran");
}
