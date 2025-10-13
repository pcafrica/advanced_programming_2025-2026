 #ifndef STATISTICS_HPP_
#define STATISTICS_HPP_

#include <vector>

namespace stat {
// Function prototypes.
double calculate_mean(const double* numbers, size_t size);
double calculate_median(const double* numbers, size_t size);
double calculate_standard_deviation(const double* numbers, size_t size) ;
} // namespace stat

#endif // STATISTICS_HPP_