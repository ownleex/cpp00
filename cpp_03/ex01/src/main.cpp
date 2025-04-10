/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:01:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 19:32:44 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    // Test of the ScavTrap class
    std::cout << "\n=== Test of the ScavTrap class ===\n" << std::endl;
    ScavTrap scav("SC4V-TP");
    
    // Display of initial values
    std::cout << "\n--- Initial values ---" << std::endl;
    std::cout << "ScavTrap " << scav.getName() << " stats:" << std::endl;
    std::cout << "Hit points: " << scav.getHitPoints() << std::endl;
    std::cout << "Energy points: " << scav.getEnergyPoints() << std::endl;
    std::cout << "Attack damage: " << scav.getAttackDamage() << std::endl;
    
    // Test methods
    std::cout << "\n--- Attack test ---" << std::endl;
    scav.attack("Psycho");

    std::cout << "\n--- Values after attack ---" << std::endl;
    std::cout << "ScavTrap " << scav.getName() << " stats:" << std::endl;
    std::cout << "Hit points: " << scav.getHitPoints() << std::endl;
    std::cout << "Energy points: " << scav.getEnergyPoints() << std::endl;
    std::cout << "Attack damage: " << scav.getAttackDamage() << std::endl;

    std::cout << "\n--- Damage test ---" << std::endl;
    scav.takeDamage(30);

    std::cout << "\n--- Values after damage ---" << std::endl;
    std::cout << "ScavTrap " << scav.getName() << " stats:" << std::endl;
    std::cout << "Hit points: " << scav.getHitPoints() << std::endl;
    std::cout << "Energy points: " << scav.getEnergyPoints() << std::endl;
    std::cout << "Attack damage: " << scav.getAttackDamage() << std::endl;
    
    std::cout << "\n--- Repair test ---" << std::endl;
    scav.beRepaired(15);
    
    std::cout << "\n--- Values after repair ---" << std::endl;
    std::cout << "ScavTrap " << scav.getName() << " stats:" << std::endl;
    std::cout << "Hit points: " << scav.getHitPoints() << std::endl;
    std::cout << "Energy points: " << scav.getEnergyPoints() << std::endl;
    std::cout << "Attack damage: " << scav.getAttackDamage() << std::endl;
    // Test specific method
    std::cout << "\n--- guardGate test ---" << std::endl;
    scav.guardGate();

    // Additional tests for ScavTrap limits
    std::cout << "\n=== Tests of ScavTrap limits ===\n" << std::endl;
    
    // Test of loss of all hit points
    std::cout << "\nTest: loss of all hit points" << std::endl;
    ScavTrap scav2("SC4V-TP-2");
    scav2.takeDamage(200); // More than its hit points
    scav2.attack("target"); // Should not be able to attack
    
    // Test of loss of all energy points
    std::cout << "\nTest: loss of all energy points" << std::endl;
    ScavTrap scav3("SC4V-TP-3");
    
    // Exhaust energy points (50 actions)
    for (int i = 0; i < 50; i++) {
        scav3.attack("target");
    }
    
    // Attempts to perform actions without energy
    std::cout << "\nAttempts to perform actions without energy:" << std::endl;
    scav3.attack("target"); // Should not be able to attack
    scav3.beRepaired(5); // Should not be able to repair itself

    // Test of inheritance and construction/destruction order
    std::cout << "\n=== Inheritance test ===\n" << std::endl;
    {
        std::cout << "Creation of a ScavTrap (note the order of constructors):" << std::endl;
        ScavTrap scavTemp("SC4V-TEMP");
        std::cout << "End of block, destruction of scavTemp (note the order of destructors):" << std::endl;
    }
    
    std::cout << "\n=== End of test ===" << std::endl;
    std::cout << std::endl;
    
    return 0;
}