#include <iostream>

template <class T1, class T2> class MyPair {
public:
  T1 first;
  T2 second;

  // Constructor.
  MyPair(const T1 &a = T1{}, const T2 &b = T2{}) : first(a), second(b) {}

  // Equality operators.
  bool operator==(const MyPair &other) const {
    return (first == other.first) && (second == other.second);
  }

  bool operator!=(const MyPair &other) const { return !(*this == other); }

  // Lexicographical comparison.
  bool operator<(const MyPair &other) const {
    return (first < other.first) || (second < other.second);
  }
};

// Example usage.
int main() {
  MyPair<int, std::string> p1{1, "Hello"};
  MyPair<int, std::string> p2{2, "World"};

  std::cout << "p1: (" << p1.first << ", " << p1.second << ")" << std::endl;
  std::cout << "p2: (" << p2.first << ", " << p2.second << ")" << std::endl;

  // Testing comparison.
  if (p1 == p2) {
    std::cout << "p1 is equal to p2" << std::endl;
  } else {
    std::cout << "p1 is not equal to p2" << std::endl;
  }

  return 0;
}
