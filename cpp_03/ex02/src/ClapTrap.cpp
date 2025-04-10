/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:00:44 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 18:11:40 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructeur par défaut
ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap constructeur par défaut appelé" << std::endl;
}

// Constructeur avec nom
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap constructeur avec nom appelé pour " << this->_name << std::endl;
}

// Constructeur de copie
ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap constructeur de copie appelé" << std::endl;
    *this = other;
}

// Destructeur
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructeur appelé pour " << this->_name << std::endl;
}

// Opérateur d'affectation
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap opérateur d'affectation appelé" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// Méthode d'attaque
void ClapTrap::attack(const std::string& target) {
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " n'a plus de points d'énergie pour attaquer!" << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " ne peut pas attaquer car il n'a plus de points de vie!" << std::endl;
        return;
    }
    
    this->_energyPoints--;

    std::cout << "ClapTrap " << this->_name << " attaque " << target 
              << ", causant " << this->_attackDamage << " points of damage! Remaining energy points: " << this->_energyPoints << std::endl;
    
}

// Méthode pour subir des dégâts
void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " est déjà hors service!" << std::endl;
        return;
    }
    
    if (amount >= this->_hitPoints) {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " a pris " << amount 
                  << " points de dégâts et est maintenant hors service!" << std::endl;
    } else {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " a pris " << amount 
                  << " points de dégâts! Points de vie restants: " << this->_hitPoints << std::endl;
    }
}

// Méthode pour se réparer
void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " n'a plus de points d'énergie pour se réparer!" << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " ne peut pas se réparer car il est hors service!" << std::endl;
        return;
    }
    
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " se répare et récupère " << amount 
              << " points de vie! Points de vie actuels: " << this->_hitPoints << std::endl;
    this->_energyPoints--;
}

// Getters
std::string ClapTrap::getName() const {
    return this->_name;
}

unsigned int ClapTrap::getHitPoints() const {
    return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
    return this->_attackDamage;
}