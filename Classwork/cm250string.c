#include <stdio.h>
#include <string.h> //the string library includes useful functions like strlen() and strcpy()
int main()
{
    char buff[100]; //declare a string buffer of 100, we can hold up to 100 characters in here

   printf("Enter a string: ");

    scanf("%s", buff); //read the input from our keyboard into our buffer

    printf("%s\n", buff); //print out what we just typed in

    //just to prove that a string is nothing more then an array of characters
    int i;
	int count = 0;

   	 for(i=0;i<strlen(buff);i++)
	{
       		 printf("%c\n", buff[i]); //use %c because each element of the array is a char data type

		if(buff[i] == 'a')
		{
			count++;
		}
	}

	printf("There were %d a's in your string\n" , count);

    return 0;
}
