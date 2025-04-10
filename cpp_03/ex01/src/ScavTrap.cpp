/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:18:18 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 17:29:02 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructeur par défaut
ScavTrap::ScavTrap() : ClapTrap(), _guardMode(false) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap constructeur par défaut appelé" << std::endl;
}

// Constructeur avec nom
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), _guardMode(false) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap constructeur avec nom appelé pour " << this->_name << std::endl;
}

// Constructeur de copie
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other), _guardMode(other._guardMode) {
    std::cout << "ScavTrap constructeur de copie appelé" << std::endl;
}

// Destructeur
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructeur appelé pour " << this->_name << std::endl;
}

// Opérateur d'affectation
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap opérateur d'affectation appelé" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        this->_guardMode = other._guardMode;
    }
    return *this;
}

// Méthode d'attaque redéfinie
void ScavTrap::attack(const std::string& target) {
    if (this->_energyPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " n'a plus de points d'énergie pour attaquer!" << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " ne peut pas attaquer car il n'a plus de points de vie!" << std::endl;
        return;
    }
    
    this->_energyPoints--;
    
    std::cout << "ScavTrap " << this->_name << " attaque " << target 
              << ", causant " << this->_attackDamage << " points de dégâts! Points d'énergie restant: " << this->_energyPoints << std::endl;
}

// Méthode spécifique à ScavTrap
void ScavTrap::guardGate() {
    this->_guardMode = true;
    std::cout << "ScavTrap " << this->_name << " est maintenant en mode Gate keeper!" << std::endl;
}