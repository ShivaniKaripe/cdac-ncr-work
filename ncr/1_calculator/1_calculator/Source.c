/*calculator program*/
#include<stdio.h>
#include<math.h>
#include<string.h>
static float g_res = 0;
static float var1 = 0;
static float var2 = 0;

float addition(float, float);
float substract(float, float);
float multiply(float, float);
float divide(float, float);
int isBalancedParathesis(char *, int);
int main()
{
	int flag = 0;
	char string[100];
	printf_s("enter the expression you want to evaluate \n ");
	gets_s(string,100);
	printf("\n the length of the string you have entered is %d", strlen(string));
	flag = isBalancedParathesis(string, strlen(string));
	if (1 == flag)
	{
		//
	}
	else if(0==flag)
	{
		printf("\n the expression you have entered is invalid ");
		getchar();
		return -1;
	}
}