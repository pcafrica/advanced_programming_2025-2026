#include "newton.hpp"

#include <complex>
#include <functional>
#include <iostream>
#include <stdexcept>

int main() {
  // Function with real root: f(x) = x^2 - 1 = 0.
  {
    // Define function and its derivative.
    auto f = [](const double &x) { return x * x - 1.0; };
    auto df = [](const double &x) { return 2.0 * x; };

    // Create a NewtonSolver instance and find the root.
    const double x0 = 0.5;
    NewtonSolver<double> solver(f, df, x0);

    try {
      const double root = solver.solve();
      std::cout << "Approximate root: " << root << std::endl;
    } catch (const std::runtime_error &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }

  // Function with complex root: f(x) = x^2 + 1 = 0.
  {
    // Define function and its derivative.
    auto f = [](const std::complex<double> &x) { return x * x + 1.0; };
    auto df = [](const std::complex<double> &x) { return 2.0 * x; };

    // Create a NewtonSolver instance and find the root.
    const std::complex<double> x0{0.5, 0.5};
    NewtonSolver<std::complex<double>> solver(f, df, x0);

    try {
      const std::complex<double> root = solver.solve();
      std::cout << "Approximate root: " << root << std::endl;
    } catch (const std::runtime_error &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }

  return 0;
}
