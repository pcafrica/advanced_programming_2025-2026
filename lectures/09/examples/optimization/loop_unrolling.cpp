#include <chrono>
#include <iostream>
#include <vector>

double multiply(const std::vector<double> &data) {
  double result = 1;

  for (const auto &v : data)
    result *= v;

  return result;
}

double multiply_with_unrolling(const std::vector<double> &data) {
  double result = 1;

  double a0, a1, a2, a3;

  size_t i;
  for (i = 0; i + 3 < data.size(); i += 4) {
    a0 = data[i];
    a1 = data[i + 1];
    a2 = data[i + 2];
    a3 = data[i + 3];

    result *= a0 * a1 * a2 * a3;
  }

  // Handle remaining elements.
  for (; i < data.size(); ++i) {
    result *= data[i];
  }

  return result;
}

int main(int argc, char **argv) {
  using timer = std::chrono::high_resolution_clock;

  // Generate an arbitrary dataset.
  const std::vector<double> data(1e6, 1.00001);

  {
    auto start = timer::now();
    const double result = multiply(data);
    auto end = timer::now();

    std::cout << "Multiply: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                       start)
                     .count()
              << " microseconds, result: " << result << "." << std::endl;
  }

  {
    auto start = timer::now();
    const double result = multiply_with_unrolling(data);
    auto end = timer::now();

    std::cout << "Multiply (with unrolling): "
              << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                       start)
                     .count()
              << " microseconds, result: " << result << "." << std::endl;
  }

  return 0;
}
