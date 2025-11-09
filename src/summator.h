#pragma once

#include "example_ref.h"
#include "example_resource.h"
#include "macros.h"

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>

namespace gutils {

class Summator : public godot::Node {
	GDCLASS(Summator, godot::Node)

	EXPORT_VAR(int, max_speed);
	EXPORT_VAR(int, count);
	EXPORT_VAR(int, mode)
	EXPORT_VAR(float, my_angle);
	EXPORT_VAR(float, speeds)
	EXPORT_VAR(godot::String, char_name);
	EXPORT_VAR(godot::Ref<gutils::ExampleResource>, test_resource)
	EXPORT_VAR(godot::NodePath, example_node_path)
	EXPORT_NODE(godot::MeshInstance3D, mesh_instance);

private:
	godot::Ref<ExampleRef> n;
	godot::Input *input;

public:
	Summator();

	// void _physics_process(double p_delta) override;
	void _notification(int what);
	void _input(const godot::Ref<godot::InputEvent> &p_event) override;

	int get_total() const;
	void say_hi() const;
	void add(int p_value);
	void reset();

protected:
	static void _bind_methods();
};

struct Simple {
};
} //namespace gutils
