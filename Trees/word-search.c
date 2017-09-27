#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree
{
    int freq;
    char word[100];
    struct tree* left;
    struct tree* right;
}tree;

tree* root = NULL;

tree* newnode(char *word)
{
    tree* new = (tree*)malloc(sizeof(tree));
    //new->word = (char*)malloc(30 * (sizeof(char)));
    
//    new->freq = 0;
    strcpy(new->word, word);
    new->freq = 1;
    new->left = NULL;
    new->right = NULL;
    return new;
}

tree* insert(tree* n, char *word)
{
    if(n == NULL)
        return newnode(word);
    if(strcmp(word, n->word) == 0)
    {
        n->freq = n->freq + 1;
        return n;
    }
    else if(strcmp(word, n->word) > 0)
        n->right = insert(n->right, word);
    else
        n->left = insert(n->left, word);
    return n;
}


int max(tree* root)
{
     static int m = -50;
     if(root != NULL)
     {
         if(m < root -> freq)
         {//printf("%s %d\n", root -> str, root -> count);
             m = root -> freq;
         max(root -> left);
         max(root -> right);
         }
     }
     return m;
}

void print(tree* root, int freq)
{
    if(root != NULL)
    {
         print(root->left, freq);
         if(root->freq == freq)
         {
               printf("Max String Is %s\n", root->word);
               printf("Count is %d", root->freq);
         }
         print(root->right, freq);
    }
}
void make_tree(char *word)
{
    if(strlen(word) >= 10)
        root = insert(root, word); 
}

void removes(char buff[], char c[])
{
    int i = 0, j = 0;

    for(i = 0; buff[i]!= '\0'; i++)
    {
        if((buff[i] >= 65 && buff[i] <= 90) || (buff[i] >= 97 && buff[i] <= 122))
           {
               c[j] = tolower(buff[i]);
               j++;
           }
    }
    c[j] = '\0';
}

int main()
{
    FILE *ptr;
    char c[100], buff[100];

    ptr = fopen("hellos.txt", "r");
    int count;
    if(ptr == NULL)
    {
         printf("Cannot open the file");
         exit(0);
    }
    
    while(fscanf(ptr, "%s", buff) == 1)
    {    
         removes(buff, c);
         make_tree(c);    
    }
    count = max(root);
    print(root, count);
    fclose(ptr);
    return 0;
}
