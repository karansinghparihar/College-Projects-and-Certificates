#include<stdio.h>
#include<stdlib.h>
void main()
{
FILE *fp;
char c;
char name[15]="karansingh",newname[30];
int number=93,newnumber;
fp=fopen("fh2.txt","w");
fprintf(fp,"name%srollno%d\n",name,number);
c=getchar();
fclose(fp);
fp=fopen("fh2.txt","r");
fscanf(fp,"%s %d",newname,&newnumber);
//fgets(newname,21,fp);
//fseek(fp,-3,2);
//fscanf(fp,"%d",&newnumber);
fclose(fp);
printf("%s seperate%d charseperate %c\n",newname,newnumber,c); 
}

