/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:34:14 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/07 22:34:16 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog constructeur par défaut appelé" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src) {
    std::cout << "Dog constructeur de copie appelé" << std::endl;
    *this = src;
}

Dog::~Dog() {
    std::cout << "Dog destructeur appelé" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Wouaf Wouaf!" << std::endl;
}