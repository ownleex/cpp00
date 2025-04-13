/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:33:39 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/13 02:15:17 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("") {
    std::cout << "AAnimal constructeur par défaut appelé" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) {
    std::cout << "AAnimal constructeur de copie appelé" << std::endl;
    *this = src;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructeur appelé" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

std::string AAnimal::getType() const {
    return this->type;
}

// Pas d'implémentation pour makeSound() car c'est une méthode pure virtuelle