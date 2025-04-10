/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:01:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 19:22:48 by ayarmaya         ###   ########.fr       */
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

    std::cout << "\n--- Final Stats ---" << std::endl;
    std::cout << "ClapTrap " << clap.getName() << " stats:" << std::endl;
    std::cout << "Hit Points: " << clap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << clap.getAttackDamage() << std::endl;

    // Tests supplémentaires pour les limites de ClapTrap
    std::cout << "\n=== Tests des limites de ClapTrap ===" << std::endl;
    
    // Test de perte de tous les points de vie
    std::cout << "\nTest: perte de tous les points de vie" << std::endl;
    ClapTrap clap2("CL4P-TP-2");
    clap2.takeDamage(20); // Plus que ses points de vie
    clap2.attack("cible"); // Ne devrait pas pouvoir attaquer
    clap2.beRepaired(5); // Ne devrait pas pouvoir se réparer
    
    // Test de perte de tous les points d'énergie
    std::cout << "\nTest: perte de tous les points d'énergie" << std::endl;
    ClapTrap clap3("CL4P-TP-3");
    
    // Épuiser les points d'énergie (10 actions)
    for (int i = 0; i < 10; i++) {
        clap3.attack("cible");
    }
    
    // Tentatives d'actions sans énergie
    std::cout << "\nTentatives d'actions sans énergie:" << std::endl;
    clap3.attack("cible"); // Ne devrait pas pouvoir attaquer
    clap3.beRepaired(5); // Ne devrait pas pouvoir se réparer
    
    std::cout << "\n=== End of Test ===\n" << std::endl;
    
    return 0;
}