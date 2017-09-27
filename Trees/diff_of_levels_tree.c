#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    int N;
    struct node* left;
    struct node* right;
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
    return n;
}
int maxed(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
int height(node* root)
{
    if ( root == NULL )
    {
        return -1;
    }
    else
    {
        return 1 + maxed( height(root->left), height(root->right) );
    }
}
int odd = 0;
int even = 0;
int cal_diff(node* root, int lev, int level)
{
    if (root == NULL)
        return 0;
    if (level == 1)
       odd = root->data;
    
    if(lev == 1)
       return root->data;
    else if (lev > 1 && level % 2 != 0)
    {
       odd += cal_diff(root->left, lev-1, level);
       odd += cal_diff(root->right, lev-1, level);
    }
    else if(lev > 1 && level % 2 == 0)
    { 
       even += cal_diff(root->left, lev-1, level);
       even += cal_diff(root->right, lev-1, level);
    }
    int res = odd - even;
    return res;
}

void levelOrder(node * root) 
{
    int h = height(root);
    int i, diff;
    for (i=1; i<=h+1; i++)
    {
       diff = cal_diff(root, i, i);
       printf("%d %d %d\n", odd, even, diff);
    }
    printf("%d", diff);
}

int main()
{
    node* tree = NULL;
    tree = insert(tree, 5);
    tree = insert(tree, 2);
    tree = insert(tree, 4);
    tree = insert(tree, 3);
    tree = insert(tree, 6);
    
	tree = insert(tree, 8);
	tree = insert(tree, 7);
	tree = insert(tree, 9);
    levelOrder(tree);  
    return 0;
}
