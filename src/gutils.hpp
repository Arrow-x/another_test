#pragma once

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/scene_tree.hpp>

namespace gutils {
inline godot::Node *get_scene_root() {
	godot::SceneTree *scene_tree = godot::Object::cast_to<godot::SceneTree>(
			godot::Engine::get_singleton()->get_main_loop());
	if (!scene_tree) {
		return nullptr;
	}

	godot::Node *root_viewport = scene_tree->get_current_scene();
	if (!root_viewport) {
		return nullptr;
	}
	return root_viewport;
}
} //namespace gutils
