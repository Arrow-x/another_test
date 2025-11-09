#include "example_ref.h"
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/variant/callable_method_pointer.hpp>
#include <godot_cpp/variant/signal.hpp>

using namespace godot;
using namespace gutils;

ExampleRef::ExampleRef() {
	something = 69;
}
void ExampleRef::_bind_methods() {
	// REG(ExampleRef, Variant::INT, something);
	ClassDB::add_signal(get_class_static(), MethodInfo(("something_to")));
	// ADD_SIGNAL(MethodInfo((signals::example_signal)));
}
