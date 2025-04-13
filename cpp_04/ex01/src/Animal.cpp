/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:33:39 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/13 02:13:04 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("") {
    std::cout << "Animal constructeur par défaut appelé" << std::endl;
}

Animal::Animal(const Animal &src) {
    std::cout << "Animal constructeur de copie appelé" << std::endl;
    *this = src;
}

Animal::~Animal() {
    std::cout << "Animal destructeur appelé" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::makeSound() const {
    std::cout << "* Son d'animal générique *" << std::endl;
}