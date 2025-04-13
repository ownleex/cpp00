/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:33:09 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/13 02:15:02 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

// Classe abstraite Animal (renommée en AAnimal)
class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal &src);
    virtual ~AAnimal();
    
    AAnimal &operator=(const AAnimal &rhs);
    
    std::string getType() const;
    virtual void makeSound() const = 0; // Méthode pure virtuelle
};

#endif