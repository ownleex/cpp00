/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:01:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 19:28:29 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    // Test of the ClapTrap class
    std::cout << "\n=== ClapTrap Class Test ===\n" << std::endl;
    ClapTrap clap("CL4P-TP");
    
    // Display initial values to verify initialization
    std::cout << "\n--- Initial Values ---" << std::endl;
    std::cout << "ClapTrap " << clap.getName() << " stats:" << std::endl;
    std::cout << "Hit Points: " << clap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << clap.getAttackDamage() << std::endl;
    
    // Test methods
    std::cout << "\n--- Attack Test ---" << std::endl;
    clap.attack("Bandit");

    std::cout << "\n--- Stats after attack ---" << std::endl;
    std::cout << "ClapTrap " << clap.getName() << " stats:" << std::endl;
    std::cout << "Hit Points: " << clap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << clap.getAttackDamage() << std::endl;
    
    std::cout << "\n--- Damage Test ---" << std::endl;
    clap.takeDamage(5);

    std::cout << "\n--- Stats after damage ---" << std::endl;
    std::cout << "ClapTrap " << clap.getName() << " stats:" << std::endl;
    std::cout << "Hit Points: " << clap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << clap.getAttackDamage() << std::endl;
    
    std::cout << "\n--- Repair Test ---" << std::endl;
    clap.beRepaired(3);

    std::cout << "\n--- Stats after repair ---" << std::endl;
    std::cout << "ClapTrap " << clap.getName() << " stats:" << std::endl;
    std::cout << "Hit Points: " << clap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << clap.getAttackDamage() << std::endl;

    // Additional tests for ClapTrap limits
    std::cout << "\n=== Tests of ClapTrap limits ===" << std::endl;
    
    // Test of loss of all hit points
    std::cout << "\nTest: loss of all hit points" << std::endl;
    ClapTrap clap2("CL4P-TP-2");
    clap2.takeDamage(20); // More than its hit points
    clap2.attack("target"); // Should not be able to attack
    clap2.beRepaired(5); // Should not be able to repair itself
    
    // Test of loss of all energy points
    std::cout << "\nTest: loss of all energy points" << std::endl;
    ClapTrap clap3("CL4P-TP-3");
    
    // Exhaust energy points (10 actions)
    for (int i = 0; i < 10; i++) {
        clap3.attack("target");
    }
    
    // Attempts to perform actions without energy
    std::cout << "\nAttempts to perform actions without energy:" << std::endl;
    clap3.attack("target"); // Should not be able to attack
    clap3.beRepaired(5); // Should not be able to repair itself
    
    std::cout << "\n=== End of Test ===\n" << std::endl;
    std::cout << std::endl;
    
    return 0;
}