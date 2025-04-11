/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:02:58 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/11 21:20:43 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap() {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

// Constructor with name
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap constructor with name called for " << this->_name << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}

// Assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Redefined attack method
void FragTrap::attack(const std::string& target) {
    if (this->_energyPoints == 0) {
        std::cout << "FragTrap " << this->_name << " has no energy points left to attack!" << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << "FragTrap " << this->_name << " cannot attack because it has no hit points left!" << std::endl;
        return;
    }
    
    this->_energyPoints--;
    
    std::cout << "FragTrap " << this->_name << " attacks " << target 
              << ", FragTrap " << this->_attackDamage << " points of damage! Remaining energy points: " << this->_energyPoints << std::endl;    
}

// FragTrap specific method
void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->_name << " happily requests a high five from everyone! 🖐️" << std::endl;
}
