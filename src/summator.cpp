#include "summator.h"
#include "example_class.h"
#include "macros.h"
#include <godot_cpp/classes/input_event_mouse_motion.hpp>

using namespace godot;

Summator::Summator() {
	count = 0;
	max_speed = 94;
	mode = 0;
	set_process(true);
}

void Summator::_notification(int p_notification) {
	switch (p_notification) {
		case NOTIFICATION_ENTER_TREE:
			print_line("we entered the tree");
			break;
		case NOTIFICATION_READY:
			example_node = Object::cast_to<AnimatedSprite2D>(find_child("example_node"));
			e = Object::cast_to<ExampleClass>(ClassDB::instantiate("ExampleClass"));
			e->something = 0;
			break;
		case NOTIFICATION_PROCESS:
			break;
		case NOTIFICATION_PHYSICS_PROCESS:
			break;
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
	e->something++;
	print_line(e->get_something());
	ClassDB::class_call_static("ExampleClass", "test_static");
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
