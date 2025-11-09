#include "register_types.h"
#include "example_node.h"
#include "example_ref.h"
#include "example_resource.h"
#include "summator.h"

using namespace godot;

void initialize_gdextension_types(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	// GDREGISTER_RUNTIME_CLASS(ExampleClass)
	GDREGISTER_RUNTIME_CLASS(gutils::ExampleNode)
	GDREGISTER_RUNTIME_CLASS(gutils::ExampleRef)
	GDREGISTER_RUNTIME_CLASS(gutils::Summator)
	GDREGISTER_RUNTIME_CLASS(gutils::ExampleResource)
}

void uninitialize_gdextension_types(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization
GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
	init_obj.register_initializer(initialize_gdextension_types);
	init_obj.register_terminator(uninitialize_gdextension_types);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
