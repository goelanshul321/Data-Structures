#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Tree
{
    char * str;
    int length;
    int count;
    struct Tree *left, *right;
}tree;

tree* new_node(tree* root, char key[])
{
    tree* temp = (tree*)malloc(sizeof(tree));
    temp -> str = (char*)malloc(1000 * sizeof(char));

    strcpy(temp -> str, key);
    temp -> count = 1;
    temp -> left = NULL;
    temp -> right = NULL;

    return temp;

}

tree* insert(tree* root, char key[])
{
     if(root == NULL) return new_node(root, key);

     if(strcmp(root -> str, key) == 0)
     {
         root -> count = root -> count + 1;
         return root;
     }
     if(strcmp(root -> str, key) < 0)
     root -> right = insert(root -> right, key);

     if(strcmp(root -> str, key) > 0)
     root -> left = insert(root -> left, key);
     return root;
}

tree* search(tree* root, int key)
{

    if (root == NULL || root->count == key)
      { printf("%s\n", root -> str); return root;}

    // Key is greater than root's key
    if (root->count < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

void removes(char buff[], char c[])
{
    int i = 0, j = 0;

    for(i = 0; buff[i]!= '\0'; i++)
    {
        if((buff[i] >= 65 && buff[i] <= 90) || (buff[i] >= 97 && buff[i] <= 122))
           {
               c[j] = buff[i];
               j++;
           }
    }
    c[j] = '\0';
    //printf("%s\n", c);
}
void print(tree* root)
{

     if(root != NULL)
     {
         printf("\ntree:\n");
         printf("%s %d\n", root -> str, root -> count);
         print(root -> left);
         print(root -> right);
     }
}

int max(tree* root)
{
     static int m = -50;
     if(root != NULL)
     {
         if(m < root -> count)
         {//printf("%s %d\n", root -> str, root -> count);
             m = root -> count;
         max(root -> left);
         max(root -> right);
         }
     }
     return m;
}

int main()
{
    FILE * input;
    char buff[255], c[255];
    tree* root = NULL;
    int maxs = 0;

    input = fopen("hellos.txt", "r");

    if(input == NULL)
    printf("cannot open file\n");
    else
    printf("file opened\n");

      while( fscanf(input, "%s", buff) == 1)
       {
          // printf("%s\n", buff);
           removes(buff, c);
           if(strlen(c) >= 10)
           root = insert(root, c);
       }

    fclose(input);
    maxs = max(root);
    printf("%d\n", maxs);
    search(root, maxs);
    return 0;
}
