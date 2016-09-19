/*Author: Justin Soderstrom
  Assignment: A3
  Date: 2/23/15
*/

#include <stdio.h>
#include <stdlib.h>


void print_menu();
void generate_numbers(int numbers[], int size);//this function should fill an array of n size
void write_to_file(int numbers[], int size);//this function should write that array to a file
int *read_from_file(int *n);//this function should read data from a file into an array
int get_user_choice();
int find_sum(int arr[], int n);
int find_avg(int sum, int n);
int find_max(int arr[], int n);
int find_min(int arr[], int n);

int main()
{
   int choice = 0;
   int n;

    while(choice != 3)
    {
        print_menu();
        choice = get_user_choice();
        //get n from user
	if(choice == 1)
	{
		int size;
		printf("How many numbers do you want?");
		scanf("%d", &size);

		int numbers[size];

		generate_numbers(numbers, size);
		write_to_file(numbers, size);
	}
	else if(choice == 2)
	{
		int *arr = read_from_file(&n);
		int sum = find_sum(arr, n);//why don't I need the stars in arr here? Is it because its an array?
		int avg = find_avg(sum, n);
		int max = find_max(arr, n);
		int min = find_min(arr, n);

		printf("The sum of the numbers were %d\n", sum);
		printf("The average of the numbers were %d\n", avg);
		printf("The maximum of the numbers were %d\n", max);
		printf("The minimum of the numbers were %d\n", min);

		free(arr);//is this correct placement?
	}
	else if(choice == 3)
	{
		printf("See you later!\n");
	}
	else
	{
		printf("That was not one of the choices. Please try again. \n"); 
	}
    }
}

void print_menu()
{
    printf("\n");
    printf("(1) Generate numbers & write to file\n");
    printf("(2) Read from file and get stats\n");
    printf("(3) Quit program\n");
    printf("\n");
}

int get_user_choice()
{
    int choice;
    printf("Please make a selection:");
    scanf("%d", &choice);
    return choice;
}

void generate_numbers(int numbers[], int size)
{
	int i;

	srand(time(NULL));

	for(i=0; i<size; i++)
	{
		numbers[i] = rand() % 1000000 + 1;
	}

}

void write_to_file(int numbers[], int size)
{
	int j;
	int count = 1;

	FILE *of;
	of = fopen("data.txt", "w");

	fprintf(of, "%d\n", size);

	for(j=0; j<size; j++)
	{
		if(count != 10)
		{
			fprintf(of, "%d ", numbers[j]);
		}
		else
		{
			fprintf(of, "%d \n", numbers[j]);
			count = 0;
		}
		count++;
	}

	fclose(of);
}

int *read_from_file(int *n)//why do we need the * front of read?
{
	int k;

	FILE *fp;

	fp = fopen("data.txt", "r");

	fscanf(fp,"%d", n);

	int *arr = malloc(*n * sizeof(int));//why cant we just create it into an array?

	for(k=0; k<*n; k++)
	{
		//k = 4
		fscanf(fp, "%d", &arr[k]);//why do we need the ampersand here?
	}

	fclose(fp);

	return arr;//is this a memory address?
}

int find_sum(int arr[], int n)
{
	int l;
	int sum = 0;

	for(l=0; l<n; l++)
	{
		sum += arr[l];
	}

	return sum;
}

int find_avg(int sum, int n)
{
	int avg = sum / n;

	return avg;
}

int find_max(int arr[], int n)
{
	int m;
	int max = 0;

	for(m=0; m<n; m++)
	{
		if(arr[m] > max)
		{
			max = arr[m];
		}
	}

	return max;
}

int find_min(int arr[], int n)
{
	int p;
	int min = 1000000;

	for(p=0; p<n; p++)
	{
		if(arr[p] < min)
		{
			min = arr[p];
		}
	}

	return min;
}
