#include "summator.h"

using namespace godot;
using namespace gutils;

Summator::Summator() : max_speed(0), count(0), mode(0), my_angle(0.0F), speeds(0.0F), char_name(""), mesh_instance(nullptr), input(nullptr) {
}

auto Summator::_notification(int what) -> void {
	switch (what) {
		case NOTIFICATION_READY: {
			input = Input::get_singleton();
			set_process(true);
			set_physics_process(true);
			break;
		}
		case NOTIFICATION_PHYSICS_PROCESS: {
			//INPUT
			if (input->is_action_just_released("ui_accept")) {
				print_line("pressed enter");
			} else if (input->is_action_just_released("left_click")) {
				print_line("left click");
			}
			break;
		}
		case NOTIFICATION_PROCESS: {
			// double dt = get_process_delta_time();
			// print_line("process dt: ", dt);
			break;
		}
		default:
			break;
	}
}

auto Summator::add(int p_value) -> void {
	count += p_value;
}

auto Summator::reset() -> void {
	print_line("setting");
}

auto Summator::get_total() const -> int {
	return count;
}

auto Summator::say_hi() -> void {
	print_line("hello for vitnaaaaam");
}

auto Summator::_bind_methods() -> void {
	REG(Summator, Variant::INT, max_speed)
	REG(Summator, Variant::INT, count)
	REG(Summator, Variant::FLOAT, my_angle)
	REG(Summator, Variant::STRING, char_name)

	REG_HINT(Summator, Variant::FLOAT, speeds, PROPERTY_HINT_RANGE, "0, 100, 0.5, or_greater")
	REG_HINT(Summator, Variant::INT, mode, PROPERTY_HINT_ENUM, "Idle, Walk, Run, Jump")
	REG_HINT(Summator, Variant::NODE_PATH, example_node_path, godot::PROPERTY_HINT_NODE_PATH_VALID_TYPES, "AnimatedSprite2D")

	REG_NODE(Summator, mesh_instance, "MeshInstance3D")
	REG_RESOURCE(Summator, test_resource, "ExampleResource")

	ClassDB::bind_method(D_METHOD("add", "value"), &Summator::add);
	ClassDB::bind_method(D_METHOD("get_total"), &Summator::get_total);

	ClassDB::bind_static_method("Summator", D_METHOD("say_hi"), &Summator::say_hi);
	ClassDB::bind_static_method("Summator", D_METHOD("reset"), &Summator::reset);
}
