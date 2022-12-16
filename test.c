#include <stdio.h>
#include <stdlib.h>

// Define the structure
typedef struct {
  int x;
  int y;
} Point;

// Pop the first element of an array of structures with dynamic allocated memory
Point pop_first(Point** arr, int* size) {
  // Check if the array is empty
  if (*arr == NULL) {
    Point p = {-1, -1}; // Return a special value to indicate an error
    return p;
  }

  // Allocate a new array that is one element smaller than the original array
  Point* new_arr = malloc((*size - 1) * sizeof(Point));

  // Copy all the elements of the original array, except the first element, into the new array
  for (int i = 0; i < (*size - 1); i++) {
    new_arr[i] = (*arr)[i + 1];
  }

  // Free the memory allocated for the original array
  free(*arr);

  // Set the original array pointer to point to the new array
  *arr = new_arr;

  // Decrement the size of the array
  (*size)--;

  // Return the popped element
  return (*arr)[0];
}

int main() {
  // Allocate an array of 5 structures
  Point* arr = malloc(5 * sizeof(Point));
  int size = 5;

  // Populate the array with some values
  for (int i = 0; i < size; i++) {
    arr[i].x = i + 1;
    arr[i].y = i + 1;
  }

  // Print the original array
  printf("Original array:\n");
  for (int i = 0; i < size; i++) {
    printf("(%d, %d) ", arr[i].x, arr[i].y);
  }
  printf("\n");

  // Pop the first element of the array
  Point popped = pop_first(&arr, &size);
  if (popped.x == -1 && popped.y == -1) {
    // Array is empty
    printf("Array is empty\n");
    return 0;
  }

  // Print the modified array
  printf("Modified array:\n");
  for (int i = 0; i < size; i++) {
    printf("(%d, %d) ", arr[i].x, arr[i].y);
  }
  printf("\n");

  // Print the popped element
  printf("Popped element: (%d, %d)\n", popped.x, popped.y);

  // Free the memory allocated for the array
  free(arr);

  return 0;
}