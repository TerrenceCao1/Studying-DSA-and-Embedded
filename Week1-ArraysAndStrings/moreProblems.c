#include <stdio.h>
#include <stdbool.h>

//Find Max/Min of array
//reverse words of string
//check palindrome string

int maxArray(int* arr, int len);
int minArray(int* arr);
void reverseWords(char* str);
bool checkPalindrome(char* str);

int main(void)
{
	return 0;
}

int maxArray(int* arr, int len)
{
	int maxElement = arr[0];
	for (int i = 1; i < len; i++)
	{
		if (arr[i] > maxElement)
		{
			maxElement = arr[i];
		}
	}
	return maxElement;
}
