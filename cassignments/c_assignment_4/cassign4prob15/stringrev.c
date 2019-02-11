#include <stdio.h>

#include <string.h>

void main()
{
   char *str;
   int i,len;

  

   printf("Enter String : ");
   scanf("%s",str);
   len=strlen(str)-1;
   for(i=0;i<strlen(str)/2;i++)
   {
         str[i]+=str[len];
         str[len]=str[i]-str[len];
         str[i]=str[i]-str[len--];
   }
   printf("Reverse String is : %s",str);
   
}