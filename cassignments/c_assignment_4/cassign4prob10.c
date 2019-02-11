#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void deletechar(char*,char);
int main()
{
char *s;
char ch,b[10];
int l;
printf("enter the string");
scanf("%s",b);
l=strlen(b);
s=(char*)malloc((l+1)*sizeof(char));

strcpy(s,b);

printf("enter the character");
scanf("%c",&ch);
printf("%c",ch);
deletechar(s,ch);
}
void deletechar(char *s,char ch)
{
for(int i=0;i<strlen(s);i++)
{
if(s[i]==ch)
{
for(int j=i+1;j<strlen(s);i++)
{
s[j-1]=s[j];
}
}
}
printf("%s",s);
}