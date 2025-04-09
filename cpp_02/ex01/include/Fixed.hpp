/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:46:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/09 17:51:05 by ayarmaya         ###   ########.fr       */
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
    // Default constructor
    Fixed(void);
    
    // Constructor with an integer
    Fixed(const int n);
    
    // Constructor with a float
    Fixed(const float n);
    
    // Copy constructor
    Fixed(const Fixed &src);
    
    // Copy Assignment operator
    Fixed &operator=(const Fixed &rhs);
    
    // Destructor
    ~Fixed(void);
    
    // Accessors
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    // Conversions
    float toFloat(void) const;
    int toInt(void) const;
};

// Overload of the insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif