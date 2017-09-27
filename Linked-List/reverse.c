#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node* next;
};
void push(struct node **h, int d)
{
    struct node *x = (struct node*)malloc(sizeof(struct node));
    x -> data = d;
    x -> next = *h;
    *h = x;
}

struct node* reverse(struct node* h)
{
     struct node* first =  h;
     struct node* second = h -> next;
     if(second == NULL)
          return first;
     else
     {
          struct node* new = reverse(second);
          second -> next = first;
          first -> next = NULL;
          return new;
     } 
}

void print(struct node *h)
{
     while(h != NULL)
     {
          printf("%d ",h -> data);
          h = h -> next; 
     }
}
int main()
{
     struct node* head = NULL;
     push(&head, 10);
     push(&head, 20);
     push(&head, 30);
     push(&head, 40);  
     print(head);
     head = reverse(head);
     print(head);   
}
