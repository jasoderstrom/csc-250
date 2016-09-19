#include <stdio.h>

int ARR_SIZE = 10;


int main()
{
	int list[ARR_SIZE];
	int i;
	int swapped = 1;
	srand(time(NULL));

	for(i=0; i<ARR_SIZE; i++)
	{
		list[i] = rand() % 100000 + 1;
		printf("%d ", list[i]);
	}
	printf("\n");

	while(swapped == 1)
	{
		for(i=0; i<ARR_SIZE; i++)
		{
			if(list[i]<list[i+1])
			{

			}
		}
	}
	return 0;
}
