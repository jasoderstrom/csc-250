/*Name: Justin Soderstrom
  Assignment: A4
  Date: 3/23/15
*/

#include <stdio.h>
#include <string.h>

struct inventory_item 
{
	char item_Name[20];
	int quantity;
	float price;
	int id;
	char date[8];
};

typedef struct inventory_item list; 

void print_Title(void);
int get_User_Choice(void);
void read_Inventory(list inventory[], int *k);
int item_Total(list inventory[], int k);
float total_Value(list inventory[], int k);
void print_Orders(list inventory[], int k);

int main(void)
{
	int choice = 0;
	int k;
	int items;
	float total;

	list inventory[500];

	while(choice != 3)
	{
		print_Title();
		choice = get_User_Choice();

		if(choice == 1)
		{
			read_Inventory(inventory, &k);
			printf("\nFinished reading file...\n");
		}
		else if(choice == 2)
		{
			total = total_Value(inventory, k);
			items = item_Total(inventory, k);
 
			printf("Total inventory value: $%.2f\n", total);
			printf("Total number of items: %d\n", items);

			print_Orders(inventory, k);
		}
		else if(choice == 3)
		{
			printf("\n");
			printf("Terminating program...\n");
			printf("\n");

			break;
		}
		else
		{
			printf("That was not a valid choice. Please select a value from 1-3.\n"); 
		}
	}

		return 0;
}

void print_Title(void)
{
	printf("\n");
	printf("Welcome to Justin's Inventory Program!\n");
	printf("**************************************\n");
	printf("(1) Read Inventory File\n");
	printf("(2) Display Inventory Stats\n");
	printf("(3) End Program\n");
	printf("\n");
}

int get_User_Choice(void)
{
	int choice;
	printf("Your choice: ");
	scanf("%d", &choice);
	return choice;
} 

void read_Inventory(list inventory[], int *k)
{
	int i;

	FILE *fp;

	fp = fopen("inventory.txt","r");

	fscanf(fp,"%d", k);

	for(i=0;i<*k;i++)
	{
		fscanf(fp,"%s", inventory[i].item_Name);
		fscanf(fp,"%d", &inventory[i].quantity);
		fscanf(fp,"%f", &inventory[i].price);
		fscanf(fp,"%d", &inventory[i].id);
		fscanf(fp,"%s", inventory[i].date);
	}

	fclose(fp);
}

float total_Value(list inventory[], int k)
{
	int i;
	float total = 0;

	for(i=0; i<k; i++)
	{
		total += inventory[i].quantity * inventory[i].price;
	}

	return total;
}

int item_Total(list inventory[], int k)
{
	int i;
	int itemTotal = 0;

	for(i=0; i<k; i++)
	{
		itemTotal += inventory[i].quantity;
	}

	return itemTotal;
}

void print_Orders(list inventory[], int k)
{
	int i;

	printf("Items that need to be ordered:\n\t");

	for(i=0; i<k; i++)
	{
		if(inventory[i].quantity < 10)
		{
			printf("%s\n", inventory[i].item_Name);
		}

	}

}
