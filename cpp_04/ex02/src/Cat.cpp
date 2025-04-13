/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:34:42 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/13 02:15:22 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructeur par défaut appelé" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &src) : AAnimal(src) {
    std::cout << "Cat constructeur de copie appelé" << std::endl;
    this->brain = NULL;
    *this = src;
}

Cat::~Cat() {
    std::cout << "Cat destructeur appelé" << std::endl;
    delete this->brain;
}

Cat &Cat::operator=(const Cat &rhs) {
    std::cout << "Cat opérateur d'assignation appelé" << std::endl;
    if (this != &rhs) {
        this->type = rhs.type;
        
        if (this->brain) {
            delete this->brain;
        }
        
        this->brain = new Brain(*(rhs.brain));
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Miaou Miaou!" << std::endl;
}

Brain *Cat::getBrain() const {
    return this->brain;
}