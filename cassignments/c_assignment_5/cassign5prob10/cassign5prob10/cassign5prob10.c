/*10. Write a program that will generate a data file containing a list of
countries and their corresponding capitals. Write interactive code which
will access the above created data file to perform the following
operations
a) Determine the capital of a specified country
b) Determine the country whose capital is specified
c) Terminate the programme*/
#include<stdio.h>
#include<string.h>
int main()
{
	char chptr[100];
	char capital[100];
	char country[100];

	int choice;
	
	FILE *fp;
	fopen_s(&fp, "country-capital.txt", "r");
	if (fp == NULL)
	{
		printf_s("error hile opening a file");
		return -1;
	}
	printf_s("enter your choice from the below menu");
	printf_s("\n 1.Determine the capital of a specified country \n 2.Determine the country whose capital is specified \n 3.Terminate the programme");
	scanf_s("%d", &choice);
	while (choice<4)
	{
		switch (choice)
		{
		case 1:
			printf_s("\n enter the counry name for which you want to know the capiltal");
			scanf_s("%s", chptr,100);
			while (!feof(fp))
			{
				fscanf_s(fp,"%s",capital);
				if ((strcmp(chptr, capital)) == 0)
				{
					fscanf_s(fp, "%s", country);
					printf_s("%s", country);
					
				}
			}
			rewind(fp);
			break;
		case 2:
			printf_s("\n enter the capital name for which you want to know the country");
			scanf_s("%s", chptr, 100);
			
			while (!feof(fp))
			{
				fscanf_s(fp, "%s", country);
				fscanf_s(fp, "%s", capital);
				if ((strcmp(capital, chptr)) == 0)
				{
					printf_s("%s", country);
					break;
					 
				}
			}
			 
			break;
		case 3:
			exit();

		}
	}

}