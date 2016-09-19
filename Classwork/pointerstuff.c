#include <stdio.h>

void func(int *y)
{
	*y = 100;
}

int main()
{
	char arr[10];
	int x = 10;
	printf("X is: %d\n", x);
	int *y = &x;//referencing the memory(get the memory addr)
	//*y = 15;//dereferencing the memory(put something into the memory)
//	scanf("%d", y);
//	printf("X is: %d\n", x);

	func(y);
	func(&x);
}
