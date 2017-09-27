#include<stdio.h>
int main()
{
int num, x;
scanf("%d", &num);
x = (num>>31) | !(!num);
printf("%d", x);
return 0;
}
