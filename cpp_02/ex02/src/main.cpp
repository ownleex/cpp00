/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:49:57 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/11 21:36:58 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/*
int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max(a, b) << std::endl;
    
    return 0;
}
*/

void print_separator() {
    std::cout << "\n----------------------------------------\n" << std::endl;
}

int main(void) {
    std::cout << "TEST FROM SUBJECT" << std::endl;
    print_separator();

    // Constructor tests
    std::cout << "1. CONSTRUCTOR TESTS" << std::endl;
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    std::cout << "a (default): " << a << std::endl;
    std::cout << "b (int 10): " << b << std::endl;
    std::cout << "c (float 42.42): " << c << std::endl;
    std::cout << "d (copy of b): " << d << std::endl;

    print_separator();

    // Comparison operator tests
    std::cout << "2. COMPARISON OPERATOR TESTS" << std::endl;
    
    std::cout << "b > c : " << (b > c) << std::endl;
    std::cout << "b < c : " << (b < c) << std::endl;
    std::cout << "b >= d : " << (b >= d) << std::endl;
    std::cout << "b <= d : " << (b <= d) << std::endl;
    std::cout << "b == d : " << (b == d) << std::endl;
    std::cout << "b != c : " << (b != c) << std::endl;

    print_separator();

    // Arithmetic operator tests
    std::cout << "3. ARITHMETIC OPERATOR TESTS" << std::endl;
    
    Fixed e = b + c;
    Fixed f = c - b;
    Fixed g = b * c;
    Fixed h = c / b;
    
    std::cout << "b + c = " << e << " (" << b << " + " << c << ")" << std::endl;
    std::cout << "c - b = " << f << " (" << c << " - " << b << ")" << std::endl;
    std::cout << "b * c = " << g << " (" << b << " * " << c << ")" << std::endl;
    std::cout << "c / b = " << h << " (" << c << " / " << b << ")" << std::endl;

    print_separator();

    // Min and max functions tests
    std::cout << "5. STATIC MIN AND MAX FUNCTIONS TESTS" << std::endl;
    
    Fixed j(100);
    Fixed k(200);
    
    std::cout << "j: " << j << ", k: " << k << std::endl;
    
    // Test with non-constant references
    std::cout << "\nTest withnon-const:" << std::endl;
    std::cout << "min(j, k): " << Fixed::min(j, k) << std::endl;
    std::cout << "max(j, k): " << Fixed::max(j, k) << std::endl;
    
    // Test with constant references
    const Fixed l(300);
    const Fixed m(400);
    
    std::cout << "\nTest with const:" << std::endl;
    std::cout << "l: " << l << ", m: " << m << std::endl;
    std::cout << "min(l, m): " << Fixed::min(l, m) << std::endl;
    std::cout << "max(l, m): " << Fixed::max(l, m) << std::endl;

    // Mixed test (one const object, one non-const)
    std::cout << "\nTest with const and non-const:" << std::endl;
    std::cout << "min(j, l): " << Fixed::min(j, l) << std::endl;
    std::cout << "max(j, l): " << Fixed::max(j, l) << std::endl;

    print_separator();

    return 0;
}
