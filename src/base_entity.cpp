#include "base_entity.h"

using namespace godot;
using namespace gutils;

auto BaseEntity::_bind_methods() -> void {
	ADD_SIGNAL(MethodInfo("damage_taken", PropertyInfo(Variant::OBJECT, "damage", PROPERTY_HINT_RESOURCE_TYPE, "Damage")));
	ADD_SIGNAL(MethodInfo("status_effect_taken", PropertyInfo(Variant::OBJECT, "status_effect", PROPERTY_HINT_RESOURCE_TYPE, "StatusEffect")));
	ADD_SIGNAL(MethodInfo("health_bar_toggled", PropertyInfo(Variant::BOOL, "show")));
}
