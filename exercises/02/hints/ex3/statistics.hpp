#ifndef STATISTICS_HPP__
#define STATISTICS_HPP__

#include <vector>

namespace stat {
// Function prototypes.
double calculate_mean(const std::vector<double> &numbers);
double calculate_median(const std::vector<double> &numbers);
double calculate_standard_deviation(const std::vector<double> &numbers);
} // namespace stat

#endif // STATISTICS_HPP__
