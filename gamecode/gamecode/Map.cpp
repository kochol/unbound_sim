#include "Map.h"

namespace my
{
	Map::Map(): m_pMap(nullptr)
	{
	}

	Map::~Map()
	{
	}

	void Map::Init(int w, int h)
	{
		m_iWidth = w;
		m_iHeight = h;
		m_pMap = new Array2D<int>(w, h);
	}
}
