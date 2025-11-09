#include "summator.h"

using namespace godot;
using namespace gutils;

Summator::Summator() {
	max_speed = 94;
	char_name = "hi";
	count = 0;
	my_angle = 1.0f;
	mode = 0;
	speeds = 0.0f;
}

void Summator::_notification(int p_notification) {
	switch (p_notification) {
		case NOTIFICATION_ENTER_TREE: {
			input = Input::get_singleton();
			set_process(true);
			set_physics_process(true);
			break;
		}
		case NOTIFICATION_READY: {
			n = Ref<ExampleRef>(memnew(ExampleRef));
			n->connect("something_to", callable_mp(this, &Summator::reset));
			break;
		}
		case NOTIFICATION_PHYSICS_PROCESS: {
			//INPUT
			if (input->is_action_just_released("ui_accept")) {
				print_line("pressed enter");
			} else if (input->is_action_just_released("left_click")) {
				print_line("left click");
			}
			// double pdt = get_physics_process_delta_time();
			// print_line("phyics process: ", pdt);
			break;
		}
		case NOTIFICATION_PROCESS: {
			// double dt = get_process_delta_time();
			// print_line("process dt: ", dt);
			break;
		}
	}
}

void Summator::_input(const Ref<InputEvent> &p_event) {
	if (p_event->is_action_pressed("ui_accept")) {
		print_line("hit enter");
		n->emit_signal("something_to");

	} else if (p_event->is_action_pressed("left_click")) {
		print_line("you pressed left click");
		n->emit_signal("something_to");
		add(3);
	}
}

void Summator::add(int p_value) {
	count += p_value;
}

void Summator::reset() {
	print_line("setting");
}

int Summator::get_total() const {
	return count;
}

void Summator::say_hi() const {
	print_line("hello for vitnaaaaam");
}

void Summator::_bind_methods() {
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
	ClassDB::bind_method(D_METHOD("say_hi"), &Summator::say_hi);
}
