/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:00:44 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 14:59:46 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

// Constructor with name
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap constructor with name called for " << this->_name << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}

// Assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// Attack method
void ClapTrap::attack(const std::string& target) {
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " has no energy points left to attack!" << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " cannot attack because it has no hit points left!" << std::endl;
        return;
    }
    
    std::cout << "ClapTrap " << this->_name << " attacks " << target 
              << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}

// Method to take damage
void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " is already out of service!" << std::endl;
        return;
    }
    
    if (amount >= this->_hitPoints) {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " took " << amount 
                  << " points of damage and is now out of service!" << std::endl;
    } else {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " took " << amount 
                  << " points of damage! Remaining hit points: " << this->_hitPoints << std::endl;
    }
}

// Method to repair
void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " has no energy points left to repair itself!" << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " cannot repair itself because it is out of service!" << std::endl;
        return;
    }
    
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " repairs itself and recovers " << amount 
              << " hit points! Current hit points: " << this->_hitPoints << std::endl;
    this->_energyPoints--;
    this->_hitPoints += amount;
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