#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[10];//syntatic sugar
	int *arr2 = malloc(10 * sizeof(int));
	arr2[5] = 20;
	arr[4] = 10;
	arr2[6] = 20;

	free(arr2);
}
