#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* next;
};
typedef struct node node;


void printListRec(node* node)
{
	if(node!=NULL)
	{
		printf("%d ", node->val);
		node = node->next;
		printListRec(node);
	}
	else
	{
		printf("\n");
	}
}


node* makeNode(int val)
{
  node *tmp = malloc(sizeof(node));
  tmp->value = val;
  tmp->next = NULL;
  return tmp;
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
    printf("Enter a number: ");
    scanf("%d", &max); 
    
    //build the linked list
    for(i=0;i<max;i++)
     {
        //make a node that holds our number
        newNode = makeNode(i);

        //head = pushEnd(head, newNode);
        head = pushFront(head, newNode);
    
        //print the current list
        walker = head;
        while(walker!=NULL)
        {
            printf("%d ", walker->value);
            walker = walker->next;
        }
        printf("\n");
     }


    //delete a specific node out of the list
    //seg faults if the node to delete is at the start of the list
    node* badNode;
    printf("# to delete: ");
    int toRemove;
    scanf("%d", &toRemove);

    //find that node in the list
    walker = head;
    while(walker->value != toRemove)
        walker = walker->next;

    badNode = walker;
    walker = head;
    while(walker->next != badNode)
        walker = walker->next;
        
    walker->next = badNode->next;
    free(badNode); 

    walker = head;
    while(walker != NULL)
    {
        printf("%d ", walker->value);
        walker = walker->next;
    }

    //delete nodes from back of list
    /*for(i=0;i<max-1;i++)
    {
        walker = head;
        while(walker->next!=NULL)
            walker = walker->next;
        badNode = walker;
   
        walker = head; 
        while(walker->next!=badNode)
            walker = walker->next;

        walker->next = NULL;
        free(badNode)
        
        //print off the list at each step
        walker = head;
        while(walker!=NULL)
        {
            printf("%d ", walker->value);
            walker = walker->next;
        }
        printf("\n");
    }*/


    //delete nodes from front of list
    /*
    for(i=0;i<max-1;i++)
    {
        badNode = head;
        head = head->next;
        free(badNode);
        
        //print off the list at each step
        walker = head;
        while(walker!=NULL)
        {
            printf("%d ", walker->value);
            walker = walker->next;
        }
        printf("\n");

    }

    */



        
    return 0;
}
