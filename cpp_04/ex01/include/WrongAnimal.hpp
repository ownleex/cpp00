/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:35:02 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/13 02:13:23 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &src);
    ~WrongAnimal();
    
    WrongAnimal &operator=(const WrongAnimal &rhs);
    
    std::string getType() const;
    void makeSound() const; // Pas de virtual ici, ce qui est délibéré
};

#endif