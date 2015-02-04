#include <stdio.h>
#include <stdint.h>
#include <dlfcn.h>
#include <stdlib.h>


void * malloc(size_t size)
{
//Staticvariableskeeptheirvaluesbetweenfunctioncalls
	static void * (* wrapped_malloc)(size_t) = NULL;
	if(wrapped_malloc == NULL)
	{
//Thiswillbecalledthefirsttimeourmallocisrun
//dlsymreturnsafunctionpointertothe"real"libcmalloc
		wrapped_malloc = dlsym(RTLD_NEXT,"malloc");
	}
//Passourcallthroughtotherealmalloc
	void * retval = wrapped_malloc(size);
//Doextralogging
	printf("malloc(%d)=%p\n",size,retval);
	return retval;
}