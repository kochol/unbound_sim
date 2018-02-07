#pragma once
#include "mydef.h"

namespace my
{
	//! Ned allocator class
	class MyNedmalloc
	{
	public:

		//! Allocate bytes
		static void* AllocateBytes(uint BytesCount, const char* file = 0, int line = 0, const char* function = 0);

		//! Deallocate bytes
		static void DeallocateBytes(void* ptr);

		//! Reallocate bytes
		static void* ReallocateBytes(void* ptr, uint BytesCount, const char* file = 0, int line = 0, const char* function = 0);

	}; // KgeNedmalloc

}
