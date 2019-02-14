#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
char *str[5];
char buf[50];
int n;
for(int i=0;i<5;i++)
{
printf("enter the names");
scanf("%s",buf);
n=strlen(buf);
str[i]=(char*)malloc((n+1)*sizeof(char));
strcpy(str[i],buf);
printf("%s",str[i]);
free(str[i]);
}
}