/* Justin Soderstrom
   Assignment 5
   3/30/15
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node* next;
};

typedef struct node node;

void printTitle();
void printList(node* head);
node* makeNode(int val);
node* getEnd(node* head);

int main()
{
	node *head = NULL;
	node *newNode = NULL;
	node *walker = NULL;

	FILE *fp;

	int val;

	printTitle();

	fp = fopen("data.txt", "r");

	while(fscanf(fp,"%d",&val) != EOF)
	{
		newNode = makeNode(val);

		if(head == NULL)
		{
			head = newNode;
		}
		else
		{
			if((val % 2) == 0)
			{
				newNode->next = head;
				head = newNode;
			}
			else
			{
				walker = getEnd(head);
				walker->next = newNode;
			} 
		}

	}

	printList(head);

	return 0;
}

void printTitle()
{
	printf("\n");
	printf("Justin Soderstrom Assignment 5\n");
	printf("******************************\n");
}

void printList(node* head)
{
	node* walker = head;

	while(walker->next != NULL)
	{
		printf("%d ", walker->value);
		walker = walker->next;
	}

	printf("%d ", walker->value);
	printf("\n\n");
}

node* makeNode(int val)
{
	node *newNode = malloc(sizeof(node));
	newNode->value = val;
	newNode->next = NULL;
	return newNode;
}

node* getEnd(node* head)
{
	node* walker = head;

	while(walker->next != NULL)
	{
		walker = walker->next;
	}

	return walker;
}
