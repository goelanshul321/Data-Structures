#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int data;
	struct list* next;
}list;

void push(list **head, int data)
{
	list* newnode = (list*)malloc(sizeof(list));
	newnode->data = data;
	newnode->next = *head;
	*head = newnode;
}

void swap(list **head, int x, int y)
{
	if(x == y)
	return;
	
	list *prevx = NULL;
	list *tempx = *head;
	while(tempx && tempx->data != x)
	{
		prevx = tempx;
		tempx = tempx->next;
	}
	
	list *prevy = NULL;
	list *tempy = *head;
	while(tempy && tempy->data != y)
	{
		prevy = tempy;
		tempy = tempy->next;
	}
	
	if(tempx == NULL || tempy == NULL)
	return;
	
	if(prevx != NULL)
		prevx->next = tempy;
	else
	    *head = tempy;
	
	if(prevy != NULL)
		prevy->next = tempx;
	else
	    *head = tempx;
	
	list *newnode = tempx->next;
	tempx->next = tempy->next;
	tempy->next = newnode;
	
}

void print(list *head)
{
	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}
int main()
{
	list* head = NULL;
	push(&head, 10);
	push(&head, 15);
	push(&head, 12);
	push(&head, 13);
	push(&head, 20);
	push(&head, 14);
	print(head);
	swap(&head, 12, 20);
	printf("\n");
	print(head);
}
