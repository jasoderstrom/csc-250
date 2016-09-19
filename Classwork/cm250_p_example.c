#include <stdio.h>

void pass_by_reference(int *x)
{
	*x = 15;
}

int main()
{
	int x = 10; //declare a normal integer data type
	int *y; //declare an integer pointer
	
	y = &x; //set y equal to the address of of the variable x.
			//note i do not have a * in front of the y
	
	printf("x is: %d\n", x);
	printf("y points at to the memory location: %p\n", y);
	printf("which hold the value: %d\n", *y);
			
	*y = 20; //set the value at the memory address stored in y equal to 20
	// the line above is drastically different from y = 20;
	// y = 20 sets the memory address pointed to by y to be memory address 20,
    // without a * infront of it you cannot affect the value
    	
	printf("x is: %d\n", x);
	printf("y points at to the memory location: %p\n", y);
	printf("which hold the value: %d\n", *y);
	
	//the next 2 lines of code are equivalent
	pass_by_reference(&x);
	pass_by_reference(y);
	
	//the next 2 lines are also equivalent
	scanf("%d", &x);
	scanf("%d", y);
	
	//we can change the pointer to point somewhere else as well
	printf("x is: %d\n", x);
	printf("y points at to the memory location: %p\n", y);
	printf("which hold the value: %d\n", *y);

	int z = 40;
	y = &z;
	
	printf("x is: %d\n", x);
	printf("y points at to the memory location: %p\n", y);
	printf("which hold the value: %d\n", *y);

	return 0;
}
