#include <stdio.h>
#include <string.h>

char cipherTable[26][26];

void fillTable()
{
    char start = 'A';
    char letter = 'A';
    int i,x;
    
    for(i=0;i<26;i++)
    {
        letter = start;
        printf("%2d: ", i);
        for(x=0;x<26;x++)
        {
            cipherTable[i][x] = letter;
            letter++;
            printf("%c  ", cipherTable[i][x]); 
            if(letter>'Z')
                letter = 'A';
        } 
        start++;
        printf("\n");
    }
}


void print_title()
{
    printf("\n\n");
    printf("======================\n");
    printf("Password Crypter V 2.0\n");
    printf("======================\n");
    printf("\n");
}

void print_menu()
{
    printf("\n");
    printf("Options\n");
    printf("-------\n");
    printf("(1) Encrypt password\n");
    printf("(2) Decrypt password\n");
    printf("(3) Quit\n");
    printf("\n\n");
}

int get_user_choice()
{
    int choice;
    printf("Enter selection: ");
    scanf("%d", &choice);
    return choice; 
}

void get_string(char buf[], int user_choice)
{
    char junk;

    if(user_choice == 1)
        printf("Enter passphrase to encrypt\n> ");
    else
        printf("Enter encrypted passphrase\n> ");
    
    scanf("%c", &junk);
    fgets(buf,100,stdin);
}

void get_key(char key[])
{
    printf("Enter you encryption key\n> ");
    fgets(key,50,stdin);
}

int get_letter_val(char letter)
{
    if(letter >= 'A' && letter <= 'Z')
        return letter - 65;
    else if(letter >= 'a' && letter <= 'z')
        return letter - 97;
}

void trim(char buff[])
{
    int len = strlen(buff);
    
    if(buff[len-1] == '\n')
        buff[len-1] = '\0';
}

void encrypt(char buff[], char key[])
{
    int len;
    int i,x=0;
    int plain_val, key_val;

    trim(buff);//get rid of newline on buff
    trim(key);//get rid of newline on key
    len = strlen(buff);

    for(i=0;i<len;i++)
    {
        if(buff[i] >= 'A' && buff[i] <= 'Z' || buff[i] >= 'a' && buff[i] <= 'z')//check to see if we have a letter
        {
            plain_val = get_letter_val(buff[i]);//change that letter into a number 0-25
            key_val = get_letter_val(key[x%strlen(key)]);//change the key letter into a number 0-25
            buff[i] = cipherTable[key_val][plain_val];  //get our cipher letter from the table
            x++; //incriment x which is used to get our current key letter, this helps account for spaces and special chars
        }
    }

    printf("Your encrypted string:%s\n", buff) ;

}

void decrypt(char buff[], char key[])
{
    int len;
    int i,j, x=0;
    int key_val, plain_val;
    trim(buff);//get rid of new line
    trim(key);//get rid of new line

    len = strlen(buff);

    for(i=0;i<len;i++)
    {
        if(buff[i] >= 'A' && buff[i] <= 'Z' || buff[i] >= 'a' && buff[i] <= 'z')//check if we have a letter
        {
            key_val = get_letter_val(key[x%strlen(key)]);//convert our key letter into a number 0 - 25
            for(j=0;j<26;j++)
            {
                //itterate through each element in the row coresponding to the key letter
                if(cipherTable[key_val][j] == buff[i])
                {
                    //if our the letter in the table matches our ciphertext letter stop
                    buff[i] = cipherTable[0][j];//pull out our plaintext letter
                                                //row 0 in our table is the alphabet ordered A-Z
                                                //j is a number 0-26 which represents our plain text letter
                    j=26;//set j to 26 to break out of the loop
                }
            }
            x++;
        }
    }

    printf("Your decrypted string:%s\n", buff);

}

int main()
{
    
    char buff[100];
    char key[50];
    int user_choice;

    fillTable();
    print_title();
    
    while(user_choice != 3)
    {    
        print_menu();
   
        user_choice = get_user_choice();
        
        if(user_choice == 1 || user_choice == 2)
        {    
            get_string(buff, user_choice);
            get_key(key);
            if(user_choice == 1)
                encrypt(buff,key);
            else
                decrypt(buff,key);
        }
        else if(user_choice == 3)
            printf("Goodbye!!!\n");
        else
            printf("Don't know what you entered. Try again\n");

    }
    return 0;
}
