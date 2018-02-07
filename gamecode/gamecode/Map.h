#pragma once
#include "Array2D.h"
#include <Godot.hpp>
#include <TileMap.hpp>

using namespace godot;

namespace my
{
	class Map:public GodotScript<TileMap>
	{
		GODOT_CLASS(Map)

	public:
		//! Constructor
		Map();

		//! Destructor
		~Map();

		//! Init
		void Init(int w, int h);

		void Generate();

		static void _register_methods();

	private:
		int m_iWidth,
			m_iHeight;

		Array2D<int>* m_pMap;
	};
}
