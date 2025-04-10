/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:01:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 19:24:50 by ayarmaya         ###   ########.fr       */
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

    // Tests supplémentaires pour les limites de ScavTrap
    std::cout << "\n=== Tests des limites de ScavTrap ===\n" << std::endl;
    
    // Test de perte de tous les points de vie
    std::cout << "\nTest: perte de tous les points de vie" << std::endl;
    ScavTrap scav2("SC4V-TP-2");
    scav2.takeDamage(200); // Plus que ses points de vie
    scav2.attack("cible"); // Ne devrait pas pouvoir attaquer
    scav2.guardGate(); // Devrait pouvoir passer en mode gardien même sans points de vie?
    
    // Test de perte de tous les points d'énergie
    std::cout << "\nTest: perte de tous les points d'énergie" << std::endl;
    ScavTrap scav3("SC4V-TP-3");
    
    // Épuiser les points d'énergie (50 actions)
    for (int i = 0; i < 50; i++) {
        scav3.attack("cible");
    }
    
    // Tentatives d'actions sans énergie
    std::cout << "\nTentatives d'actions sans énergie:" << std::endl;
    scav3.attack("cible"); // Ne devrait pas pouvoir attaquer
    scav3.beRepaired(5); // Ne devrait pas pouvoir se réparer
    scav3.guardGate(); // Devrait pouvoir passer en mode gardien même sans énergie

    // Test d'héritage et ordre de construction/destruction
    std::cout << "\n=== Test d'héritage ===\n" << std::endl;
    {
        std::cout << "Création d'un ScavTrap (notez l'ordre des constructeurs):" << std::endl;
        ScavTrap scavTemp("SC4V-TEMP");
        std::cout << "Fin du bloc, destruction de scavTemp (notez l'ordre des destructeurs):" << std::endl;
    }
    
    std::cout << "\n=== Fin du test ===\n" << std::endl;
    
    std::cout << std::endl;
    
    return 0;
}