#include <stdio.h>
#include <string.h>

int main(void)
{

	int arr[5][5] = {
			  {10,10,10,10,10},
			  {10,10,10,10,10}
			};

	int i,x;

	for(i=0;i<5;i++)
	{
		for(x=0;x<5;x++)
		{
			//printf("%d ", arr[i][x]);
			arr[i][x] = 10;
		}
		printf("\n");
	}

	for(i=0;i<5;i++)
	{
		for(x=0;x<5;x++)
		{
			printf("%d ", arr[x][i]);
		}
		printf("\n");
	}
}
