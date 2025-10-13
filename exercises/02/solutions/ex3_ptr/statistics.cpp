#include "statistics.hpp"
#include <algorithm>
#include <cmath>

namespace stat {

double calculate_mean(const double *numbers, size_t size) {
  double sum = 0.0;
  for (size_t i = 0; i < size; ++i) {
    sum += numbers[i];
  }

  return sum / size;
}

double calculate_median(const double *numbers, size_t size) {
  double *sorted_numbers = new double[size];

  for (size_t i = 0; i < size; ++i) {
    sorted_numbers[i] = numbers[i];
  }

  std::sort(sorted_numbers, sorted_numbers + size);

  double median;
  if (size % 2 == 0) {
    size_t mid = size / 2;
    median = (sorted_numbers[mid - 1] + sorted_numbers[mid]) / 2.0;
  } else {
    median = sorted_numbers[size / 2];
  }

  delete[] sorted_numbers;

  return median;
}

double calculate_standard_deviation(const double *numbers, size_t size) {
  double mean = calculate_mean(numbers, size);

  double variance = 0.0;
  for (size_t i = 0; i < size; ++i) {
    variance += (numbers[i] - mean) * (numbers[i] - mean);
  }

  return std::sqrt(variance / size);
}

} // namespace stat
