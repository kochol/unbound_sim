extends TileMap

# class member variables go here, for example:
# var a = 2
# var b = "textvar"

func _ready():
	for x in range(0, 32):
		for y in range(0, 32):
			set_cell(x, y, 0)

#func _process(delta):
#	# Called every frame. Delta is time since last frame.
#	# Update game logic here.
#	pass
