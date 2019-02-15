<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
void printRotatedString(char str[]) 
{ 
    int len = strlen(str); 
  
    // Generate all rotations one by one and print 
    char temp[len]; 
    for (int i = 0; i < len; i++) 
    { 
        int j = i;  // Current index in str 
        int k = 0;  // Current index in temp 
  
        // Copying the second part from the point 
        // of rotation. 
        while (str[j] != '\0') 
        { 
            temp[k] = str[j]; 
            k++; 
            j++; 
        } 
  
        // Copying the first part from the point 
        // of rotation. 
        j = 0; 
        while (j < i) 
        { 
            temp[k] = str[j]; 
            j++; 
            k++; 
        } 
  
        printf("%s\n", temp); 
    } 
} 
  
 
int main() 
{ 
    char str[100];
	printf("enter a string");
gets(str); 
    printRotatedString(str); 
    return 0; 
} 
=======
#include<stdio.h>
#include<string.h>
void printRotatedString(char str[]) 
{ 
    int len = strlen(str); 
  
    // Generate all rotations one by one and print 
    char temp[len]; 
    for (int i = 0; i < len; i++) 
    { 
        int j = i;  // Current index in str 
        int k = 0;  // Current index in temp 
  
        // Copying the second part from the point 
        // of rotation. 
        while (str[j] != '\0') 
        { 
            temp[k] = str[j]; 
            k++; 
            j++; 
        } 
  
        // Copying the first part from the point 
        // of rotation. 
        j = 0; 
        while (j < i) 
        { 
            temp[k] = str[j]; 
            j++; 
            k++; 
        } 
  
        printf("%s\n", temp); 
    } 
} 
  
 
int main() 
{ 
    char str[100];
	printf("enter a string");
gets(str); 
    printRotatedString(str); 
    return 0; 
} 
>>>>>>> a9245c9d3915eb3d655e88b5d2e533936d867c30
