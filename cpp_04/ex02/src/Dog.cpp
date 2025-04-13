/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:34:14 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/13 02:15:25 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog constructeur par défaut appelé" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &src) : AAnimal(src) {
    std::cout << "Dog constructeur de copie appelé" << std::endl;
    this->brain = NULL;
    *this = src;
}

Dog::~Dog() {
    std::cout << "Dog destructeur appelé" << std::endl;
    delete this->brain;
}

Dog &Dog::operator=(const Dog &rhs) {
    std::cout << "Dog opérateur d'assignation appelé" << std::endl;
    if (this != &rhs) {
        this->type = rhs.type;
        
        if (this->brain) {
            delete this->brain;
        }
        
        this->brain = new Brain(*(rhs.brain));
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Wouaf Wouaf!" << std::endl;
}

Brain *Dog::getBrain() const {
    return this->brain;
}