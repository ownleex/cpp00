/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:49:02 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/11 15:26:53 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructeur par défaut appelé" << std::endl;
    for (int i = 0; i < 100; i++) {
        // Initialisation avec une chaîne générique sans utiliser de conversion
        this->ideas[i] = "Idée par défaut";
    }
}

Brain::Brain(const Brain &src) {
    std::cout << "Brain constructeur de copie appelé" << std::endl;
    *this = src;
}

Brain::~Brain() {
    std::cout << "Brain destructeur appelé" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs) {
    std::cout << "Brain opérateur d'assignation appelé" << std::endl;
    if (this != &rhs) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return this->ideas[index];
    }
    return "";
}

void Brain::setIdea(int index, std::string idea) {
    if (index >= 0 && index < 100) {
        this->ideas[index] = idea;
    }
}