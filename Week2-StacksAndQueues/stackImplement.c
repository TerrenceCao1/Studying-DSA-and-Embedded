#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Implement:
//init function
//isEmpty
//isFull
//peak
//add
//pop

struct arrayStack 
{
	int* array;
	int currentTopPosition;
	int capacity;
};

struct arrayStack* initArrayStack(int maxSize);
int peak(struct arrayStack* stack);
bool isEmpty(struct arrayStack* stack);

int main(void)
{
	return 0;
}

struct arrayStack* initArrayStack(int maxSize)
{
	struct arrayStack* stack = (struct arrayStack*)malloc(sizeof(struct arrayStack));
	if (!stack)
	{
		printf("stack creation failed :(");
		free(stack);
		return NULL;
	}

	stack->array = (int*)malloc(sizeof(int) * maxSize);
	if(!stack->array)
	{
		printf("stack array creation failed :(");
		free(stack);
		return NULL;
	}

	stack->capacity = maxSize;
	stack->currentTopPosition = -1;

	return stack;
}

bool isEmpty(struct arrayStack* stack)
{
	if(stack->currentTopPosition == -1){return true;}
	return false;
}

bool isFull(struct arrayStack* stack)
{
	if(stack->currentTopPosition == stack->capacity-1){return true;}
	return false;
}

int peak(struct arrayStack* stack)
{
	return stack->array[stack->currentTopPosition];
}
