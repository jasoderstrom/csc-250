#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i;
	int j;
	char arr[5][10];

	for(i=0; i<10; i++)
	{
		for(j=0; j<5; j++)
		{
			arr[i][j] = 'A';
			printf("%2c", arr[j][i]);
		}
		printf("\n");
	}

}
