#include "example_ref.h"

using namespace godot;

ExampleRef::ExampleRef() {
	something = 69;
}

void ExampleRef::_bind_methods() {
	EXPORT_REG(ExampleRef, Variant::INT, something);
}
