#include "summator.h"
#include "defer.hpp"
#include "macros.h"
#include <godot_cpp/core/print_string.hpp>

using namespace godot;

Summator::Summator() {
	max_speed = 94;
	char_name = "hi";
	count = 0;
	my_angle = 1.0f;
	test_resource = Ref<ExampleResource>();
	mode = 0;
	speed = 0.0f;
	example_node = nullptr;
	e = nullptr;
	query = PhysicsRayQueryParameters3D::create(Vector3(0, 0, 9), Vector3(4, 4, 4));
}

void Summator::_notification(int p_notification) {
	switch (p_notification) {
		case NOTIFICATION_ENTER_TREE:
			break;
		case NOTIFICATION_READY: {
			set_process(true);
			set_physics_process(true);
			// auto n = memnew(MySpecialNode);
			// DEFER({ memfree(n); });
			//
			// add_child(n);
			// auto *n = memnew(Node3D);
			// DEFER({ memfree(n); });
			// print_line("size of a generic Node3D is: ", sizeof(*n));
			//
			// auto *o = memnew(Object);
			// DEFER({ memfree(o); });
			// print_line("size of a generic Object is: ", sizeof(*o));
			//
			// auto *r = memnew(RefCounted);
			// DEFER({ memfree(r); });
			// print_line("size of a generic RefCounted is: ", sizeof(*r));
			//
			// auto *m = new Simple();
			// DEFER({ delete m; });
			// print_line("size of a generic Struct is: ", sizeof(*m));
			// print_line("size of Summator is: ", sizeof(*this));
			break;
		}
		case NOTIFICATION_PHYSICS_PROCESS: {
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
	} else if (p_event->is_action_pressed("left_click")) {
		print_line("you pressed left click");
		add(3);
	}
}

void Summator::add(int p_value) {
	count += p_value;
}

void Summator::reset() {
	count = 0;
}

int Summator::get_total() const {
	return count;
}

void Summator::say_hi() const {
	print_line("hello for vitnaaaaam");
}

void Summator::_bind_methods() {
	EXPORT_REG(Summator, Variant::INT, max_speed)
	EXPORT_REG(Summator, Variant::STRING, char_name)
	EXPORT_REG(Summator, Variant::INT, count)
	EXPORT_REG(Summator, Variant::FLOAT, my_angle)

	EXPORT_REG_HINT(Summator, Variant::OBJECT, test_resource, PROPERTY_HINT_RESOURCE_TYPE, "TestResource")
	EXPORT_REG_HINT(Summator, Variant::INT, mode, PROPERTY_HINT_ENUM, "Idle,Walk,Run,Jump")
	EXPORT_REG_HINT(Summator, Variant::FLOAT, speed, PROPERTY_HINT_RANGE, "0,100,0.5,or_greater")

	ClassDB::bind_method(D_METHOD("add"), &Summator::add);
}
