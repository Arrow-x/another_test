#pragma once
#include "example_class.h"
#include "macros.h"
#include "test_resource.h"
#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>

class Summator : public godot::Node {
	GDCLASS(Summator, godot::Node);

	EXPORT_VAR(int, max_speed);
	EXPORT_VAR(godot::String, char_name);
	EXPORT_VAR(int, count);
	EXPORT_VAR(float, my_angle);
	EXPORT_VAR(godot::Ref<TestResource>, test_resource)
	EXPORT_VAR(int, mode)
	EXPORT_VAR(float, speed)

	godot::AnimatedSprite2D *example_node;
	ExampleClass *e;

public:
	Summator();
	int get_total() const;
	void say_hi() const;
	void add(int p_value);
	void reset();

	// void _physics_process(double p_delta) override;
	void _input(const godot::Ref<godot::InputEvent> &p_event) override;
	void _notification(int what);

protected:
	static void _bind_methods();
};
