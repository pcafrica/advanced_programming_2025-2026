<!--
title: Exercise session 09
paginate: true

_class: titlepage
-->

# Exercise session 09
<br>

## Optimization, debugging, profiling, testing.
<br>

#### Advanced Programming - SISSA, UniTS, 2025-2026

###### Pasquale Claudio Africa

###### 25 Nov 2025

---

# Exercise 1: Optimization

The `hints/ex1/` directory contains the implementation of a class for dense matrices organized as **column-major**.

- Implement `Matrix::transpose()`, a method to compute $A = A^T$.
- Implement `operator*`, a function to compute matrix-matrix multiplication.
- Optimize the matrix-matrix multiplication by transposing the first factor before the computation. Compare the execution speed with the previous implementation.
- Use `valgrind --tool=callgrind` to generate a profiler report.
- Generate a coverage report using `lcov` and `genhtml`.

---

# Exercise 2: Debugging

The `hints/ex2/` directory contains an implementation of a double-linked list class. The class stores a pointer to the head, and each node (except for the head and the tail, obviously) contains a pointer to the previous and to the next node.

The implementation contains a lot of errors, namely:

1. Compilation and syntax errors.
2. Runtime errors, including a segmentation fault and a problem in printing the list.
3. Memory leaks.
4. Two possible *segmentation fault*s, not captured by the `main`.

With the help of `gdb` and `valgrind`, solve all these issues and make the code working!

---

# Exercise 3: Testing

The `hints/ex3/` contains a static function to compute the mean of a `std::vector`.

Following the given directory structure and using [Google Test](https://google.github.io/googletest/), fill in the missing parts in `tests/mean.cpp` to check that the function behaves as expected in all the listed cases.

To run the testsuite type
```bash
make test
```
or
```bash
ctest
```
from the CMake build folder.
