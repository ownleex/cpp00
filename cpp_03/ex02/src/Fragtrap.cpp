/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:30:02 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/07 21:30:25 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructeur par défaut
FragTrap::FragTrap() : ClapTrap() {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap constructeur par défaut appelé" << std::endl;
}

// Constructeur avec nom
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap constructeur avec nom appelé pour " << this->_name << std::endl;
}

// Constructeur de copie
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap constructeur de copie appelé" << std::endl;
}

// Destructeur
FragTrap::~FragTrap() {
    std::cout << "FragTrap destructeur appelé pour " << this->_name << std::endl;
}

// Opérateur d'affectation
FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap opérateur d'affectation appelé" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Méthode spécifique à FragTrap
void FragTrap::highFivesGuys(void) {
    if (this->_hitPoints == 0) {
        std::cout << "FragTrap " << this->_name << " est hors service et ne peut pas demander un high five!" << std::endl;
        return;
    }
    
    std::cout << "FragTrap " << this->_name << " demande joyeusement un high five à tout le monde! 🖐️" << std::endl;
}