/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:01:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 18:51:36 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // Test de la classe FragTrap
    std::cout << "\n=== Test de la classe FragTrap ===\n" << std::endl;
    FragTrap frag("FR4G-TP");
    
    // Affichage des valeurs initiales
    std::cout << "\n--- Valeurs initiales ---" << std::endl;
    std::cout << "FragTrap " << frag.getName() << " stats:" << std::endl;
    std::cout << "Points de vie: " << frag.getHitPoints() << std::endl;
    std::cout << "Points d'énergie: " << frag.getEnergyPoints() << std::endl;
    std::cout << "Dégâts d'attaque: " << frag.getAttackDamage() << std::endl;
    
    // Test des méthodes
    std::cout << "\n--- Test d'attaque ---" << std::endl;
    frag.attack("Super Badass");

    std::cout << "\n--- Valeurs après attaque ---" << std::endl;
    std::cout << "FragTrap " << frag.getName() << " stats:" << std::endl;
    std::cout << "Points de vie: " << frag.getHitPoints() << std::endl;
    std::cout << "Points d'énergie: " << frag.getEnergyPoints() << std::endl;
    std::cout << "Dégâts d'attaque: " << frag.getAttackDamage() << std::endl;

    std::cout << "\n--- Test de dégâts ---" << std::endl;
    frag.takeDamage(50);

    std::cout << "\n--- Valeurs après dégâts ---" << std::endl;
    std::cout << "FragTrap " << frag.getName() << " stats:" << std::endl;
    std::cout << "Points de vie: " << frag.getHitPoints() << std::endl;
    std::cout << "Points d'énergie: " << frag.getEnergyPoints() << std::endl;
    std::cout << "Dégâts d'attaque: " << frag.getAttackDamage() << std::endl;
    
    std::cout << "\n--- Test de réparation ---" << std::endl;
    frag.beRepaired(25);
    
    std::cout << "\n--- Valeurs après réparation ---" << std::endl;
    std::cout << "FragTrap " << frag.getName() << " stats:" << std::endl;
    std::cout << "Points de vie: " << frag.getHitPoints() << std::endl;
    std::cout << "Points d'énergie: " << frag.getEnergyPoints() << std::endl;
    std::cout << "Dégâts d'attaque: " << frag.getAttackDamage() << std::endl;
    
    // Test de la méthode spécifique
    std::cout << "\n--- Test de highFivesGuys ---" << std::endl;
    frag.highFivesGuys();
    
    // Tests des limites pour FragTrap
    std::cout << "\n--- Tests des limites pour FragTrap ---" << std::endl;
    
    // Test de perte de tous les points de vie
    std::cout << "\nTest: perte de tous les points de vie" << std::endl;
    FragTrap frag2("FR4G-TP-2");
    frag2.takeDamage(200); // Plus que ses points de vie
    frag2.attack("cible"); // Ne devrait pas pouvoir attaquer
    frag2.highFivesGuys(); // Ne devrait pas pouvoir demander un high five
    
    // Test de perte de tous les points d'énergie
    std::cout << "\nTest: perte de tous les points d'énergie" << std::endl;
    FragTrap frag3("FR4G-TP-3");
    
    // Épuiser les points d'énergie (100 actions)
    for (int i = 0; i < 100; i++) {
        if (i % 20 == 0) // Afficher seulement tous les 20 pour éviter trop de sortie
            std::cout << "Action " << (i + 1) << ": ";
        frag3.attack("cible");
        if (i % 20 == 0)
            std::cout << std::endl;
    }
    
    // Essayer d'effectuer des actions sans énergie
    std::cout << "\nTentatives d'actions sans énergie:" << std::endl;
    frag3.attack("cible");
    frag3.beRepaired(5);
    frag3.highFivesGuys(); // Devrait pouvoir demander un high five même sans énergie
    
    std::cout << "\n--- Fin du programme ---" << std::endl;
    return 0;
}