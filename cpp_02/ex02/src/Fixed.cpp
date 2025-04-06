/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:49:50 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/06 19:04:10 by ayarmaya         ###   ########.fr       */
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
    _fixedPointValue = n << _fractionalBits;
}

// Constructeur avec un flottant
Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(n * (1 << _fractionalBits));
}

// Constructeur de recopie
Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// Destructeur
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// Opérateur d'affectation
Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
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
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

// Surcharge de l'opérateur d'insertion
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

// Opérateurs de comparaison
bool Fixed::operator>(const Fixed &rhs) const {
    return this->_fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator<(const Fixed &rhs) const {
    return this->_fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator==(const Fixed &rhs) const {
    return this->_fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return this->_fixedPointValue != rhs._fixedPointValue;
}

// Opérateurs arithmétiques
Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue + rhs._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue - rhs._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    // Multiplication: convert back to float, multiply, then convert back to fixed point
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    // Division: convert back to float, divide, then convert back to fixed point
    if (rhs._fixedPointValue == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / rhs.toFloat());
}

// Opérateurs d'incrémentation et de décrémentation
Fixed &Fixed::operator++() {
    // Pré-incrémentation
    this->_fixedPointValue += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    // Post-incrémentation
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() {
    // Pré-décrémentation
    this->_fixedPointValue -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    // Post-décrémentation
    Fixed temp(*this);
    --(*this);
    return temp;
}

// Fonctions membres statiques min et max
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}