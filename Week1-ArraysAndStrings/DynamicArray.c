#include <stdio.h>
#include <stdlib.h>


//Implement a Dynamic array (malloc + resize on overflow).
typedef struct
	{
		int* ptr; //pointer to array
		int size; //current size of array
		int capacity; //max size without reallocation
	}DynamArray;

//initiate function
DynamArray* dyArrayInit(int initialCapacity)
{
	DynamArray* arr = (DynamArray*)malloc(sizeof(DynamArray));
	arr->ptr = (int*)malloc(initialCapacity * sizeof(int));
	arr->size = 0;
	arr->capacity = initialCapacity;
	return arr;
}

//append function
void dyArrayAppend(DynamArray* arr, int val)
{
	if (arr->size < arr->capacity)
	{
		arr->ptr[arr->size] = val;
		arr->size++;
	}
	else
	{
		arr->ptr = realloc(arr->ptr, arr->size);
		arr->capacity++;
		arr->ptr[arr->size++] = val;
	}
}

//free memory funciton
void freeDyArray(DynamArray* arr)
{
	free(arr->ptr);
	free(arr);
}

int* insert(int* origArr, int origSize, int index, int value);

int main(void)
{
	DynamArray* myArr = dyArrayInit(10);
	printf("BEFORE REALLOCATION: \n");
	for(int i = 0; i < 10; i++)
	{
		dyArrayAppend(myArr, i);
	}

	for (int i = 0; i < 10; i++)
	{
		printf("myArr[%d]: %d\n", i, myArr->ptr[i]);
	}

	printf("AFTER REALLOCATION: \n");
	for (int i = 10; i < 20; i++)
	{
		dyArrayAppend(myArr, i);
	}

	for (int i = 10; i < 20; i++)
	{
		printf("myArr[%d]: %d\n", i, myArr->ptr[i]);
	}

	freeDyArray(myArr);

	return 0;
}
