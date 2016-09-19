#include <stdio.h>
#include <string.h>

struct employee {
	char first_name[25];
	char last_name[25];
	char email_address[25];
	int age;
	int id; 
};

	get_employees(struct employee directory[])
	{
		int i;
		int count;
		//open the file
		FILE *input;

		input = fopen("employees.txt", "r");
		//read in first value
		fscanf(input,"%d", &count);

		//loop run as many times as first line
		for(i=0;i<count;i++)
		{
			fscanf(input,"%s", directory[i].first_name);
			fscanf(input,"%s", directory[i].last_name);
			fscanf(input,"%s", directory[i].email_address);
			fscanf(input,"%d", &directory[i].id);
			fscanf(input,"%d", &directory[i].age);

		}
		//5 fscanf's, one for each field

		//end loop

		//close file
		fclose(input);
		printf("%d\n", directory[0].age);
		return count;
	}

void print_info(struct employee person)
{
	printf("%s\n", person.first_name);
	printf("%s\n", person.last_name);
	printf("%s\n", person.email_address);
	printf("%d\n", person.id);
	printf("%d\n", person.age);
}

void search(char name[], struct employee directory[], int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		if(strcmp(name, directory[i].first_name) == 0)
		{
			print_info(directory[i]);
		}
	}
}

int main()
{
	char first_name[20];
	int count;
	struct employee directory[100];
	count =	get_employees(directory);
	print_info(directory[0]);

	printf("Enter a first name: ");
	scanf("%s", first_name);
	search(first_name,directory,count);

//	strcpy(directory[0].first_name, "chad");
//	strcpy(directory[0].last_name, "mitzel");
//	directory[0].id=0;

//	directory[1].id = 23432;

//	struct employee jane;
//	jane.age = 32;
//	jane.id = 3749804713987431;
//	strcpy(jane.first_name,"jane");
//	strcpy(jane.last_name, "smith");
//	strcpy(jane.email_address, "j.s@ceo.com");
 
//	char jan_first_name[] = "Jan";
//	char jan_last_name[] = "Doe";
//	char jan_email[] = "jan@mycompany.com";
//	int jan_age = 28;
//	int jan_id = 1283854;

}
