#pragma once

#include "mydef.h"
#include "MyNedmalloc.h"
#include <new>

namespace my
{
#	if MY_MEMORY_ALLOCATOR == MY_MEMORY_NEDMALLOC
	class MyMemory : public my::MyNedmalloc {};

#	endif

} // my

  //! Use MY_NEW instead of new to track memory leaks and use internal MY allocator that is faster
  //!	example \code my::Device* pDev = MY_NEW(my::Device)(/*Constructor values*/); \endcode
#define MY_NEW(T) new (my::MyMemory::AllocateBytes(sizeof(T), __FILE__, __LINE__, __FUNCTION__)) T

  //! If you use MY_NEW to allocate memory then you have to use MY_DELETE to deallocate it and free memory.
  //! First parameter is pointer the second one is class name without anything else like namespace only class name or its parent name
  //!	example \code MY_DELETE(pDev, Device); \endcode
#define MY_DELETE(ptr, T) if (ptr) {(ptr)->~T(); my::MyMemory::DeallocateBytes(ptr); ptr = NULL; }
#define MY_DELETETHIS(ptr, T) if (ptr) {(ptr)->~T(); my::MyMemory::DeallocateBytes(ptr); }

#define MY_NEW_ARRAY(T, count) (T*) my::MyMemory::AllocateBytes(sizeof(T) * count, __FILE__, __LINE__, __FUNCTION__)
#define MY_NEW_CLASS_ARRAY(T, count) (new (my::MyMemory::AllocateBytes(sizeof(T) * count + 4, __FILE__, __LINE__, __FUNCTION__)) T[count])
#define MY_DELETE_ARRAY(ptr) if (ptr) { my::MyMemory::DeallocateBytes(ptr); ptr = NULL; }
#ifdef _MSC_VER
#define MY_DELETE_CLASS_ARRAY(ptr, T, count) if (ptr) { 	for (int i = 0; i < count; i++) ptr[i].~T(); my::MyMemory::DeallocateBytes((void*)((unsigned long long)ptr - sizeof(void*))); ptr = NULL; }
#else
#define MY_DELETE_CLASS_ARRAY(ptr, T, count) if (ptr) { 	for (int i = 0; i < count; i++) ptr[i].~T(); my::MyMemory::DeallocateBytes(ptr); ptr = NULL; }
#endif

#define MY_REALLOC_ARRAY(ptr, T, count)(T*)my::MyMemory::ReallocateBytes(ptr, sizeof(T) * count, __FILE__, __LINE__, __FUNCTION__)
