/*Develop sample programs using preprocessor operators #, ## and also
conditional compilation*/
#define m 5
#define book(name,author) #name"is wriiten by"#author
#define printme(s) printf_s("token"#s"=%d",token##s);
#include<stdio.h>
int main()
{
	int token9 = 81;
#ifdef m=5
	printf("%s",book(shivani, somebook));
#else
	printme(p);
#endif 
#ifdef n
	book(shivani, somebook);
#else
	printme(9);

#endif // 
	system("pause");


}
