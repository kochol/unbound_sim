#include "Map.h"
#include <ResourceLoader.hpp>

#ifndef CLAMP
#define CLAMP(m_a,m_min,m_max) (((m_a)<(m_min))?(m_min):(((m_a)>(m_max))?m_max:m_a))
#endif

namespace my
{
	Map::Map(): GodotScript(), m_iWidth(0), m_iHeight(0), m_pMap(nullptr)
	{
		Godot::print("Constructor");
		m_rTree1 = ResourceLoader::load("res://sn/objects/tree1.tscn", "PackedScene");
		Godot::print(m_rTree1->get_class());
	}

	Map::~Map()
	{
		MY_DELETE(m_pMap, Array2D);
	}

	void Map::Init(int w, int h)
	{
		m_iWidth = w;
		m_iHeight = h;
		m_pMap = MY_NEW(Array2D<int>(w, h));
	}

	void Map::Generate()
	{
		for (int x = 0; x < m_iWidth; x++)
			for (int y = 0; y < m_iHeight; y++)
				owner->set_cell(x, y, 0);

		for (int i = 0; i < 300; i++)
		{	
			Node2D* tree = (Node2D*)(m_rTree1->instance());
			Vector2 pos(rand() % (m_iWidth * 64), rand() % (m_iHeight * 64));
			pos.x = CLAMP(pos.x, 32, m_iWidth * 64 - 32);
			pos.y = CLAMP(pos.y, 32, m_iHeight * 64 - 32);
			tree->set_position(pos);
			owner->add_child(tree);
		}
	}

	void Map::_register_methods()
	{
		register_method("Init", &Map::Init);
		register_method("Generate", &Map::Generate);
		Godot::print("Methods registerd");

	}
}
