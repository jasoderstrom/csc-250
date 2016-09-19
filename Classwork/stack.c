#include <stdio.h>

int top(int stack[], int top)
{
	int val;
	val = stack[top];
	return val;
}

int pop(int top)
{
	top--;
	return top;
}

int push(int stack[], int top, int val)
{
	top++;
	stack[top] = val;
	return top;
}

int main()
{
	int stack[50];
	int topPos = -1;
	int val;
	int i;
	for(i=0;i<10;i++)
	{
		topPos = push(stack,topPos,i);
	}

	for(i=0;i<10;i++)
	{
		val = top(stack, topPos);
		topPos = pop(topPos);
		printf("%d\n", val);
	}
}
