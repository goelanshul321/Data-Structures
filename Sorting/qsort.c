#include<stdio.h>
#include<stdlib.h>

int compare(int a, int b)
{
    if(a > b)
        return -1;
    if(a == b)
        return 0;

        return 1;
}

void quicksort(int* array, int n, int l, int r, int (*cmp)(void* , void* ))
{
    int last = l, i;
    for(i = l + 1; i <= r; i++)
    {
        if((*cmp)(array[l], array[l + i]) < 0)
            swap(array, ++last, i);
    }
    swap(array, last, l);
    quicksort(array, n, last - 1, r, &cmp);
    quicksort(array, n, last + 1, r, &cmp);
} 

void swap(int *array, int x, int y)
{
    int temp;
    temp = *(array + x);
    *(array + x) = *(array + y);
    *(array + y) = temp;
}

int main()
{
    int array[20], size, i, left, right;
    scanf("%d", &size);
    for(i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    void (*cmp)(void, void) = &compare;
    qsort ( array, size, left, right, (*cmp)(void* , void*));
    printf("sorted array is");
    for(i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
