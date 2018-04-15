#include<stdio.h>
void main()
{
int a,b,add,sub,mul,mod;
float div;
printf("enter two nos.\n");
scanf("%d %d" ,&a,&b);
add=a+b;
sub=a-b;
mul=a*b;
div=a/b;
mod=a%b;
printf("add = %d , sub = %d , mul = %d , div = %f , mod = %d ",add,sub,mul,div,mod);
}


