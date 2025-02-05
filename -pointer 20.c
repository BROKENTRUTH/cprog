#include <stdio.h>
#include <stdlib.h>
void first_main() {
int rows = 3, cols = 4, i, j;
// Allocate memory for an array of row pointers
int** array = (int**)malloc(rows * sizeof(int*));
// Allocate memory for each row
for (i = 0; i < rows; i++) {
array[i] = (int*)malloc(cols * sizeof(int));
}
// Fill the array with values and print
for (i = 0; i < rows; i++) {
for (j = 0; j < cols; j++) {
array[i][j] = i * cols + j;
printf("%d ", array[i][j]);
}
printf("\n");
}
// Free the allocated memory
for (i = 0; i < rows; i++) {
free(array[i]);
}
free(array);
}
// Non-contiguous Allocation of a Two-Dimensional Array
#include <stdio.h>
#include <stdlib.h>
int main() {
int rows = 3, cols = 4, i, j;
// Allocate contiguous memory for the 2D array
int* array = (int*)malloc(rows * cols * sizeof(int));
if (array == NULL) {
printf("Memory allocation failed!\n");
return 1;
}
// Access elements using simulated 2D array notation
for (i = 0; i < rows; i++) {
for (j = 0; j < cols; j++) {
array[i * cols + j] = i * cols + j; // Store values
}
}
// Print the 2D array using array notation
printf("2D Array:\n");
for (i = 0; i < rows; i++) {
for (j = 0; j < cols; j++) {
printf("%d ", array[i * cols + j]); // Access values
}
printf("\n");
}
free(array); // Free the allocated memory
return 0;
}
