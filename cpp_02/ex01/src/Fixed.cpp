/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:46:22 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/06 19:04:25 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

// Constructeur par défaut
Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructeur avec un entier
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    // Conversion d'un entier en virgule fixe en décalant les bits
    _fixedPointValue = n << _fractionalBits;
}

// Constructeur avec un flottant
Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    // Conversion d'un flottant en virgule fixe en multipliant par 2^_fractionalBits et arrondissant
    _fixedPointValue = roundf(n * (1 << _fractionalBits));
}

// Constructeur de recopie
Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// Opérateur d'affectation
Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

// Destructeur
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// Accesseurs
int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// Conversions
float Fixed::toFloat(void) const {
    // Conversion de virgule fixe en flottant en divisant par 2^_fractionalBits
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    // Conversion de virgule fixe en entier en décalant à droite
    return _fixedPointValue >> _fractionalBits;
}

// Surcharge de l'opérateur d'insertion
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}