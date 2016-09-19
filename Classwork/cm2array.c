#include <stdio.h>

int main()
{
 int A[10];
 int i, x;
 int sum = 0;

 srand( time(NULL) );

 for (i = 0; i < 10; ++i)
   A[i] = rand() % 6 + 1;

 for (i = 0; i < 10; ++i)
   printf("%d  ", A[i]);
 printf("\n");

 sum = 0; 
 for (i = 0; i < 10; ++i)
  {
   sum = sum + A[i];
  }
 printf("Sum of array elements is %d\n", sum);


 return 0;
}
