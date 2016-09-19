#include <stdio.h>

int main()
{
 int i, x;

 srand(time(NULL));

 for (i = 0; i < 10; ++i)
 {
  x = rand() % 6+1;

  printf("%d ", x);
 }
 printf("\n");

 return 0;
}
