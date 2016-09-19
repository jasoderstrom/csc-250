#include <stdio.h>
#include <stdlib.h>

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
}

void push(int val)
{
}

void pop()
{
}

int main()
{
    push(5);
    push(6);
    push(7);
    int val;
    val = top();
    printf("%d\n", val);
    pop();
    val = top();
    printf("%d\n", val);
    pop();
}
