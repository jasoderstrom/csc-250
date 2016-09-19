#include <stdio.h>
#include <string.h>

struct inventory{
	float price;
	char name[20];
	int quantity;
	int id;
};
typedef struct inventory si;
int main()
{

	si bannanas;
	si chips;

	//struct inventory bannanas;
	//struct inventory chips;
	si items[100];

	//struct inventory items[100];

//	items[0].price = 2.33;

	strcopy(items[0].name, "coke");
	items[0].price = 1.59;
	items[0].quantity = 203;
	items[0].id = 123456;


	for(i=0;i<100;i++)
	{
		scanf("%f", &items[i].price);
		printf("%s\n", items[i].name);
	}

	bannanas.price = 1.39;
	bannanas.quantity = 30;
	bannanas.id = 143373;
//	bannanas.name = "dole"; will not work
//can do this scanf("%s", bannanas.name);

	strcpy(bannanas.name, "dole");
	printf("%s\n", bannanas.name); 
}
