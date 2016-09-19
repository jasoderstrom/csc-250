/*Name: Justin Soderstrom
  Assignment: A6
  Date: 4/06/15
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node 
{
	char item_Name[20];
	int quantity;
	float price;
	int id;
	char date[10];
	struct node* next;
};

typedef struct node node; 

void printTitle(void);
node* createList(void);
node* makeNode(void);
node* getEnd(node* head);
float getTotalValue(node* head);
int getTotalQuantity(node* head);
void needToOrder(node* head);

int main(void)
{
	float total = 0;
	int quantity = 0;

	node *head = NULL;

	printTitle();

	head = createList();

	total = getTotalValue(head);

	quantity = getTotalQuantity(head);

	printf("Total Inventory Value: $%.2f\n" , total);
	printf("Total Quantity: %d\n", quantity);
	needToOrder(head);

	return 0; 

}

void printTitle(void)
{
	printf("\n");
	printf("Welcome to Justin's Inventory Program!\n");
	printf("**************************************\n");
}

node* createList(void)
{
	FILE *fp;

	node *head = NULL;
	node *newNode = NULL;
	node *walker = NULL;

	fp = fopen("inventory.txt","r");

	newNode = makeNode();

	while(fscanf(fp,"%s", newNode->item_Name) != EOF)
	{

		fscanf(fp,"%d", &newNode->quantity);
		fscanf(fp,"%f", &newNode->price);
		fscanf(fp,"%d", &newNode->id);
		fscanf(fp,"%s", newNode->date);

		if(head == NULL)
		{
			head = newNode;
		}
		else
		{
			walker = getEnd(head);
			walker->next = newNode;
		}
		newNode = makeNode();
	}

	fclose(fp);

	return head;
}

node* makeNode(void)
{
	node *newNode = malloc(sizeof(node));
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

float getTotalValue(node* head)
{
	node* walker = head;
	float total = 0;

	while(walker != NULL)
	{
		total += walker->quantity * walker->price;
		walker = walker->next;
	}

	return total;
}

int getTotalQuantity(node* head)
{
	node* walker = head;

	int itemTotal = 0;

	while(walker != NULL)
	{
		itemTotal += walker->quantity;
		walker = walker->next;
	}

	return itemTotal;
}

void needToOrder(node* head)
{
	node* walker = head;

	printf("Items that need to be ordered:\n\t");

	while(walker != NULL)
	{
		if(walker->quantity < 10)
		{
			printf("%s\n\t", walker->item_Name);
		}
		walker = walker->next;
	}

	printf("\n");
}
