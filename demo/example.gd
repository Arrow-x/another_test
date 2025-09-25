extends Node3D


func _process(_delta: float) -> void:
	var special := ExampleClass.new()
	print(special.get_ray_from_viewport(get_viewport(), Vector3.ONE, Vector3.LEFT, 1, true, true))
