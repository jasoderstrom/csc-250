/*Author: Justin Soderstrom
  Section: CSC 250 9:00am
  Date: January 21, 2015
  Objective: Create three functions. Two functions will return the max and min of an array, and the last function will determine how many times a 
  value occurs in the array.
*/

#include <stdio.h>

int biggest(int list[], int n);
int smallest(int list[], int n);
int freq(int A[], int n, int val);

int main(void)
{
	int i,x;
	int list[10];

	srand(time(NULL));

	for(i=0; i<10; i++)
	{
		list[i] = rand() % 10 + 1;
	}

	x = biggest(list, 10);
	printf("Max is %d\n", x);

	x = smallest(list, 10);
	printf("Min is %d\n", x);

	x = freq(list, 10, 7);
	printf("There are %d 7s\n", x); 

	return 0;
}

int biggest(int list[], int n)
{
	int j = 0;
	int max = list[0];

	for(j=0; j<n; j++)
	{
		if(list[j] > max)
		{
			max = list[j];
		}
	}

	return max;
}

int smallest(int list[], int n)
{
	int k = 0;
	int min = list[0];

	for(k=0; k<n; k++)
	{
		if(list[k] < min)
		{
			min = list[k];
		}

	}

	return min;
}


int freq(int A[], int n, int val)
{

	int j = 0;
	int count = 0;

	for(j=0; j<n; j++)
	{
		if(val == A[j])
		{
			count++;
		}

	}

	return count;
}
