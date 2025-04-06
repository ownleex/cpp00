/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:49:32 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/06 19:04:13 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    // Constructeurs et destructeur
    Fixed(void);
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed &src);
    ~Fixed(void);
    
    // Opérateur d'affectation
    Fixed &operator=(const Fixed &rhs);
    
    // Accesseurs
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    // Conversions
    float toFloat(void) const;
    int toInt(void) const;
    
    // Opérateurs de comparaison
    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;
    
    // Opérateurs arithmétiques
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;
    
    // Opérateurs d'incrémentation et de décrémentation
    Fixed &operator++();    // Pré-incrémentation
    Fixed operator++(int);  // Post-incrémentation
    Fixed &operator--();    // Pré-décrémentation
    Fixed operator--(int);  // Post-décrémentation
    
    // Fonctions membres statiques min et max
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

// Surcharge de l'opérateur d'insertion
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif