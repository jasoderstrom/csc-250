/*Author: Justin Soderstrom
  Project: Assignment 1
  Objective: Create a Shift Cipher that shifts passwords by 3 characters
  Date: February 6, 2015
*/

#include <stdio.h>
#include <string.h>

void print_title(void)//printed title
{
    printf("\n\n");
    printf("======================\n");
    printf("Password Crypter V 1.0\n");
    printf("======================\n");
    printf("\n");
}

void print_menu(void)//printed menu
{
    printf("\n");
    printf("Options\n");
    printf("-------\n");
    printf("(1) Encrypt password\n");
    printf("(2) Decrypt password\n");
    printf("(3) Quit\n");
    printf("\n\n");
}

int get_user_choice(void)
{
	int user_choice;

	printf("Please make a selection: ");

	scanf("%d", &user_choice);//retrieves user selection from menu

	return user_choice;
}

void get_string(char buff[])
{
	char extra; //used to store newline character from user_choice scanf()

	scanf("%c", &extra);

	printf("Please enter your password: ");

	fgets(buff, 500, stdin);
}


void encrypt(char buff[])
{
	int i;

	get_string(buff);

	for(i=0;i<strlen(buff)-1;i++)//shifts password forward by 3 characters
	{
		buff[i] += 3;
	}

	printf("Your encrypted password is: %s", buff); 
}

void decrypt(char buff[])
{
	int j;

	get_string(buff);

	for(j<0;j<strlen(buff)-1;j++)//shifts password back by 3 characters
	{
		buff[j] -= 3;
	}

	printf("Your decrypted password is: %s", buff);
}

int main(void)
{
    char buff[500];
    int user_choice = 0;

    while(user_choice != 3)
    {
    	print_title();
    	print_menu();

    	user_choice = get_user_choice();

    	if(user_choice == 1)//decrypt password
    	{
		 encrypt(buff);
    	}
    	else if(user_choice == 2)//encrypt password
    	{
		 decrypt(buff);
    	}
	else if(user_choice == 3)//goodbye statement
	{
		 printf("See you later!\n");
	}
    	else //error statement
    	{
		printf("That was not one of the choices in the list. Please try again.\n");
    	}
     }

    return 0;
}
