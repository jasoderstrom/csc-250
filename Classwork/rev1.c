#include <stdio.h>

int main()
{
	int num;
	int i=0;

	printf("Enter a number: ");
	scanf("%d", &num);
	printf("Value is %d\n", num);


	if(num >= 0)
	{
		printf("Your number is positive!\n");
	}
	else
	{
		printf("Your number is negative!\n");
	}

	if (num  % 2 == 0)
	{
		printf("Even\n");
	}
	else
	{
		printf("Odd\n");
	}

	

	for (i=1;i<=num;i++)
	{
		printf("%d", i);
	}

	printf("\n");


	i = 1;
	while (i <= num)
	{
		printf("%3d\n", i);
		i++;
	}
	printf("\n");



	return 0;

}
