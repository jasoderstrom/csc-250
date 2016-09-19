#include <stdio.h>
int *ret()
{
	static int arr[10];
	return arr;
}

int main()
{
	int *arr = ret();
	printf("%d\n", arr[0]);
	arr[0] = 15;
	printf("%d\n", arr[0]);
	arr[0] = 15;
}
