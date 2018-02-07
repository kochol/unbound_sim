#include "Map.h"

namespace my
{
	Map::Map(): GodotScript(), m_iWidth(0), m_iHeight(0), m_pMap(nullptr)
	{
		Godot::print("Constructor");
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
	}

	void Map::_register_methods()
	{
		register_method("Init", &Map::Init);
		register_method("Generate", &Map::Generate);
		Godot::print("Methods registerd");

	}
}
