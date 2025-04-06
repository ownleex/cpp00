/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:46:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/06 19:04:21 by ayarmaya         ###   ########.fr       */
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
    // Constructeur par défaut
    Fixed(void);
    
    // Constructeur avec un entier
    Fixed(const int n);
    
    // Constructeur avec un flottant
    Fixed(const float n);
    
    // Constructeur de recopie
    Fixed(const Fixed &src);
    
    // Opérateur d'affectation
    Fixed &operator=(const Fixed &rhs);
    
    // Destructeur
    ~Fixed(void);
    
    // Accesseurs
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    // Conversions
    float toFloat(void) const;
    int toInt(void) const;
};

// Surcharge de l'opérateur d'insertion
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif