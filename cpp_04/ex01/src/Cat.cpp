/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:34:42 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/07 22:51:44 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructeur par défaut appelé" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src) {
    std::cout << "Cat constructeur de copie appelé" << std::endl;
    this->brain = NULL; // Initialisation à NULL avant l'assignation
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
        
        // Suppression de l'ancien cerveau s'il existe
        if (this->brain) {
            delete this->brain;
        }
        
        // Copie profonde du cerveau
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