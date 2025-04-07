/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:34:28 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/07 22:57:31 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
private:
    Brain *brain;

public:
    Cat();
    Cat(const Cat &src);
    virtual ~Cat();
    
    Cat &operator=(const Cat &rhs);
    
    virtual void makeSound() const;
    Brain *getBrain() const;
};

#endif