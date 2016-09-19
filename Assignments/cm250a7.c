/* Author: Justin Soderstrom
   Assignment: A7
   Date: 04/13/2015
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    int val;
    node *next;
};

node* createList(int amount);
node* makeNode(int val);
node* pushFront(node* head, node* new);
node* delete(node* head, int val);
node* modify(node* head, int old, int new);
int inList(node* head, int val);
void lookForDupes(node*head);
void printList(node* head);

int main(void)
{
	int amount;
	int search;
	int list;
	int new;
	int remove;

	printf("\n");
	printf("Justin's Assignment 7!\n");
	printf("----------------------\n");

	printf("How many nodes? ");
	scanf("%d", &amount);
 
	node* head = createList(amount);

	printf("\n");

	printf("Enter a number to search for: ");
	scanf("%d", &search);

	list = inList(head, search);

	printf("\n");

	if(list == 1)
	{
		printf("Change to what value? ");
		scanf("%d", &new);
		modify(head, search, new);
	}

	printf("\n");

	printf("Enter a number to remove: ");
	scanf("%d", &remove);
	head = delete(head, remove);

	printf("\n");

	lookForDupes(head);

	printf("\n");

	return 0;
}

node* createList(int amount)
{
	node* head = NULL;
	node* newNode = NULL;

	int val;
	int i;

	srand(time(NULL));

	for(i=0; i<amount; i++)
	{
		val = rand() % 10000 + 1;

		newNode = makeNode(val);

		if(head == NULL)
		{
			head = newNode;
		}
		else
		{
			head = pushFront(head, newNode);
		}
	}

	printList(head);

	return head;
}

node* makeNode(int val)
{
	node *newNode = malloc(sizeof(node));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

node* pushFront(node* head, node* new)
{
	new->next = head;
	head = new;
	return head;
}

node* delete(node* head, int val)
{
	node* walker = head;
	node* badNode = NULL;

	while(walker->val != val)
	{
		if(walker->next != NULL)
		{
			walker = walker->next;
		}
		else
		{
			break;
		}
	}

	if(walker == head)
	{
		head = head->next;
		badNode = walker;
		walker = head;
		free(badNode);

		printf("%d was deleted from the list\n", val);
	}
	else if(walker->val == val)
	{
		badNode = walker;

		walker = head;

		while(walker->next != badNode)
		{
			walker = walker->next;
		}

		walker->next = badNode->next;
		free(badNode);

		printf("%d was deleted from the list\n", val);
	}
	else
	{
		printf("No node to delete\n");
	}

	printList(head);

	return head;
}

node* modify(node* head, int old, int new)
{
	node* walker = head;

	while(walker->val != old)
	{
		if(walker->next != NULL)
		{
			walker = walker->next;
		}
		else
		{
			break;
		}
	}

	walker->val = new;

	printList(head);
}

int inList(node* head, int val)
{
	node* walker = head;

	while(walker->val != val)
	{
		if(walker->next != NULL)
		{
			walker = walker->next;
		}
		else
		{
			break;
		}
	}
	if(walker->val == val)
	{
		printf("Found in list\n");
		return 1;
	}
	else
	{
		printf("Not in list\n");
		return 0;
	}
}

void lookForDupes(node* head)
{
	node* walker1 = head;
	node* walker2 = head;

	while(walker1 != NULL)
	{
		while(walker2 != NULL)
		{
			if(walker2->val == walker1->val && walker2 != walker1)
			{
				printf("Dup found: %d\n", walker1->val);
				printf("Dup found: %d\n", walker2->val);
				return;
			}
			else
			{
				walker2 = walker2->next;
			}
		}

			walker2 = head;
			walker1 = walker1->next;
	}

	printf("No Dupes Found :D\n");
}

void printList(node* head)
{
	node* walker = head;

	while(walker != NULL)
	{
		printf("%d ", walker->val);
		walker = walker->next;
	}

	printf("\n");
}

