#include <stdio.h>

void func(int *x)
{
	*x = 16;
	printf("%d\n", *x);
	printf("%x\n", x); //gives memory address instead of the value

	int y;
	int arr[10];
	scanf("%d", &y);//points to memory address
	scanf("%d", arr[y]);//arrays already do this, so dont need ampersand
	printf("%x\n", arr);//gives starting memory location of the array

	//int arr[10
	//int *arr are equivalent
}

int main()
{
	int x;
	func(&x);//pass by reference, vs pass by value
	printf("%d\n", x);
}
