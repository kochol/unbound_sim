#pragma once

#include "mydef.h"

namespace my
{
	struct MemoryInfo
	{
		void*			Data;
		uint			BytesCount;
		const char*		FileName;
		const char*		Function;
		int				Line;
		uint			AllocNo;

	}; // MemoryInfo

	//! Tracks the memory for memory leaks
	class MyMemoryTrack
	{
	public:

		//! Add memory
		static void AddMemory(void* ptr, uint BytesCount, const char* file = 0, int line = 0, const char* function = 0);

		//! Removes memory
		static bool RemoveMemory(void* ptr);

		//! Logs memory leakages
		static void LogMemoryLeaks();

	protected:

	}; // MyMemoryTrack

} // my
