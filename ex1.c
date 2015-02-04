#include <stdio.h>
#include <stdlib.h>

struct element
{
	struct element * next;
	int data;
};

struct linked_list
{
	struct element * head;
};

void append_int(struct linked_list * list, int val)
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

void prepend_int(struct linked_list * list, int val)
{
	struct element * elem = malloc(sizeof(struct element));
	elem -> data = val;
	elem -> next = NULL;
	if(list->head==NULL)
	{
		list->head=elem;
	}
	else
	{
		struct element * temp = NULL;
		temp = list -> head;
		list -> head = elem;
		elem -> next = temp;
	}
}

//cannot remove only one item
void remove_tail(struct linked_list * list){
	if(list->head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct element * tail = list -> head;
		struct element * curr = NULL;
		curr = tail;
		while(tail -> next != NULL)
		{
			curr = tail;
			tail = tail -> next;
		}
		free(curr);
	}
}


void remove_head(struct linked_list * list){
	if(list->head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct element * elem = NULL;
		elem = list->head;
		list->head = elem->next;
		elem = NULL;
	}
}


int count(struct linked_list * list){
	int i = 0;
	if(list->head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		i = 1;
		struct element * tail = list -> head;
		while(tail -> next != NULL)
		{
			i++;
			tail = tail -> next;
		}
	}
	return i;
}


int main()
{
	struct linked_list * mylist = malloc(sizeof(struct linked_list));
	append_int(mylist,1);
	append_int(mylist,2);
	append_int(mylist,3);
	append_int(mylist,4);
	prepend_int(mylist,111);
	append_int(mylist,5);
	append_int(mylist,6);
	append_int(mylist,7);
	append_int(mylist,8);
	append_int(mylist,9);
	prepend_int(mylist,122);
	prepend_int(mylist,133);
	prepend_int(mylist,144);
	append_int(mylist,10);
	remove_tail(mylist);
	remove_head(mylist);

// print list 
	struct element * tail = mylist -> head;
	printf("%d\n", tail -> data);
	while(tail -> next != NULL)
	{
		tail = tail -> next;
		printf("%d\n", tail -> data);
	}

	printf("Number of elements = %d\n", count(mylist));

	free(mylist);

	return 0;
}
