#pragma once
#include "Array2D.h"

namespace my
{
	class Map
	{
	public:
		//! Constructor
		Map();

		//! Destructor
		~Map();

		//! Init
		void Init(int w, int h);

	private:
		int m_iWidth,
			m_iHeight;

		Array2D<int>* m_pMap;
	};
}
