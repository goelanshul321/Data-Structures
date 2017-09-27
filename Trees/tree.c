#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    int data;
    int N;
    struct tree* left;
    struct tree* right;
}node;

node* newnode(int data)
{
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->N = 1;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int SizeOf(node* n)
{
    if(n == NULL)
        return 0;
    return n->N;
}

node* insert(node* n, int data)
{
    if(n == NULL)
        return newnode(data);
    if(data == n->data)
        n->data = data;
    if(data > n->data)
        n->right = insert(n->right, data);
    else
        n->left = insert(n->left, data);
    n->N = 1 + SizeOf(n->left) + SizeOf(n->right);
    return n;
}

int rank(node* n, int key)
{
    if(n == NULL)
        return 0;
    if(key == n->data)
        return SizeOf(n->left);

    else if(key < n->data)
        return rank(n->left, key);
    
    return 1 + SizeOf(n->left) + rank(n->right, key); 
}

int c1 = 0, c2 = 0;

void get_max(node* n)
{
    node* temp = n;
    if(temp == NULL)
        return;
    else if(temp -> right != NULL)
    {
       ++c2;
        temp = temp->right;
        get_max(temp);    
    }
    else if(temp -> right == NULL)
	printf("\nMax = %d", temp->data);
}

void get_min(node* n)
{
    node* temp = n;
    if(temp == NULL)
        return;
    else if(temp -> left != NULL)
    {
       ++c1;
        temp = temp->left;
        get_min(temp);    
    }
    else if(temp -> left == NULL)
	printf("Min = %d", temp->data);
}

int sum1 = 0;

int sum(node* n)
{
    if(n != NULL)
    {
   	 sum(n->left);
   	 sum1 = sum1 + n->data;
   	 sum(n->right);
    }
    if(n == NULL)	
    return sum1; 
}


void print(node* n)
{
    if(n != NULL)
    {
   	 print(n->left);
   	 printf("data = %d N = %d  \n",  n->data, n->N);
   	 print(n->right);
    }
}

node* del_min(node* n)
{
    node* temp = n;
    if(temp == NULL)
        return;
    if(n->left == NULL && n->right != NULL)
    {
        n = n->right;
        return n;
    }
    else if(temp -> left -> left != NULL)
    {
       temp = temp->left;
       del_min(temp);    
    }
    else if(temp -> left->left == NULL)
       temp -> left = n->right;
    return n;
	}

node* del_max(node* n)
{
    node* temp = n;
    node* prev;
    if(temp == NULL)
        return;
    if(n->left != NULL && n->right == NULL)
    {
        n = n->left;
        return n;
    }
    else if(temp -> right -> right != NULL)
    {
       temp = temp->right;
       del_max(temp);    
    }
    else if(temp -> right -> right == NULL)
       temp -> right = n->left;
    return n;
}

int main()
{
    node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 10);
  //  get_min(root);
  //  get_max(root);
  //  int x =  sum(root);
  //  printf("\nSum = %d\n", x);
  //  root = del_min(root);
    print(root);
  //  del_max(root);
  //  print(root);
//    if(c1 > c2)
  // 	 printf("\nHeight = %d", c1+1);
  //  else if(c2 > c1)
  // 	 printf("\nHeight = %d", c2+1);
 //   else
   //      printf("\nHeight = %d", c1+1);
     int key;
     printf("Enter the key \n");
     scanf("%d", &key);
     printf("Rank = %d", rank(root, key) + 1); 
     return 0;
}
