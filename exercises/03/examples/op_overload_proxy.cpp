#include <iostream>
#include <vector>

class Array {
private:
  std::vector<double> data;

  class ArrayProxy {
  private:
    double &val;

  public:
    ArrayProxy(double &val) : val(val) {}

    // Reading operator.
    operator double() const {
      std::cout << "reading operator (const)" << std::endl;
      return val;
    }

    // Writing operator.
    ArrayProxy &operator=(const double &x) {
      std::cout << "writing operator (non-const)" << std::endl;
      val = x;
      return *this;
    }

    // Copy assignment operator.
    ArrayProxy &operator=(const ArrayProxy &other) {
      std::cout << "copy assignment (non-const)" << std::endl;
      val = other.val;
      return *this;
    }
  };

public:
  // Constructor.
  Array(const std::vector<double> &data) : data(data) {}

  // (Non-const) accessor for both reading and writing.
  ArrayProxy operator()(const unsigned int idx) {
    std::cout << "accessor (non-const)" << std::endl;
    return ArrayProxy(data[idx]);
  }

  // Const accessor for reading.
  double operator()(const unsigned int idx) const {
    std::cout << "accessor (const)" << std::endl;
    return data[idx];
  }
};

int main() {
  // Non-const array.
  Array a{{-2.3, 5, 1.2, 0.0, 7}};

  const double x = a(2); // Reading.

  a(1) = a(2) = 3; // Writing.

  std::cout << a(1) << std::endl << a(2) << std::endl; // Reading.

  // Const array.
  const Array &a_const = a;

  std::cout << a_const(1) << std::endl << a_const(2) << std::endl; // Reading.

  return 0;
}
