extends Node2D

# class member variables go here, for example:
# var a = 2
# var b = "textvar"
export (int) var CameraSpeed
export (int) var ZoomSpeed

var velocity = Vector2()
var zoom = int()

func _ready():
	# Called every time the node is added to the scene.
	# Initialization here
	pass

func _process(delta):
	velocity = Vector2()
	zoom = 0
	if Input.is_action_pressed("ui_up"):
		velocity.y -= 1
	if Input.is_action_pressed("ui_down"):
		velocity.y += 1
	if Input.is_action_pressed("ui_left"):
		velocity.x -= 1
	if Input.is_action_pressed("ui_right"):
		velocity.x += 1
		
	if Input.is_action_pressed("zoom_in"):
		zoom += 1
	if Input.is_action_pressed("zoom_out"):
		zoom -= 1
	
	if velocity.length() > 0:
		velocity = velocity.normalized() * CameraSpeed
		
	$mainCamera.position += velocity * delta
	$mainCamera.zoom.x += zoom * ZoomSpeed * delta
	$mainCamera.zoom.y += zoom * ZoomSpeed * delta
	