#include <stdio.h>
#include <stdlib.h>


//Implement a Dynamic array (malloc + resize on overflow).

int* insert(int* origArr, int origSize, int index, int value);

int main(void)
{
	//Dynamic array
	int* ptr;
	int size = 5;
	
	ptr = (int*)malloc(size * sizeof(int));

	if (ptr == NULL)
	{
		printf("yo the memory didn't get allocated bud\n");
		return 1;
	}
	
	//if ptr got malloced:
	printf("memory allocated\n");

	//resize on overflow:
		//write insert function -> if the index >= size: realloc enough memory to get to the index
	insert(ptr, 5, 10, 34);

	for (int i = 0; i < 11; i++)
	{
		printf("ptr[%d] = %d\n", i, ptr[i]);
	}
	
	return 0;
}

int* insert(int* origArr, int origSize, int index, int value)
{
	if(index >= value)
	{
		origArr = realloc(origArr, (index+1) * sizeof(int));
		origArr[index] = value;
	}
	else
	{
		origArr[index] = value;
	}
	return origArr;
}

