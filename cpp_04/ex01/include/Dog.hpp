/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:33:54 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/13 02:12:38 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
private:
    Brain *brain;

public:
    Dog();
    Dog(const Dog &src);
    virtual ~Dog();
    
    Dog &operator=(const Dog &rhs);
    
    virtual void makeSound() const;
    Brain *getBrain() const;
};

#endif