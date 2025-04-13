/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:35:21 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/13 02:12:05 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("") {
    std::cout << "WrongAnimal constructeur par défaut appelé" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
    std::cout << "WrongAnimal constructeur de copie appelé" << std::endl;
    *this = src;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructeur appelé" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::makeSound() const {
    std::cout << "* Son d'animal générique erroné *" << std::endl;
}