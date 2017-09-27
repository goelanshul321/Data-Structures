#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct student
{
    int rno;
    char name[20];
    int age;
};

void exch(void* a, int x, int y)
{
     int temp;
     struct student *s1 = ((struct student *)a);
     temp = s1[x].age;
     s1[x].age = s1[y].age;
     s1[y].age = temp;
    
     temp = s1[x].rno;
     s1[x].rno = s1[y].rno;
     s1[y].rno = temp;
     
     char str[20];
     strcpy(str, s1[x].name);
     strcpy(s1[x].name, s1[y].name);
     strcpy(s1[y].name, str);
}

int cmp(void* x, int y, int z)
{
     int i;
     struct student *s1 = ((struct student *)x);
     struct student *s2 = ((struct student *)x);
     if(s1[y].age < s2[z].age) return -1;
     if(s1[y].age > s2[z].age) return 1;
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
            if((*cmp) (a, i, left) < 0)
                exch(a, i, ++last);
     }
     exch(a, left, last);
     quicksort(a, left, last - 1, cmp);
     quicksort(a, last + 1, right, cmp);
}

int main()
{
     struct student s1[100];
     int size, i;
     scanf("%d", &size);
     for(i = 0; i < size; i++)
     {
         scanf("%d %d", &s1[i].rno, &s1[i].age);
         scanf("%s", s1[i].name);
     }
     quicksort(s1, 0, size - 1, cmp);
     for(i = 0;i < size; i++)
     {
         printf("Rollno = %d Age = %d Name = %s\n\n", s1[i].rno, s1[i].age, s1[i].name);
     }
     return 0;
}
