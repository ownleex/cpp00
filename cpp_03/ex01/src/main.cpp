/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:01:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 18:45:51 by ayarmaya         ###   ########.fr       */
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

    std::cout << std::endl;
    
    return 0;
}