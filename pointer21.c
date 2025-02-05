#include <stdio.h>
#include <stdlib.h>
int main()
{
int rows = 3, cols = 4, i, j;
int **array = (int **) malloc(rows * sizeof(int *)); // Allocate memory
if (array == NULL) { // for the row pointers
printf("Memory allocation failed!\n");
return 1;
}
array[0] = (int *) malloc(rows * cols * sizeof(int)); // Allocate memory

if (array[0] == NULL) { // for the entire 2D array
printf("Memory allocation failed!\n"); // as a single contiguous block
free(array);
return 1;
}

for (i = 1; i < rows; i++) // Point each row pointer to the appropriate
array[i] = array[0] + i * cols; // position in the contiguous block
for (i = 0; i < rows; i++) // Fill the 2D array
for (j = 0; j < cols; j++)
array[i][j] = i * cols + j;
printf("2D Array:\n"); // Print the 2D array
for (i = 0; i < rows; i++) {
for (j = 0; j < cols; j++) {
printf("%d ", array[i][j]);
}
printf("\n");
}
free(array[0]); // Free the contiguous memory block
free(array); // Free the row pointers
return 0;
}
// In a three dimensional array each element can be assessed by using three subscripts.
int arr[2][3][2] = { {{5, 10}, {6, 11}, {7, 12}}, {{20, 30}, {21, 31}, {22, 32}} };
// We can consider a three dimensional array to be an array of 2-D array i.e each element of a 3-
// D array is considered to be a 2-D array. The 3-D array arr can be considered as an array
// consisting of two elements where each element is a 2-D array.
// The name of the array arr is a pointer to the 0th 2-D array.
// Thus, the pointer expression *(*(*(arr + i ) + j ) + k) is equivalent to the subscript expression
// arr[i][j][k].
