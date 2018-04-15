#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
FILE *fp;
char newname[100];
char name[]="hello, janu 123 @ ! kaha khaoage khanna we hum hai jamana.";
fp=fopen("binaryf.txt","w");
fwrite(name,sizeof(char),strlen(name),fp);
fclose(fp);
fp=fopen("binaryf.txt","r");
fread(newname,sizeof(char),100,fp);
fclose(fp);
printf("\n%s\n",newname);
printf("%d\n",sizeof(char));
printf("%d\n",sizeof(int));
printf("%d\n",sizeof(float));
}

