/*Author: Justin Soderstrom
  Project: Assignment 2
  Objective: Create a Vigenere Cipher
  Date: February 18, 2015
*/

#include <stdio.h>
#include <string.h>

void print_title(void)//printed title
{
    printf("\n\n");
    printf("======================\n");
    printf("Password Crypter V 2.0\n");
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

void get_string(char buff[], char key[])
{
	char extra; //used to store newline character from user_choice scanf()

	scanf("%c", &extra);

	printf("Please enter your password: ");

	fgets(buff, 500, stdin);

	printf("Please enter a keyword: ");

	scanf("%s", key); //stores keyword
}

void generateTable(char table[26][26])//generates encryption table
{
	int x = 0;
	int y = 0;
	int count = 0;
	char start;
	char current;

	for(x=0; x<26; x++)
	{
		start = 'A' + count;
		current = start;

		for(y=0; y<26; y++)
		{
			table[x][y] = current;
			current += 1;

			if(current > 'Z')
			{
				current = 'A';
			}

			//printf("%2c", table[x][y]); (Used to print generated table)
		}
		count++;
		//printf("\n"); (Used to print generated table)
	}

}
int letterConvert(char letter)//converts letters into numbers
{
	if(letter >= 'A' && letter <= 'Z')
	{
		letter -= 'A';
	}
	else
	{
		letter -= 'a';
	}

	return letter;
}
char caseConvert(char letter)//changes lowercase letters into uppercase letters
{
	if(letter >= 'a' && letter <= 'z')
	{
		letter -= 32;
	}

	return letter;
}
void encrypt(char buff[], char key[], char table[26][26])
{
	int i; 
	int x = 0;
	int con_x;//coordinate for the keyword
	int con_y;//coordinate for the password

	get_string(buff, key);

	for(i=0;i<strlen(buff)-1;i++)
	{
		if(buff[i] >= 'A' && buff[i] <= 'Z' || buff[i] >= 'a' && buff[i] <= 'z')
		{
			con_y = letterConvert(buff[i]);
			con_x = letterConvert(key[x%strlen(key)]);
			buff[i] = table[con_y][con_x];
			x++;
		}
	}

	printf("Your encrypted password is: %s", buff); 
}

void decrypt(char buff[], char key[], char table[26][26])
{
	int j;
	int k;
	int con_y;//coordinate for the keyword
	int x = 0;

	get_string(buff, key);

	for(j<0;j<strlen(buff)-1;j++)
	{
		if(buff[j] >= 'A' && buff[j] <= 'Z' || buff[j] >= 'a' && buff[j] <= 'z')
		{
			con_y = letterConvert(key[x%strlen(key)]);
			buff[j] = caseConvert(buff[j]);

			for(k=0; k<26; k++)
			{
				if(table[con_y][k] == buff[j])
				{
					k += 'A';
					buff[j] = k;
					break;
				}
			}
			x++;
		} 
	}

	printf("Your decrypted password is: %s", buff);
}

int main(void)
{
    char buff[500];
    char key[500];
    char table[26][26];
    int user_choice = 0;

    generateTable(table);

    while(user_choice != 3)
    {
    	print_title();
    	print_menu();

    	user_choice = get_user_choice();

    	if(user_choice == 1)//decrypt password
    	{
		 encrypt(buff, key, table);
    	}
    	else if(user_choice == 2)//encrypt password
    	{
		 decrypt(buff, key, table);
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
