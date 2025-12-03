#!/usr/bin/env python3

from time import perf_counter
from abc import ABC, abstractmethod
import numpy as np

class Polynomial(ABC):
    def __init__(self, *coefficients):
        self.coefficients = coefficients

    def __repr__(self):
        if not self.coefficients:
            return "0"
        
        terms = []
        for degree, coeff in enumerate(self.coefficients):
            if coeff == 0:
                continue
            
            if degree == 0:
                term = str(coeff)
            elif degree == 1:
                if coeff == 1:
                    term = "x"
                elif coeff == -1:
                    term = "-x"
                else:
                    term = f"{coeff}x"
            else:
                if coeff == 1:
                    term = f"x^{degree}"
                elif coeff == -1:
                    term = f"-x^{degree}"
                else:
                    term = f"{coeff}x^{degree}"
            
            terms.append(term)
        
        if not terms:
            return "0"
        
        result = terms[0]
        for term in terms[1:]:
            if term.startswith('-'):
                result += f" - {term[1:]}"
            else:
                result += f" + {term}"
        
        return result

    def __add__(self, other):
        max_len = max(len(self.coefficients), len(other.coefficients))
        
        result_coeffs = []
        for i in range(max_len):
            self_coeff = self.coefficients[i] if i < len(self.coefficients) else 0
            other_coeff = other.coefficients[i] if i < len(other.coefficients) else 0
            result_coeffs.append(self_coeff + other_coeff)
        
        return type(self)(*result_coeffs)
    
    @abstractmethod
    def evaluate(self, x):
        pass


def measure_time(func):
    def wrapper(*args, **kwargs):
        start_time = perf_counter()
        result = func(*args, **kwargs)
        end_time = perf_counter()
        elapsed = end_time - start_time
        
        print(f"   Function '{func.__name__}' took {elapsed:.6f} seconds.")
        return result
    return wrapper


class StandardPolynomialEvaluator(Polynomial):
    @measure_time
    def evaluate(self, x):
        try:
            iter(x)
            is_iterable = True
        except TypeError:
            is_iterable = False
            x = [x]
        
        results = []
        for x_val in x:
            result = 0
            for degree, coeff in enumerate(self.coefficients):
                result += coeff * (x_val ** degree)
            results.append(result)
        
        return results if is_iterable else results[0]


class HornerPolynomialEvaluator(Polynomial):
    @measure_time
    def evaluate(self, x):
        try:
            iter(x)
            is_iterable = True
        except TypeError:
            is_iterable = False
            x = [x]
        
        results = []
        for x_val in x:
            result = 0
            for coeff in reversed(self.coefficients):
                result = result * x_val + coeff
            results.append(result)
        
        return results if is_iterable else results[0]


if __name__ == "__main__":
    print("\n1. Testing __repr__:")
    poly1 = StandardPolynomialEvaluator(1, 2, 3)
    print(f"   poly1 = {poly1}")
    print(f"   Expected: 1 + 2x + 3x^2")
    
    poly2 = StandardPolynomialEvaluator(2, 3, -4)
    print(f"\n   poly2 = {poly2}")
    print(f"   Expected: 2 + 3x - 4x^2")
    
    print("\n2. Testing evaluation:")
    result = poly1.evaluate(2)
    print(f"   poly1(2) = {result}")
    print(f"   Expected: 17")
    
    print("\n3. Testing polynomial addition:")
    poly3 = StandardPolynomialEvaluator(1, 2)
    poly4 = StandardPolynomialEvaluator(3, 4)
    poly_sum = poly3 + poly4
    print(f"   (1 + 2x) + (3 + 4x) = {poly_sum}")
    print(f"   Expected: 4 + 6x")
    
    print("\n4. Testing standard vs Horner equivalence:")
    coeffs = [1, 2, 3, 4, 5]
    poly_std = StandardPolynomialEvaluator(*coeffs)
    poly_horner = HornerPolynomialEvaluator(*coeffs)
    
    test_point = 2.5
    result_std = poly_std.evaluate(test_point)
    result_horner = poly_horner.evaluate(test_point)
    
    print(f"   Standard at x={test_point}: {result_std}")
    print(f"   Horner   at x={test_point}: {result_horner}")

    print("\n5. Performance comparison on 10000 points:")
    
    coeffs = list(range(1, 21))
    poly_standard = StandardPolynomialEvaluator(*coeffs)
    poly_horner = HornerPolynomialEvaluator(*coeffs)
    
    x_values = np.linspace(0, 10, 10000).tolist()
    
    print(f"   Polynomial: {poly_standard}")
    print(f"   Evaluating at {len(x_values)} points in [0, 10]...")
    
    print("\n   Standard method:")
    results_standard = poly_standard.evaluate(x_values)
    
    print("   Horner's method:")
    results_horner = poly_horner.evaluate(x_values)
    
    max_abs_diff = max(abs(a - b) for a, b in zip(results_standard, results_horner))
    max_val = max(max(abs(x) for x in results_standard), max(abs(x) for x in results_horner))
    relative_error = max_abs_diff / max_val if max_val > 0 else max_abs_diff
    
    print(f"   Relative error: {relative_error:.2e}")
