#include <stdio.h>
#include <stdlib.h>

//implement:
	//strlen - return length of a string
	//strcpy - copy one string to another
	//strcmp - compare strings
	//strcat - concatenate strings

int length(char* str);
char* copy(char* orig);
int compare(char* str1, char* str2);
char* concat(char* str1, char* str2);

int main(void)
{
	char yuhyuh[50] = "yurtyurt";
	char* Yuhyuh = "Yurtyurt";
	//printf("length = %i\n", length(yuhyuh));

	//char* copiedYuhYuh = copy(yuhyuh);
	//printf("Copy of %s: %s\n", yuhyuh, copiedYuhYuh);
	
	//printf("comparing 'yurtyurt' with 'Yurtyurt': %i\n", compare(yuhyuh, Yuhyuh));

	printf("yuhyuh + Yuhyuh = %s\n", concat(yuhyuh, Yuhyuh));
	return 0;
}

int length(char* str)
{
	int count = 0;
	int i = 0;
	while(str[i] != '\0')
	{
		count++;
		i++;
	}
	return count;
}

char* copy(char* orig)
{
	char* res = malloc(sizeof(char) * length(orig));
	for(int i = 0; i <= length(orig); i++)
	{
		res[i] = orig[i];
	}
	return res;
}

int compare(char* str1, char* str2)
{
	int sumStr1 = 0; int sumStr2 = 0;
	while(*str1)
	{
		sumStr1 += *str1++;
	}
	while(*str2)
	{
		sumStr2 += *str2++;
	}

	return sumStr1 - sumStr2;
}

char* concat(char* str1, char* str2)
{
	char* base = str1;

	while(*str1)
	{
		str1++;
	}

	while(*str2)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	
	*str1 = '\0';

	return base;
}
