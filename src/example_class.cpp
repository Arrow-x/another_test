#include "example_class.h"
#include <godot_cpp/classes/physics_direct_space_state3d.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/classes/world3d.hpp>
// #include "summator.h"

using namespace godot;

ExampleClass::ExampleClass() {
	something = 0;
	query = PhysicsRayQueryParameters3D::create(Vector3(0, 0, 0), Vector3(0, 0, 0), 1);
}

Dictionary ExampleClass::get_ray_from_viewport(Viewport *node, Vector3 from, Vector3 to, uint32_t physics_layer, bool set_areas, bool set_bodies) {
	print_line("size of queray object: ", sizeof(query));
	query->set_from(from);
	query->set_to(to);
	query->set_collision_mask(physics_layer);
	query->set_collide_with_areas(set_areas);
	query->set_collide_with_bodies(set_bodies);
	return node->get_world_3d()->get_direct_space_state()->intersect_ray(query);
}

void ExampleClass::print_type(const Variant &p_variant) const {
	print_line(vformat("Type: %d", p_variant.get_type()));
}

void ExampleClass::hello_something() const {
	print_line("how it's going dudes lol");
}

void ExampleClass::_bind_methods() {
	ClassDB::bind_method(D_METHOD("hello_something"), &ExampleClass::hello_something);
	ClassDB::bind_method(D_METHOD("get_ray_from_viewport", "viewport", "from", "to", "physics_layer", "set_areas", "set_bodies"), &ExampleClass::get_ray_from_viewport);
	ClassDB::bind_static_method("ExampleClass", D_METHOD("test_static"), &ExampleClass::test_static);
	EXPORT_REG(ExampleClass, Variant::INT, something);
}

void ExampleClass::test_static() {
	print_line("static function ran");
}
