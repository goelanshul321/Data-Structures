#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
 
typedef struct Node node;
void push(struct Node** head_ref, int new_data)
{
		 struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
		 new_node->data = new_data;
		 new_node->next = *head_ref;
		 *head_ref = new_node;
}

Node* reverse(Node* h)
{
     Node* first =  h;
     Node* second = h -> next;
     if(second == NULL)
          return first;
     else
     {
          Node* newnode = reverse(second);
          second -> next = first;
          first -> next = NULL;
          return newnode;
     } 
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}
 
void swapPointer( Node** a, Node** b )
{
    node* t = *a;
    *a = *b;
    *b = t;
}

int getSize(struct Node *node)
{
    int size = 0;
    while (node != NULL)
    {
        node = node->next;
        size++;
    }
    return size;
}
 
node* addSameSize(Node* head1, Node* head2, int* carry)
{
    if (head1 == NULL)
        return NULL;
 
    int sum;
    Node* result = (Node *)malloc(sizeof(Node));
    result->next = addSameSize(head1->next, head2->next, carry);
    sum = head1->data + head2->data + *carry;
    *carry = sum / 10;
    sum = sum % 10;
    result->data = sum;
 
    return result;
}
 
void addCarryToRemaining(Node* head1, Node* cur, int* carry, Node** result)
{
    int sum;
 
    if (head1 != cur)
    {
        addCarryToRemaining(head1->next, cur, carry, result);
 
        sum = head1->data + *carry;
        *carry = sum/10;
        sum %= 10;
 
        push(result, sum);
    }
}
 
Node* addList(Node* head1, Node* head2)
{
    Node *cur;
    Node* result;
    if (head1 == NULL)
    {
        result = head2;
        return result;
    }
    else if (head2 == NULL)
    {
        result = head1;
        return result;
    }
    head1 = reverse(head1);
    head2 = reverse(head2);
    int size1 = getSize(head1);
    int size2 = getSize(head2) ;
 
    int carry = 0;
 
    if (size1 == size2)
        result = addSameSize(head1, head2, &carry);
 
    else
    {
       if(size1<size2)
            swapPointer(&head1, &head2);
        Node* current = head1;
        int diff = abs(size1 - size2);
        for (current = head1; diff--; current = current->next);
        result = addSameSize(current, head2, &carry);
        addCarryToRemaining(head1, current, &carry, &result);
    }
 
    if (carry)
        push(&result, carry);
        result = reverse(result);
        return result;
}
 
int main()
{
    Node *head1 = NULL, *head2 = NULL, *result = NULL;
 
    int arr1[] = {9, 9, 1};
    int arr2[] = {1};
 
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int i;
    for (i = size1-1; i >= 0; --i)
        push(&head1, arr1[i]);

    for (i = size2-1; i >= 0; --i)
        push(&head2, arr2[i]);
 
    result = addList(head1, head2);
 
    printList(result);
 
    return 0;
}
