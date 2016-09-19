#include <stdio.h>
#include <string.h>

int rows = 10;//global scope variables
int cols = 5;

void get_grades(int grades[10][5]);
void print_grades(int grades[10][5]);
void print_classes(char classes[5][15]);
void calc_final_grades(int grades[10][5], char final_grade[]);
void print_final_grade(char final_grade[]);

int main(void)
{
	int grades[10][5];
	char final_grade[5];
	char classes[5][15] = {
				{"Math"},
				{"Art"},
				{"Science"},
				{"History"},
				{"Grammar"}
			      };

	get_grades(grades);
	print_classes(classes);
	print_grades(grades);
	calc_final_grades(grades, final_grade);
	print_final_grade(final_grade);

	return 0;
}

void print_final_grade(char final_grade[])
{
	int i;
	for (i=0;i<5;i++)
	{
		printf("%10c", final_grade[i]);
	}
	printf("\n");
}

void calc_final_grades(int grades[10][5], char final_grade[])
{
	int avg;
	int sum = 0;
	int i,x;

	for(i=0;i<5;i++)
	{
		for(x=0;x<10;x++)
		{
			sum += grades[x][i];
		}
		avg = sum / 10;
		sum = 0;
		if(avg > 89)
		{
			final_grade[i] = 'A';
		}
		else if (avg > 79)
		{
			final_grade[i] = 'B';
		}
		else if (avg > 69)
		{
			final_grade[i] = 'C';
		}
		else if(avg > 59)
		{
			final_grade[i] = 'D';
		}
		else
			final_grade[i] = 'F'; 
	}
}

void print_classes(char classes[5][15])
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("%10s", classes[i]);
	}
	printf("\n");
}

void get_grades(int grades[10][5])
{

	srand(time(NULL));
	int i,x;

	for(i = 0; i<10; i++)
	{
		for(x=0;x<5;x++)
		{
			grades[i][x] = rand() % 101; //0-100
		}

	}

}

void print_grades(int grades[10][5])
{
	int i,x;
	for(i=0;i<10;i++)
	{
		for(x=0;x<5;x++)
		{
			printf("%10d", grades[i][x]);

		}
		printf("\n");
	}
}
