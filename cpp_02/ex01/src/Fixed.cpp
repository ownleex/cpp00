/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:46:22 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/09 17:50:53 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructor with an integer
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    // Conversion of an integer to fixed-point by shifting bits
    _fixedPointValue = n << _fractionalBits;
}

// Constructor with a float
Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    // Conversion of a float to fixed-point by multiplying by 2^_fractionalBits and rounding
    _fixedPointValue = roundf(n * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// Copy Assignment operator
Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// Accessors
int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// Conversions
float Fixed::toFloat(void) const {
    // Conversion from fixed-point to float by dividing by 2^_fractionalBits
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    // Conversion from fixed-point to integer by right-shifting
    return _fixedPointValue >> _fractionalBits;
}

// Overload of the insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}