#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int val;
	struct Node* next;
}Node;

//implement:
//	isEmpty
//	peek
//	add
//	pop

bool isEmpty(Node* stack);
int peek(Node* stack);
void add(Node** stack, int val);
int pop(Node** stack);

int main(void)
{
	Node* head = NULL;

	printf("isEmpty?: %d\n", isEmpty(head));

	add(&head, 15);
	add(&head, 123);

	printf("peek: %d\n", peek(head));

	printf("isEmpty?: %d\n", isEmpty(head));
	printf("%d", pop(&head));
}

bool isEmpty(Node* stack)
{
	return (stack == NULL);
}

int peek(Node* stack)
{
	if(isEmpty(stack))
	{
		printf("can't peek an empty stack buddy\n");
		return 0;
	}
	return stack->val;
}

void add(Node** stack, int val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->val = val;
	newNode->next = *stack;
	*stack = newNode;
}

int pop(Node** stack)
{
	if(isEmpty(*stack))
	{
		printf("yo your stack is empty bub\n");
		return -1;
	}
	
	Node* ptr = *stack;

	int ret = ptr->val;
	*stack = ptr->next;

	free(ptr);

	return ret;
}
