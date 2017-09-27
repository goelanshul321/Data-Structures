#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m, n, i, j;
    scanf("%d\n %d", &m, &n);
    int** arr = (int**)malloc(m * sizeof(int*));
    for(i = 0; i < m; i++)
    {
        *(arr + i) = (int*)malloc(n * sizeof(int));
        for(j = 0; j < n; j++)
            scanf("%d", (*(arr + i) + j));
    }
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            printf("%d\n", *(*(arr + i) + j)); 
     
}
