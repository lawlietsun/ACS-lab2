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

int count(struct linked_list * list)
{
	int i = 0;
	if(list -> head == NULL)
	{
		return i;
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

void prepend_int(struct linked_list * list, int val)
{
	struct element * elem = malloc(sizeof(struct element));
	elem -> data = val;
	elem -> next = NULL;
	if(list -> head == NULL)
	{
		list -> head = elem;
	}
	else
	{
		struct element * temp = NULL;
		temp = list -> head;
		list -> head = elem;
		elem -> next = temp;
	}
}

void remove_head(struct linked_list * list)
{
	if(list -> head == NULL) //empty list, return empty list, nothing can be removed.
	{
		return;
	}
	else
	{
		struct element * elem = NULL;
		elem = list->head;
		if(elem -> next == NULL) // list with one element(head), remove head. return empty list.
		{
			list->head = NULL;
		}
		else
		{
			list->head = elem->next;
			elem = NULL;
		}
	}
}

void remove_tail(struct linked_list * list)
{
	if(list -> head == NULL) //empty list, return empty list, nothing can be removed.
	{
		return;
	}
	else
	{
		struct element * tail = list -> head;
		if(tail -> next == NULL) // list with one element(head), remove head. return empty list.
		{
			list -> head = NULL;
		}
		else
		{
			struct element * curr = NULL;
			curr = tail;
			while(tail -> next != NULL)
			{
				curr = tail;
				tail = tail -> next;
			}
			curr -> next = NULL;
		}
	}
}

int main(int argc,char * argv[])
{
	struct linked_list * mylist = malloc(sizeof(struct linked_list));

	mylist -> head = NULL;
	
	append_int(mylist,1);
	append_int(mylist,2);
	append_int(mylist,3);
	append_int(mylist,4);
	prepend_int(mylist,0);
	remove_tail(mylist);
	remove_head(mylist);

// print list 
	struct element * tail = mylist -> head;
	if(tail == NULL)
	{
		printf("No element in the list.\n");
	}
	else
	{
		printf("%d\n", tail -> data);
		while(tail -> next != NULL)
		{
			tail = tail -> next;
			printf("%d\n", tail -> data);
		}
		printf("Number of elements is %d\n", count(mylist));
	}

	free(mylist);

	return 0;
}
