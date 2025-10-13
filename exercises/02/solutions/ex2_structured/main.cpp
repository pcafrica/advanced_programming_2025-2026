#include <cstdlib> // For rand() and srand().
#include <ctime>   // For time().
#include <iostream>
#include "find_max_min.hpp"

int main() {
  unsigned int size;

  // Prompt the user for the size of the array.
  std::cout << "Enter the size of the array: ";
  std::cin >> size;

  if (size == 0) {
    std::cout << "Invalid array size. Please enter a positive integer."
              << std::endl;

    return 1; // Exit with an error code.
  }

  // Dynamically allocate memory for the array.
  int *arr = new int[size];

  // Seed the random number generator with the current time.
  srand(time(nullptr));

  // Fill the array with random integers.
  for (unsigned int i = 0; i < size; ++i) {
    arr[i] = rand() % 100; // Generates random integers between 0 and 99.
  }

  // Find and display the maximum and minimum values in the array.
  int max_val, min_val;
  find_max_min(arr, size, max_val, min_val);

  std::cout << "Array elements:" << std::endl;
  for (unsigned int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Maximum value: " << max_val << std::endl;
  std::cout << "Minimum value: " << min_val << std::endl;

  // Deallocate the dynamically allocated memory.
  // If forgotten, a memory leak will occur.
  delete[] arr;

  return 0;
}
