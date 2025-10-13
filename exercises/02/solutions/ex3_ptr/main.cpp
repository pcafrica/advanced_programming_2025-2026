#include "statistics.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>

void resize_array(double *&data, size_t current_size, size_t new_capacity) {
  if (new_capacity <= current_size) {
    return;
  }

  double *new_data = new double[new_capacity];

  for (size_t i = 0; i < current_size; ++i) {
    new_data[i] = data[i];
  }

  delete[] data;

  data = new_data;
}

int main() {
  std::cout << "Statistics calculator (using pointers)" << std::endl;

  double *numbers = nullptr;
  size_t size = 0;
  size_t capacity = 0;
  const size_t INITIAL_CAPACITY = 10;

  std::string input;

  double num;
  std::istringstream iss;

  while (true) {
    std::cout
        << "Enter a set of numbers separated by spaces (or 'q' to quit): ";
    std::getline(std::cin, input);

    if (input == "q" || input == "Q") {
      break;
    }

    if (numbers != nullptr) {
      delete[] numbers;
      numbers = nullptr;
    }
    size = 0;
    capacity = 0;

    iss.clear();
    iss.str(input);

    while (iss >> num) {
      if (size >= capacity) {
        size_t new_capacity = (capacity == 0) ? INITIAL_CAPACITY : capacity * 2;
        resize_array(numbers, size, new_capacity);
        capacity = new_capacity;
      }

      numbers[size] = num;
      size++;
    }

    if (size == 0) {
      std::cout << "Invalid input. Please enter numbers." << std::endl;
      continue;
    }

    const double mean = stat::calculate_mean(numbers, size);
    const double median = stat::calculate_median(numbers, size);
    const double stddev = stat::calculate_standard_deviation(numbers, size);

    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Median: " << median << std::endl;
    std::cout << "Standard deviation: " << stddev << std::endl;
  }

  if (numbers != nullptr) {
    delete[] numbers;
  }

  return 0;
}
