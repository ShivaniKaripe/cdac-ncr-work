
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//size of the strings
#define SIZE1 20
#define SIZE2 100
//function to expand the string1 and store it in  string2
void expand(char *s1, char *s2)
{
	int l;
	//variable j to insert the character in string 2
	static int j = -1;
	//loop terminates when null character encounters
	for (register int i = 0; s1[i] != '\0'; i++)
	{
		//if the character is equal to '-' then it must check the cases
		if (s1[i] == '-')
		{
			//the character before '-' must be less than the character after '-'
			 
				//checking whether it is valid case or not
				if ((s1[i - 1] <= s1[i + 1])&&(('a' <= s1[i - 1] && s1[i - 1] <= 'z') || ('A' <= s1[i - 1] && s1[i - 1] <= 'Z') || ('0' <= s1[i - 1] && s1[i - 1] <= '9')))
				{
					//if it is valid then string will be exanded
					l = 0;

					while (s2[j] != s1[i + 1])
					{
						s2[++j] = s1[i - 1] + (++l);
					}
					i++;
				}
			
			else
			{
				 //if it is not a valid case the program terminates
					printf_s("invalid input\n");
					system("pause");
					exit(1); 
				 
			}

		}
		//if not '-' then the characters must be appended to the string2
		else
			s2[++j] = s1[i];
	}
	//appending null terminating character
		s2[++j] = '\0';
		//printing the result
		printf_s("the string after the expansion is\n");
		printf_s("%s\n", s2);
}
int main()
{
		 
		char s1[SIZE1], s2[SIZE2];
		printf_s("enter the string\n");
		gets(s1);
		//expand function is called
		expand(s1, s2);
		system("pause");
		return 0;
}
	 