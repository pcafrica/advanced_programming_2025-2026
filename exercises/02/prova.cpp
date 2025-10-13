#include <iostream>

void modify_by_copy(int x) {
	// Creates a copy of 'x' inside the function.
	x = 20; // Changes the copy 'x', not the original value.
	}
void modify_by_ptr(int* ptr) {
	*ptr = 30; // Modifies the original value via the pointer.
	}
void modify_by_ref(int& ref) {
	ref = 40; // Modifies the original value through the reference.
	}

int main() {

	int value = 20;
	int* ptr = &value;
	std::cout << ptr << std::endl;

	modify_by_copy(value); // Pass by value.
	std::cout << value << std::endl; // Output: 10.
	modify_by_ptr(&value); // Pass by pointer
	std::cout << value << std::endl; // Output: 30.
	modify_by_ref(value); // Pass by reference
	std::cout << value << std::endl;
  	return 0;
}
