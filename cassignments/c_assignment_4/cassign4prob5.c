#include<stdio.h>
#include<string.h>
void uppertolower(char ch[],int len);
int main()
{
	int choice,ch[20];
	printf("choose the option \n 1.uppercase to lower case \n lower case to upper case");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf_s("enter a string in upper case to convert it into lower case");
		gets(ch);
		//uppertolower(ch,strlen(ch));
		for (int i = 0; ch[i]!='\0'; i++)
		{
			if ((ch[i] > 64) && (ch[i] < 91))
			{
				ch[i] += 32;
			}
			printf_s("%c", ch[i]);
		}
		printf("%s", ch);
		scanf("%d", &choice);
		break;
		
	case 2:
		printf("enter a string in lower case to convert it into upper case");
		gets(ch);
		//lowertoupper(ch);
		break;

	default:
		
	printf("invalid choice");

		break;
	}
	scanf("%d", &choice);
}
/*void uppertolower(char *ch,int len)
{
	scanf_s("%d", &len);
}*/