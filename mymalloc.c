#include <stdio.h>
#include <stdint.h>
#include <dlfcn.h>


void * malloc(size_t size)
{
//Static variables keep their values between function calls
	static void * (* wrapped_malloc)(size_t) = NULL;
	if(wrapped_malloc == NULL)
	{
//This will be called the first time our malloc is run
//dlsym returns a function pointer to the "real" libc malloc
		wrapped_malloc = dlsym(RTLD_NEXT,"malloc");
	}
//Pass our call through to the real malloc
	void * retval = wrapped_malloc(size);
//Do extra logging
	printf("malloc(%d)=%p\n",size,retval);
	return retval;
}

/* MacOS compile and run code : 
gcc-4.9 -D_GNU_SOURCE -fPIC -shared -ldl -o mymalloc.so mymalloc.c
DYLD_INSERT_LIBRARIES=./mymalloc.so DYLD_FORCE_FLAT_NAMESPACE=1 date
*/