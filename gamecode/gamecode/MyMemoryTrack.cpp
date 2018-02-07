#include "MyMemoryTrack.h"
#include <cstdio>
#include <map>
#include "MyMemory.h"
#include <Godot.hpp>

namespace my
{
	static std::map<size_t, MemoryInfo*>		g_sMemory;

	//------------------------------------------------------------------------------------
	// Add memory
	//------------------------------------------------------------------------------------
	void MyMemoryTrack::AddMemory(void* ptr, uint BytesCount, const char* file, int line, const char* function)
	{
#		ifdef MY_TRACK_MEMORY
		static uint AllocNo = 0;
		AllocNo++;
		MemoryInfo* mi = new MemoryInfo;
		mi->Data = ptr;
		mi->BytesCount = BytesCount;
		mi->FileName = file;
		mi->Line = line;
		mi->Function = function;
		mi->AllocNo = AllocNo;
		g_sMemory[(size_t)ptr] = mi;

#		endif // MY_TRACK_MEMORY

	} // AddMemory

		//------------------------------------------------------------------------------------
		// Removes memory
		//------------------------------------------------------------------------------------
	bool MyMemoryTrack::RemoveMemory(void* ptr)
	{
#		ifdef MY_TRACK_MEMORY
		std::map<size_t, MemoryInfo*>::iterator it = g_sMemory.find((size_t)ptr);
		if (it == g_sMemory.end())
		{
			char str[128];
			sprintf_s(str, "The %d pointer is not allocated with MY_NEW or it was deallocated already.", (size_t)ptr);
			godot::Godot::print_error(godot::String(str), "RemoveMemory", "MyMemoryTrack", __LINE__);
			return false;
		}

		delete it->second;
		g_sMemory.erase(it);

#		endif // MY_TRACK_MEMORY

		return true;

	} // RemoveMemory

		//------------------------------------------------------------------------------------
		// Logs memory leakages
		//------------------------------------------------------------------------------------
	void MyMemoryTrack::LogMemoryLeaks()
	{
#		ifdef MY_TRACK_MEMORY
		if (g_sMemory.empty())
		{
			godot::Godot::print("Congratulation no memory leaks found :)");
			return;
		}
		std::map<size_t, MemoryInfo*>::iterator it;
		MemoryInfo* mi;
		int bytes = 0;
		char str[128];
		godot::Godot::print("No   \tAddress\t\tsize\tfunction            \tline\tfile");
		for (it = g_sMemory.begin(); it != g_sMemory.end(); it++)
		{
			mi = it->second;
			bytes += mi->BytesCount;
			sprintf_s(str, "%05d\t0x%08X\t%d\t%-20s\t%d\t%s", mi->AllocNo, mi->Data, mi->BytesCount,
				mi->Function, mi->Line, mi->FileName);
			godot::Godot::print(godot::String(str));
		}
		sprintf_s(str, "%d memory leaks found.\n%d Bytes in size.", g_sMemory.size(), bytes);
		godot::Godot::print(godot::String(str));
#		endif

	} // LogMemoryLeaks
} // my
