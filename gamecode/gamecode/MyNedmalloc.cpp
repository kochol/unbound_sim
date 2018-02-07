#include "MyNedmalloc.h"
#include "nedmalloc/nedmalloc.c"
#include "MyMemoryTrack.h"

namespace my
{
	//------------------------------------------------------------------------------------
	// Allocate bytes
	//------------------------------------------------------------------------------------
	void* MyNedmalloc::AllocateBytes(uint BytesCount, const char* file, int line, const char* function)
	{
		// Allocate bytes
		void* ret = nedalloc::nedmalloc(BytesCount);

		// Track memory
		MyMemoryTrack::AddMemory(ret, BytesCount, file, line, function);

		return ret;

	} // AllocateBytes

		//------------------------------------------------------------------------------------
		// Deallocate bytes
		//------------------------------------------------------------------------------------
	void MyNedmalloc::DeallocateBytes(void* ptr)
	{
		// Remove memory from tracker
		MyMemoryTrack::RemoveMemory(ptr);

		// Free memory
		nedalloc::nedfree(ptr);

	} // DeallocateBytes

		//------------------------------------------------------------------------------------
		// Reallocate bytes
		//------------------------------------------------------------------------------------
	void* MyNedmalloc::ReallocateBytes(void* ptr, uint BytesCount, const char* file /*= 0*/, int line /*= 0*/, const char* function /*= 0*/)
	{
		// Allocate bytes
		void* ret = nedalloc::nedrealloc(ptr, BytesCount);

		// Track memory
		MyMemoryTrack::RemoveMemory(ptr);
		MyMemoryTrack::AddMemory(ret, BytesCount, file, line, function);

		return ret;

	} // ReallocateBytes

} // kge
