/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:01:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 19:34:40 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // Test of the FragTrap class
    std::cout << "\n=== FragTrap Class Test ===\n" << std::endl;
    FragTrap frag("FR4G-TP");
    
    // Display of initial values
    std::cout << "\n--- Initial Values ---" << std::endl;
    std::cout << "FragTrap " << frag.getName() << " stats:" << std::endl;
    std::cout << "Hit Points: " << frag.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << frag.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << frag.getAttackDamage() << std::endl;
    
    // Test methods
    std::cout << "\n--- Attack Test ---" << std::endl;
    frag.attack("Super Badass");

    std::cout << "\n--- Values after attack ---" << std::endl;
    std::cout << "FragTrap " << frag.getName() << " stats:" << std::endl;
    std::cout << "Hit Points: " << frag.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << frag.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << frag.getAttackDamage() << std::endl;

    std::cout << "\n--- Damage Test ---" << std::endl;
    frag.takeDamage(50);

    std::cout << "\n--- Values after damage ---" << std::endl;
    std::cout << "FragTrap " << frag.getName() << " stats:" << std::endl;
    std::cout << "Hit Points: " << frag.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << frag.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << frag.getAttackDamage() << std::endl;
    
    std::cout << "\n--- Repair Test ---" << std::endl;
    frag.beRepaired(25);
    
    std::cout << "\n--- Values after repair ---" << std::endl;
    std::cout << "FragTrap " << frag.getName() << " stats:" << std::endl;
    std::cout << "Hit Points: " << frag.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << frag.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << frag.getAttackDamage() << std::endl;
    
    // Test specific method
    std::cout << "\n--- highFivesGuys Test ---" << std::endl;
    frag.highFivesGuys();
    
    // Test limits for FragTrap
    std::cout << "\n--- FragTrap Limit Tests ---" << std::endl;
    
    // Test loss of all hit points
    std::cout << "\nTest: loss of all hit points" << std::endl;
    FragTrap frag2("FR4G-TP-2");
    frag2.takeDamage(200); // More than its hit points
    frag2.attack("target"); // Should not be able to attack
    
    // Test loss of all energy points
    std::cout << "\nTest: loss of all energy points" << std::endl;
    FragTrap frag3("FR4G-TP-3");
    
    // Exhaust energy points (100 actions)
    for (int i = 0; i < 100; i++) {
        frag3.attack("target");
    }
    
    // Try to perform actions without energy
    std::cout << "\nAttempts to perform actions without energy:" << std::endl;
    frag3.attack("target");
    frag3.beRepaired(5);
    
    std::cout << "\n--- End of program ---" << std::endl;
    return 0;
}