#pragma once

#include "macros.h"
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/physics_ray_query_parameters3d.hpp>

class ExampleClass : public godot::Node3D {
	GDCLASS(ExampleClass, godot::Node3D)

	EXPORT_VAR(int, something)
	godot::Ref<godot::PhysicsRayQueryParameters3D> query;

public:
	ExampleClass();
	~ExampleClass() override = default;

	static void test_static();

	void print_type(const godot::Variant &p_variant) const;
	void hello_something() const;
	godot::Dictionary get_ray_from_viewport(godot::Viewport *node, godot::Vector3 from, godot::Vector3 to, uint32_t physics_layer, bool set_areas, bool set_bodies);

protected:
	static void _bind_methods();
};
