#include<stdio.h>
#include<stdlib.h>
struct queue 
{
	int head, capacity;
	int tail, size;	
	int *array;
	int c;
};
struct queue* createqueue(int y)
{
	struct queue* que=(struct queue*)malloc(sizeof(struct queue));
	que -> head = que -> size = 0;
	que -> tail = 6;
	que -> c = 7;
	que -> capacity = y;
	que -> array = (int*)malloc(y*sizeof(int));
	return que;
}
int isfull(struct queue* x)
{
	return x -> size == 6;
}
int empty(struct queue* x)
{
	return x -> size == 0;
}
void push(struct queue* x,int y)
{
	if(isfull(x))
	printf("OVERFLOW");
	else
	{
		x -> array[x -> head++] = y;
		x -> size = x -> size + 1;
	}
}
int pop(struct queue* x)
{
	if(empty(x))
	return printf("UNDERFLOW");
	else
	{
		x -> c = x -> c - 1;
		return x -> array[x -> tail - x -> c];
	}
}
int  main()
{
	struct queue* que = createqueue(7);
	push(que, 10);
	push(que, 20);
	printf("%d",pop(que));
}
