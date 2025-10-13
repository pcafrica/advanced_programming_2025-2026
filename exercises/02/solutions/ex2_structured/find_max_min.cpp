#include <iostream>

// Function to find and display the maximum and minimum values in an array.
void find_max_min(int *arr, unsigned int size, int &max_val, int &min_val) {
  if (size == 0) {
    std::cout << "Array is empty." << std::endl;
    return;
  }
  max_val = arr[0]; // Initialize max_val to the first element.
  min_val = arr[0]; // Initialize min_val to the first element.

  for (unsigned int i = 1; i < size; ++i) {
    if (arr[i] > max_val) {
      max_val = arr[i]; // Update max_val if a larger element is found.
    } else if (arr[i] < min_val) {
      min_val = arr[i]; // Update min_val if a smaller element is found.
    }
  }
}
