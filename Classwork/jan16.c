#include <stdio.h>//printf(), scanf()
#include <string.h>

int main()
{

	char str[10];

	printf("Please enter a word: ");
	scanf("%s", str);

	printf("%s\n", str);

	printf("%c\n", str[3]);
	printf("%c\n", str[0]);

	int i = 0;
	int n = 0;
	int count = 0;
	while(str[i] != '\0')
	{
		count++;
		i++;
	}

	int len = strlen(str);

	for(i=0;i<len;i++)
	{
		printf("%c\n", str[i]);
	}


	return 0;
}
