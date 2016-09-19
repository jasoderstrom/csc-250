#include <stdio.h>
#include <stdlib.h>

struct node{

	int val;
	struct node* next;
};

typedef struct node node;

int main()
{
	node *head = NULL;
	node *newNode = NULL;

	newNode = malloc(sizeof(node));
	newNode->val = 5; //used for pointers. Cant use newNode.val
	newNode->next = NULL;

	head = newNode;
	printf("%d\n", head->val);
	printf("%d\n", newNode->val);


	newNode = malloc(sizeof(node));
	newNode->val = 6;
//	scanf("%d", &newNode->val);
	newNode->next = NULL;

	printf("%d\n", head->val);
	printf("%d\n", newNode->val);

	head->next = newNode;

	node *walker = head;

	newNode = malloc(sizeof(node));

	while(walker->next != NULL)
	{
		printf("%d\n", walker->val);
		walker = walker->next;
	}

	walker->next = newNode;
	return 0;
}
