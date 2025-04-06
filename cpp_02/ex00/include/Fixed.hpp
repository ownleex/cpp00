/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:34:06 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/06 19:04:30 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    // Constructeur par défaut
    Fixed(void);
    
    // Constructeur de recopie
    Fixed(const Fixed &src);
    
    // Opérateur d'affectation
    Fixed &operator=(const Fixed &rhs);
    
    // Destructeur
    ~Fixed(void);
    
    // Accesseurs
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif