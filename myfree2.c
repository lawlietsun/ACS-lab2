#include <stdio.h>
#include <dlfcn.h>


void free(void *ptr)
{
	static void (* wrapped_free)(void *);
	char *error;

    /* get address of libc free */
	if (wrapped_free == NULL) {
		wrapped_free = dlsym(RTLD_NEXT, "free");
		// check whether has last error
		if ((dlerror()) != NULL) {
			fputs(error, stderr);
			return;
		}
	}
	else
	{
		return;
	}
	printf("free(%p)\n", ptr);     
	wrapped_free(ptr);
}


// MacOS compile code : 
// gcc-4.9 -D_GNU_SOURCE -fPIC -shared -ldl -o myfree.so myfree.c

// MacOS runcode : 
// DYLD_INSERT_LIBRARIES=./myfree.so DYLD_FORCE_FLAT_NAMESPACE=1 ./double_free