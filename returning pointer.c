// C program to illustrate the concept of 
// returning pointer from a function
#include <stdio.h>
// Function that returns pointer
int* fun()
{
// Declare a static integer
static int A = 10;
return (&A);
}

void main() {
	int* p; // Declare a pointer
	 p = fun(); // Function call
  
	  printf("%p\n", p); // Print Address
	printf("%d\n", *p); // Print value at the above address
}
