#ifndef STATISTICS_HPP__
#define STATISTICS_HPP__

#include <vector>

namespace stat {
// Function prototypes.
double calculate_mean(const double *numbers, size_t size);
double calculate_median(const double *numbers, size_t size);
double calculate_standard_deviation(const double *numbers, size_t size);
} // namespace stat

#endif // STATISTICS_HPP__
