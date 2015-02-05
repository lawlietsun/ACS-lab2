#include <stdio.h>
#include <stdlib.h>


struct element
{
	struct element * next;
	void * data;
};

struct linked_list
{
	struct element * head;
};

void append_int(struct linked_list * list, void * val)
{
	struct element * elem = malloc(sizeof(struct element));
	elem -> data = val;
	elem -> next = NULL;//Really important to explicitly set this to null. Malloc does not zero memory
	if(list->head==NULL)
	{
//Empty list, we need to append to head
		list->head=elem;
	}
	else
	{
//List has some elements, find the end and append to that
		struct element * tail = list -> head;
		while(tail -> next != NULL)
		{
			tail = tail -> next;
		}
		tail -> next = elem;
	}
}

int main(int argc, char * argv[])
{
	void * some_memory = malloc(100);
	void * another_memory = malloc(100);
	void * other_memory = malloc(100);
	free(some_memory);
	free(some_memory);
	free(another_memory);
	free(other_memory);


	printf("Success\n");

	struct linked_list * mylist = malloc(sizeof(struct linked_list));

	mylist -> head = NULL;
	
	append_int(mylist, some_memory);
	append_int(mylist, another_memory);
	append_int(mylist, other_memory);

	// print list 
	struct element * tail = mylist -> head;
	if(tail == NULL)
	{
		printf("No element in the list.\n");
	}
	else
	{
		printf("List contain:\n");
		printf("%p\n", tail -> data);
		while(tail -> next != NULL)
		{
			tail = tail -> next;
			printf("%p\n", tail -> data);
		}
		// printf("Number of elements is %d\n", count(mylist));
	}

	free(mylist);

	return 0;

}
