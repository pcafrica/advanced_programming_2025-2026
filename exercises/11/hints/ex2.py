#!/usr/bin/env python3

from time import perf_counter
from abc import ABC, abstractmethod

class Polynomial(ABC):
    def __init__(self, *coefficients):
        self.coefficients = list(coefficients)

    def __repr__(self):
        # TODO: Implement string representation.
        # Example: [1, 2, 3] -> "1 + 2x + 3x^2".
        pass

    def __add__(self, other):
        # TODO: Implement polynomial addition.
        # Hint: Pad shorter polynomial with zeros.
        pass
    
    @abstractmethod
    def evaluate(self, x):
        pass


class StandardPolynomialEvaluator(Polynomial):
    def evaluate(self, x):
        # TODO: Implement standard evaluation.
        # P(x) = a0 + a1*x + a2*x^2 + ...
        pass


class HornerPolynomialEvaluator(Polynomial):
    def evaluate(self, x):
        # TODO: Implement Horner's rule.
        # P(x) = a0 + x*(a1 + x*(a2 + ...))
        pass


# TODO: Implement measure_time decorator.
def measure_time(func):
    pass


@measure_time
def evaluate_polynomial(poly_evaluator, x_list):
    return [poly_evaluator.evaluate(x) for x in x_list]


if __name__ == "__main__":
    # Test basic operations.
    poly1 = StandardPolynomialEvaluator(1, 2, 3)
    print(f"poly1: {poly1}")
    
    poly2 = StandardPolynomialEvaluator(2, 3, 4)
    print(f"poly2: {poly2}")
    
    # Test evaluation.
    print(f"poly1(2) = {poly1.evaluate(2)}")  # Should be 1 + 4 + 12 = 17
    
    # TODO: Test addition.
    # TODO: Compare Standard vs Horner performance on 1000 points.
