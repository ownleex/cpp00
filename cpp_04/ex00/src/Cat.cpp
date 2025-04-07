/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:34:42 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/07 22:34:43 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructeur par défaut appelé" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &src) : Animal(src) {
    std::cout << "Cat constructeur de copie appelé" << std::endl;
    *this = src;
}

Cat::~Cat() {
    std::cout << "Cat destructeur appelé" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Miaou Miaou!" << std::endl;
}