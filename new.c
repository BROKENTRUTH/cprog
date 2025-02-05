#include <stdio.h>
#include <math.h>

// Function to move a disk
void moveDisk(char from, char to) 
{
    printf("Move disk from %c to %c\n", from, to);
}

// Function to solve Tower of Hanoi iteratively
void towerOfHanoiIterative(int n, char source, char auxiliary, char destination) 
{
    int totalMoves = pow(2, n) - 1; // Total number of moves for n disks
    int i;

    // If number of disks is even, swap destination and auxiliary
    if (n % 2 == 0) {
        char temp = destination;
        destination = auxiliary;
        auxiliary = temp;
    }

    for (i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            // Move between source and destination
            if (i % 2 == 1) {
                moveDisk(source, destination);
            } else {
                moveDisk(destination, source);
            }
        } else if (i % 3 == 2) {
            // Move between source and auxiliary
            if (i % 2 == 1) {
                moveDisk(source, auxiliary);
            } else {
                moveDisk(auxiliary, source);
            }
        } else if (i % 3 == 0) {
            // Move between auxiliary and destination
            if (i % 2 == 1) {
                moveDisk(auxiliary, destination);
            } else {
                moveDisk(destination, auxiliary);
            }
        }
    }
}

void tower(int numdisks, char left, char center, char right)
{
	if(numdisks==0)
	  return;

	//1. Move the top n - 1 disks from the left pole to the center pole.
	//   Using right pole as the temporary pole
	tower(numdisks-1, left, right, center);

	//2. Move the nth disk (the largest disk) to the right pole.
	moveDisk(left, right);
	//3. Move the n - 1 disks on the center pole to the right pole.
	//   Using left pole as the temporary pole
	tower(numdisks-1, center, left, right);
}


int main() {
    int n; // Number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    //towerOfHanoiIterative(n, 'L', 'C', 'R'); // L is source, C is auxiliary, R is destination
    
	tower(n, 'L', 'C', 'R'); // L is source, C is auxiliary, R is destination
    return 0;
}

