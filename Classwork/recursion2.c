#include <stdio.h>

int rec(int i)
{
	if(i==10)
		printf("Done\n");
	else
	{
		printf("In function %d\n", i);
		i++;
		rec(i);
		return 0;
	}
}

int main()
{
	int i=0;
	rec(i);
}
