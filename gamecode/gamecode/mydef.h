#pragma once

//************************************************************************
//   M E M O R Y    C O N F I G
//************************************************************************
#define MY_MEMORY_NEDMALLOC 1

// use nedmalloc for default allocator
#define MY_MEMORY_ALLOCATOR MY_MEMORY_NEDMALLOC

#define MY_TRACK_MEMORY

namespace my
{
	typedef unsigned int uint;
}