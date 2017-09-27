#include<stdio.h>
#include<stdlib.h>
// struct student
// {
//    int rno;
//    char* name;
// };

void exch(void* a, int x, int y)
{
     int *arr = ((int *)a);
     int temp = arr[x];
     arr[x] = arr[y];
     arr[y] = temp;
}
int cmp(void* x, int y, int z)
{
 //    struct student s1 = *((struct student *)x);
 //    struct student s2 = *((struct student *)y);
 //    if(s1.rno < s2.rno) return -1;
 //    if(s1.rno > s2.rno) return 1;
       int *a = ((int *)x); 
 //      if((*(int *)x) < (*(int *)y))  return 1;
 //      if((*(int *)x) > (*(int *)y))  return -1;
       if(a[y] > a[z]) return -1;
       if(a[y] < a[z]) return 1;
       return 0;
}
void quicksort(void *a, int left, int right, int (*cmp) (void*, int, int))
{
     if(left >= right)
     return;
     int i;
     int last = left;
     for(i = left + 1; i <= right; i++)
     {
        //  if(*cmp(i, left) < 0)
  
            if((*cmp) (a, i, left) < 0)
                exch(a, i, ++last);
     }
     exch(a, left, last);
     quicksort(a, left, last - 1, cmp);
     quicksort(a, last + 1, right, cmp);
}
int main()
{
     int a[20], i, size;
     scanf("%d", &size);
     for(i = 0; i < size; i++)
         scanf("%d", &a[i]);

     quicksort(a, 0, size - 1, cmp);
 
     for(i = 0; i < size; i++)
         printf("%d", a[i]);
     return 0;
}
