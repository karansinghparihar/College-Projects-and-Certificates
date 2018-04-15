#include<stdio.h>
void main()
{
FILE *fp;
fp=fopen("cprogram1.txt","w");
fprintf(fp,"erase kar diya");
fclose(fp);

}
