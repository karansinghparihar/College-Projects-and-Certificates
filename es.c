#include<stdio.h>
#include<string.h>

void print(int a, int b)
{
int c=a;
int d=b;

c=c+a;
d=d+b;
printf("inside subroutine val a =%d\n",a);
printf("inside subroutine val b =%d\n",b);
printf("inside subroutine val c =%d\n",c);
printf("inside subroutine val d =%d\n",d);
a=c+a;
b=d+b;
}
int main()
{
char message[30];
int a,b,c,d;
a=1;
b=2;
c=3;
d=4;

strcpy(message,"hello this is me! ");
printf("string message is =%s\n",message);
printf("inside main val a =%d\n",a);
printf("inside main val b =%d\n",b);
printf("inside main val c =%d\n",c);
printf("inside main val d =%d\n",d);
print(5,6);
return 0;
}
