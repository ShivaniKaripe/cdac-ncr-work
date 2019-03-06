#include<stdio.h>
#include<stdlib.h>

 
// Function to implement strlen() function
int string_length(char *pointer)
{
	//variable to maintain the length
	int len = 0;
	//loop until null terminating character encountered
	while (*(pointer + len) != '\0')
		len++;
	//returns the length of the string
	return len;
}
// Function to implement strrev() function
char* strrev(char *s)
{
	//variable length to maintain the length
	//variable c to maintain the count
	int length, c;
	//pointers to maintain begin and end of the string
	char *begin, *end;
	
	char temp;
	//store the string length in length variable
	length = string_length(s);
	begin = s;
	end = s;
	// loop to get the end of the string
	for (c = 0; c < length - 1; c++)
		end++;
	//reverses the string
	for (c = 0; c < length / 2; c++)
	{
		temp = *end;
		*end = *begin;
		*begin = temp;

		begin++;
		end--;
	}
	//return the result 
	return s;
}
// Function to implement strcpy() function
char* strcpy(char* destination, const char* source)
{
	// return if no memory is allocated to the destination
	if (destination == NULL)
		return NULL;

	// take a pointer pointing to the beginning of destination string
	char *ptr = destination;

	// copy the string pointed by source into the array 
	// pointed by destination
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}

	// include the terminating null character
	*destination = '\0';

	// destination is returned  
	return ptr;
}
// Function to implement strcat() function in C
char* strcat(char* destination, const char* source)
{
	// make ptr point to the end of destination string
	char* ptr = destination + strlen(destination);

	// Appends characters of source to the destination string
	while (*source != '\0')
		*ptr++ = *source++;

	// include the terminating null character
	*ptr = '\0';

	// destination is returned 
	return destination;
}
// Function to implement strcmp function
int strcmp(const char *X, const char *Y)
{
	while (*X)
	{
		// if characters differ or end of second string is reached
		if (*X != *Y)
			break;

		// move to next pair of characters
		X++;
		Y++;
	}

	// return the ASCII difference 
	return *(const unsigned char*)X - *(const unsigned char*)Y;
}
int main()
{
	char *result;
	char str1[20];
	char str2[20];
	int choice;
	//enter the string on which user wants to perform operations
	printf_s("\n enter string on which you want to perform the operations");
	
	gets_s(str1, 20);
	//loop will repeated until the user chooses the wrong option
	do
	{
		printf_s("\n choose the following");
		printf_s("\n 1.reverse the string");
		printf_s("\n 2.string copy");
		printf_s("\n 3.string concatenation");
		printf_s("\n 4.string comparision");
		scanf_s("%d", &choice);
		//based on the user choice the particular case is initialized
		switch (choice)
		{
		case 1:
			//strrev is called and result is stored in variable
			result = strrev(str1);
			printf_s("\n the result of the strrev is :%s", result);
			break;
		case 2:
			//strcpy is called and result is stored in variable
			result = strcpy(str2, str1);
			printf_s("\n the result of the strcpy is :%s", result);


			break;
		case 3:

			printf_s("enter string to attach to string 1");
			scanf_s("%s", str2, 20);
			//strcat is called and result is stored in variable
			result = strcat(str1, str2);
			printf_s("\n the result of the strcat is :%s", result);
			system("pause");
			break;
		case 4:
			printf_s("\n enter string to compare with string 1");
			scanf_s("%s", str2, 20);
			//strcmp is called and result is stored in variable
			int res = strcmp(str1, str2);
			printf_s("\n the result of the strcmp is :%d", res);
			system("pause");
			break;
		default:
			break;
		}
	} while (choice < 5);
}