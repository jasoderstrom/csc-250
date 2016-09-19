#include <stdio.h>
#include <string.h>

int main()
{
	char buff[100];
	char buff2[100];
	scanf("%s", buff);
	scanf("%s", buff2);

	//fgets(buff, 100, stdin);
	//int rem = strlen(buff)-1;
	//buff[rem] = '\0';

	//printf("%s", buff);
	printf("%s %s\n", buff, buff2);
	return 0;


}
