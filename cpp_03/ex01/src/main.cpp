/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:01:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 17:42:27 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    // Test de la classe ClapTrap
    std::cout << "\n=== Test de la classe ClapTrap ===\n" << std::endl;
    ClapTrap clap("CL4P-TP");
    
    // Affichage des valeurs initiales
    std::cout << "\n--- Valeurs initiales ---" << std::endl;
    std::cout << "ClapTrap " << clap.getName() << " stats:" << std::endl;
    std::cout << "Points de vie: " << clap.getHitPoints() << std::endl;
    std::cout << "Points d'énergie: " << clap.getEnergyPoints() << std::endl;
    std::cout << "Dégâts d'attaque: " << clap.getAttackDamage() << std::endl;
    
    // Test méthodes
    std::cout << "\n--- Test d'attaque ---" << std::endl;
    clap.attack("Bandit");

    std::cout << "\n--- Stats after attack ---" << std::endl;
    std::cout << "ClapTrap " << clap.getName() << " stats:" << std::endl;
    std::cout << "Hit Points: " << clap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << clap.getAttackDamage() << std::endl;

    std::cout << "\n--- Test de dégâts ---" << std::endl;
    clap.takeDamage(5);

    std::cout << "\n--- Stats after dammage ---" << std::endl;
    std::cout << "ClapTrap " << clap.getName() << " stats:" << std::endl;
    std::cout << "Hit Points: " << clap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << clap.getAttackDamage() << std::endl;
    
    std::cout << "\n--- Test de réparation ---" << std::endl;
    clap.beRepaired(3);

    std::cout << "\n--- Stats after repair ---" << std::endl;
    std::cout << "ClapTrap " << clap.getName() << " stats:" << std::endl;
    std::cout << "Hit Points: " << clap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << clap.getAttackDamage() << std::endl;
    
    // Test de la classe ScavTrap
    std::cout << "\n=== Test de la classe ScavTrap ===\n" << std::endl;
    ScavTrap scav("SC4V-TP");
    
    // Affichage des valeurs initiales
    std::cout << "\n--- Valeurs initiales ---" << std::endl;
    std::cout << "ScavTrap " << scav.getName() << " stats:" << std::endl;
    std::cout << "Points de vie: " << scav.getHitPoints() << std::endl;
    std::cout << "Points d'énergie: " << scav.getEnergyPoints() << std::endl;
    std::cout << "Dégâts d'attaque: " << scav.getAttackDamage() << std::endl;
    
    // Test des méthodes
    std::cout << "\n--- Test d'attaque ---" << std::endl;
    scav.attack("Psycho");

    std::cout << "\n--- Valeurs apres attaque ---" << std::endl;
    std::cout << "ScavTrap " << scav.getName() << " stats:" << std::endl;
    std::cout << "Points de vie: " << scav.getHitPoints() << std::endl;
    std::cout << "Points d'énergie: " << scav.getEnergyPoints() << std::endl;
    std::cout << "Dégâts d'attaque: " << scav.getAttackDamage() << std::endl;

    std::cout << "\n--- Test de dégâts ---" << std::endl;
    scav.takeDamage(30);

    std::cout << "\n--- Valeurs apres degat ---" << std::endl;
    std::cout << "ScavTrap " << scav.getName() << " stats:" << std::endl;
    std::cout << "Points de vie: " << scav.getHitPoints() << std::endl;
    std::cout << "Points d'énergie: " << scav.getEnergyPoints() << std::endl;
    std::cout << "Dégâts d'attaque: " << scav.getAttackDamage() << std::endl;
    
    std::cout << "\n--- Test de réparation ---" << std::endl;
    scav.beRepaired(15);
    
    std::cout << "\n--- Valeurs apres reparation ---" << std::endl;
    std::cout << "ScavTrap " << scav.getName() << " stats:" << std::endl;
    std::cout << "Points de vie: " << scav.getHitPoints() << std::endl;
    std::cout << "Points d'énergie: " << scav.getEnergyPoints() << std::endl;
    std::cout << "Dégâts d'attaque: " << scav.getAttackDamage() << std::endl;
    // Test méthode spécifique
    std::cout << "\n--- Test de guardGate ---" << std::endl;
    scav.guardGate();
    
    return 0;
}