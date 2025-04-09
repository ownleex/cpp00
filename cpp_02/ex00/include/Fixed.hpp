/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:34:06 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/09 17:50:19 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    // Default constructor
    Fixed(void);
    
    // Copy constructor
    Fixed(const Fixed &src);
    
    // Copy Assignment operator
    Fixed &operator=(const Fixed &rhs);
    
    // Destructor
    ~Fixed(void);
    
    // Accessors
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif