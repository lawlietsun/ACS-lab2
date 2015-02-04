#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[])
{
	void * some_memory = malloc(100);
	free(some_memory);
	free(some_memory);

	printf("Successddddd\n");
}
