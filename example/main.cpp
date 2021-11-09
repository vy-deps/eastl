#include <cstdlib>

class ExampleAllocator
{
	const char* name_;

public:
	ExampleAllocator(const char* name = "ExampleAllocator") : name_(name) {}

	void* allocate(size_t size, int = 0) noexcept { return malloc(size); }
	void* allocate(size_t size, size_t alignment, size_t, int = 0) noexcept { return malloc(size); }
	void deallocate(void* ptr, size_t) noexcept { free(ptr); }
	void deallocate(void* ptr) noexcept { free(ptr); }

	const char* get_name() const noexcept { return name_; }
	void set_name(const char* name) noexcept { name_ = name; }
};

ExampleAllocator g_default_allocator;
inline ExampleAllocator* example_get_default_allocator() noexcept { return &g_default_allocator; }

#define EASTLAllocatorType ExampleAllocator
#define EASTLAllocatorDefault example_get_default_allocator
#define EA_ASSERT_ENABLED

#include <EAAssert/eaassert.h>
#include <EABase/config/eaplatform.h>
#include <EABase/eastdarg.h>
#include <EASTL/array.h>
#include <EASTL/fixed_allocator.h>
#include <EASTL/fixed_hash_map.h>
#include <EASTL/fixed_set.h>
#include <EASTL/fixed_string.h>
#include <EASTL/fixed_vector.h>
#include <EASTL/map.h>
#include <EASTL/scoped_array.h>
#include <EASTL/sort.h>
#include <EASTL/string.h>
#include <EASTL/string_view.h>
#include <EASTL/type_traits.h>
#include <EASTL/unique_ptr.h>
#include <EASTL/vector.h>
#include <EAStdC/EAStdC.h>
#include <EAStdC/EAString.h>
#include <eathread/eathread_mutex.h>

void* operator new(size_t size, const char*, int, unsigned, const char*, int)
{
	return g_default_allocator.allocate(size);
}

void* operator new[](size_t size, const char*, int, unsigned, const char*, int)
{
	return g_default_allocator.allocate(size);
}

void* operator new(size_t size, size_t alignment, size_t, const char*, int, unsigned, const char*, int)
{
	return g_default_allocator.allocate(size, alignment, 0);
}

void* operator new[](size_t size, size_t alignment, size_t, const char*, int, unsigned, const char*, int)
{
	return g_default_allocator.allocate(size, alignment, 0);
}


int main()
{
	EA::StdC::Init();
	printf("hello, world!\n");
	EA::StdC::Shutdown();
	return 0;
}
