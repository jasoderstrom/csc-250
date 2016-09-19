#include <stdio.h>

void hi()
{
 printf("Hello\n");
 printf("Goodbye\n");
}

void line( int n )
{
 int i;
 for (i = 0; i < n; ++i)
   printf("-");
 printf("\n");
}

int getnum( int range )
{
 int res;
 res = rand() % range;
 return res;
}

int sumArray( int A[], int N )
{
 int i;
 int sum = 0;
 for (i = 0; i < N; ++i)
   sum = sum + A[i];
 return sum;
}


void  showArray( int A[], int N )
{
 int i;
 for (i = 0; i < N; ++i)
  printf("%d  ", A[i]);
 printf("\n");
}


int main()
{
 int i, x;
 int list[8];
 int ans;

 srand( time(NULL) );

 line( 40 );
 hi();
 line( 20 );

 x = getnum( 15 );
 printf("X is %d\n", x);
 line( x );

 for (i = 0; i < 8; ++i)
 {
   list[i] = getnum( 20 ); 
 }

 showArray( list, 8 );
 showArray( list, 5 );
 ans = sumArray( list, 5 );
 printf("%d is sum of first 5 items in list\n", ans);
 line( 40 );

 
 return 0;
}
