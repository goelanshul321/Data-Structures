#include<stdio.h>
#include<stdlib.h>
typedef struct node nn;
struct node
{
    int data;
    struct node* next;
};
/*
void addatbeginning( struct node **h, int v)
{
    struct node *n = (struct node*)malloc( sizeof(struct node) );
    n -> data = v;
    n -> next = *h;
    *h = n;
}
/*
void AddAtGivenPosition( struct node **h, int v, int p )
{
    if( p == 1 )
    {
        addatbeginning(h, v );
    }
    else
    {
        int i = 1;
        struct node *curr = *h ;
        while( ( i < p - 1 ) && curr != NULL )
        curr = curr -> next;
        if( curr != NULL )
        {
            struct node *n = (struct node*)malloc(sizeof(struct node));
            n -> data = v;
            n -> next = curr -> next;
            curr -> next = struct node;
        }
    }

}

int delete(struct node **h)
{
	if(*h == NULL)
	{
		printf("empty");
		return -1;
	}
	else
	{
		struct node *temp = *h;
		*h = *h -> next;
		int x = temp -> data ;
		free(temp);
		temp = NULL;
		return x;
	}
}
void print(struct node *x)
{
    while(x != NULL )
    {
         printf("%d ", x -> data );
         x = x -> next ;
    }
}

int main()
{
 struct node* head = NULL;
 //AddAtGivenPosition(&head, 20, 1);
addatbeginning(&head,20);
print(head);
int x = delete(&head);
printf("\n%d",x);
}
*/
void push( struct node **h, int v)
{
    struct node *n = (struct node*)malloc( sizeof(struct node) );
    n -> data = v;
    n -> next = *h;
    *h = n;
}
void reverse(struct node **h)
{
	struct node **curr = h;
	struct node *first = *h;
	if(first -> next != NULL)
	{
	
	struct node *second = first ->next ;
	while(first && second )
	{
		first -> next = second -> next;
		second -> next =first ;
		*curr = second;
		curr = &(first -> next);
		first = first -> next;
		second = first -> next;
	}
    }
}
void print(struct node *x)
{
    while(x != NULL )
    {
         printf("%d ", x -> data );
         x = x -> next ;
    }
}
int main()
{
	struct node* head=NULL;
	push(&head, 40);
	push(&head, 30);
	push(&head, 20);
	push(&head, 10);
    print(head);
    reverse(&head);
    print(head);
}
