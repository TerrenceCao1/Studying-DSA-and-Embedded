#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct arrayStack 
{
	int* array;
	int currentTopPosition;
	int capacity;
};

//Implement:
//init function
//isEmpty
//isFull
//peak
//add
//pop

struct arrayStack* initArrayStack(int maxSize);
int peek(struct arrayStack* stack);
bool isEmpty(struct arrayStack* stack);
bool isFull(struct arrayStack* stack);
void addToStack(struct arrayStack* stack, int value);
int popFromStack(struct arrayStack* stack);


int main(void)
{
	struct arrayStack* testStack = initArrayStack(5);
	addToStack(testStack, 5);
	addToStack(testStack, 23);
	addToStack(testStack, 21);

	printf("%i\n", popFromStack(testStack)); 
	addToStack(testStack, 52);
	printf("%i\n", popFromStack(testStack)); 
	printf("%i\n", popFromStack(testStack)); 
	printf("%i\n", popFromStack(testStack)); 
	printf("isEmpty? %i\n", isEmpty(testStack));
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
	return (stack->currentTopPosition == -1);
}

bool isFull(struct arrayStack* stack)
{
	return (stack->currentTopPosition == stack->capacity-1);
}

int peek(struct arrayStack* stack)
{
	if(isEmpty(stack))
	{
		printf("STACK IS EMPTY!\n");
		return 0;
	}
	return stack->array[stack->currentTopPosition];
}

void addToStack(struct arrayStack* stack, int value)
{
	if(isFull(stack))
	{
		printf("Yo we can't add to the stack cause it's full bub\n");
		return;
	}
	stack->currentTopPosition++;
	stack->array[stack->currentTopPosition] = value; 
}

int popFromStack(struct arrayStack* stack)
{
	if(isEmpty(stack))
	{
		printf("Ayo we can't pop from the stack if there's nothing in the stack. BUB\n");
		return 0;
	}
	int ret = peek(stack);
	stack->currentTopPosition--;
	
	return ret;
}
