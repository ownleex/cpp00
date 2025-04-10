/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:18:18 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 19:14:37 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap(), _guardMode(false) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

// Constructor with name
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), _guardMode(false) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap constructor with name called for " << this->_name << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other), _guardMode(other._guardMode) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << this->_name << std::endl;
}

// Assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        this->_guardMode = other._guardMode;
    }
    return *this;
}

// Redefined attack method
void ScavTrap::attack(const std::string& target) {
    if (this->_energyPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " has no energy points left to attack!" << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " cannot attack because it has no hit points left!" << std::endl;
        return;
    }
    
    this->_energyPoints--;
    
    std::cout << "ScavTrap " << this->_name << " attacks " << target 
              << ", causing " << this->_attackDamage << " points of damage! Remaining energy points: " << this->_energyPoints << std::endl;    
}

// ScavTrap specific method
void ScavTrap::guardGate() {
    this->_guardMode = true;
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}