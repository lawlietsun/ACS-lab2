#include <stdio.h>
#include <stdlib.h>

void foo(double argument) 
{
 // Static array allocation 
	int my_array[10];
// dynamic allocation
	int * dynamic_array = malloc(10 * sizeof(int));

}

int main(int argc, char* argv[]) 
{
	foo (42.0) ;
// varibles a_number and my_array have ceased to exist here. 
// The memory pointed to by dynamic_array has not been freed 
// but we have lost our pointer to it. This is a memory leak.
	return 0;
}