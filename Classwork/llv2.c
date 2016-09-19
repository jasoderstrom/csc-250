#include <stdio.h>
#include <stdlib.h>

struct node{

	int value;
	struct node* next;
};

typedef struct node node;

node* makeNode(int val)
{
	node *newNode = malloc(sizeof(node));
	newNode->value = val;
	newNode->next = NULL;
	return newNode;
}

node* getEnd(node* head)
{
	node *walker = head;
	while(walker->next != NULL)
	{
		walker = walker->next;
	}
	return walker;
}

node* pushEnd(node* head, node* newNode)
{
	node* end;
	if(head == NULL)
		head = newNode;
	else
	{
		end = getEnd(head); 
		end->next = newNode;
	}
	return head;
}

node* pushFront(node* head, node* newNode)
{
	if(head == NULL)
		head = newNode;
	else
	{
		newNode->next = head;
		head = newNode;
	}
	return head;
}

int main()
{
	node *head = NULL;
	node *newNode = NULL;
	node *walker = NULL;
	int max = 10;
	int i;
	node* head2;
	printf("Enter a number: ");
	scanf("%d", &max);
	for(i=0;i<max;i++)
	{
		//make a node that holds our number
		newNode = makeNode(i);
//		newNode = malloc(sizeof(node));
//		newNode->value = i;
//		newNode->next = NULL;
		head = pushFront(head, newNode);
		//get the start of the list
		walker = head;
		//find the end of the list
		while(walker!=NULL)
		{
			printf("%d ", walker->value);
			walker = walker->next;
		}
		printf("\n");
		/*else
		{
			walker = get_end(head);
			//add the node to the list
			walker->next = newNode;
		}*/

			node* badNode;
		for(i=0; i<max-1; i++)
		{
			//how to delete a node from a list
			walker = head;
			while(walker->next != NULL)
				walker = walker->next;
			badNode = walker;

			walker = head;
			while(walker->next!=badNode)
				walker = walker->next;

			walker->next = NULL;
			free(badNode);
			//end of deletion April 8
		}

		walker = head;
		while(walker != NULL)
		{
			printf("%d ", walker->value);
			walker = walker->next;
		}
		printf("\n");

	}

	return 0;
}
