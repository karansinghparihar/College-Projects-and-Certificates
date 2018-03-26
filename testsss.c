//random code
#include<stdio.h>
#include<stdlib.h>
int test(int a)
{
if(a<10)
{
printf(" less than 10 = %d\n",a);
a++;
return a;
}
return a;
}
void main()
{
int q=test(12);
printf(" value of a = %d\n",q);}
