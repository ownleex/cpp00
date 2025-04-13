/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:36:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/13 02:15:34 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat constructeur par défaut appelé" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
    std::cout << "WrongCat constructeur de copie appelé" << std::endl;
    *this = src;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructeur appelé" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Miaou Miaou! (mais personne n'entendra ce son...)" << std::endl;
}