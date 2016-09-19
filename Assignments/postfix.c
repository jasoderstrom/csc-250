#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int val;
    struct node* next;
};
typedef struct node node;

struct stack
{
    node* bottom;
    node* top;
};
typedef struct stack _stack;

_stack stack;

int top()
{
	int val;
	val = stack.top->val;
	return val;
}

void push(node* newNode)
{
	if(stack.top == NULL && stack.bottom == NULL)
	{
		stack.top = newNode;
		stack.bottom = newNode;
	}
	else
	{
		newNode->next = stack.top;
		stack.top = newNode;
	}
}

void pop()
{
	node* badNode = stack.top;
	stack.top = stack.top->next;
	free(badNode);
}

void getExpression(char expression[])
{
	printf("Please enter your postfix expression below:\n");

	fgets(expression, 100, stdin);
}
int calculate(char op, int val1, int val2)
{
	int result;

	if(op == '+')
	{
		result = val1 + val2;
	}
	else if(op == '-')
	{
		result = val2 - val1;
	}
	else if(op == '*')
	{
		result = val1 * val2;
	}
	else if(op == '/')
	{
		result = val2 / val1;
	}

	return result;
}

void readExpression(char expression[])
{
	int i;
	int val1;
	int val2;
	char op;

	node* newNode;

	for(i=0; i<strlen(expression)-1; i++)
	{
		if(expression[i] <= '9' && expression[i] >= '0')
		{
			newNode = malloc(sizeof(node));

			newNode->val = expression[i] - '0';

			newNode->next = NULL;

			push(newNode);
		}
		else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
		{
			op = expression[i];

			val1 = top();

			pop();

			val2 = top();

			pop();

			newNode = malloc(sizeof(node));
			newNode->val = calculate(op, val1, val2);
			push(newNode);
		}
	}
}

int main()
{
	char expression[100];

	stack.top = NULL;
	stack.bottom = NULL;

	getExpression(expression);
	readExpression(expression);

	printf("Result = %d\n", stack.top->val);

	return 0;
}
