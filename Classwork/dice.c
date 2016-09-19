#include <stdio.h>

int roll(int *d1, int *d2, int *d3)
{
	int sum;
	srand(time(NULL));
	*d1 = rand() % 6 + 1;
	*d2 = rand() % 6 + 1;
	*d3 = rand() % 6 + 1;
	sum = *d1 + *d2 + *d3;

	return sum;
}

int main()
{
	int d1,d2,d3;
	int sum;

	sum = roll(&d1,&d2,&d3);

	printf("D1: %d\n", d1);
	printf("D2: %d\n", d2);
	printf("D3: %d\n", d3);
	printf("Sum: %d\n", sum);

	return 0;
}
