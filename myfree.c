#include <stdio.h>
#include <dlfcn.h>


void free(void *ptr)
{
	static void (*freep)(void *);
	char *error;

    /* get address of libc free */
	if (!freep) {
		freep = dlsym(RTLD_NEXT, "free");
		if ((error = dlerror()) != NULL) {
			fputs(error, stderr);
			return;
		}
	}
	else
	{
		return;
	}
	printf("free(%p)\n", ptr);     
	freep(ptr);
}


// macos compile code : gcc-4.9 -D_GNU_SOURCE -fPIC -shared -ldl -o myfree.so myfree.c
// macos runcode : DYLD_INSERT_LIBRARIES=./myfree.so DYLD_FORCE_FLAT_NAMESPACE=1 ./double_free