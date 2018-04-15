#include<stdio.h>
#include<stdlib.h>
void main()
{
FILE *fp;
long int prevn,currn,nextn,rewindn,againrewindn;
char name[45]="karan singh";
int number=93;
fp=fopen("fh1.txt","w");
fprintf(fp,"%s hello     ,%d",name,number);

fclose(fp);
#include<stdio.h>
#include<stdlib.h>
void main()
{
FILE *fp;
long int prevn,currn,nextn,rewindn,againrewindn;
char name[45]="karan singh";
int number=93;
fp=fopen("fh1.txt","w");
fprintf(fp,"%s hello     ,%d",name,number);

fclose(fp);
}

