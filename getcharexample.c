#include<stdio.h>
#include<stdlib.h>
void main()
{
FILE *fp;
char c;
char data[300];

fp=fopen("fh2.txt","r");
/*while((c=getchar())!=EOF)
{
fprintf(fp,"%c",c);
}
fclose(fp);
fp=fopen("fh2.txt","r");
//fscanf(fp,"%s",data);
fgets(data,27,fp);
//fseek(fp,-3,2);*/
//fscanf(fp,"%s",data);
fgets(data,34,fp);
fclose(fp);
printf("%s",data); 
}

