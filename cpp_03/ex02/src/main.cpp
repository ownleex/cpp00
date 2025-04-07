/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:01:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/07 21:30:45 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // Test de la classe ClapTrap
    std::cout << "--- Test de la classe ClapTrap ---" << std::endl;
    ClapTrap clap("CL4P-TP");
    clap.attack("Bandit");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    // Test de la classe ScavTrap
    std::cout << "\n--- Test de la classe ScavTrap ---" << std::endl;
    ScavTrap scav("SC4V-TP");
    scav.attack("Psycho");
    scav.takeDamage(30);
    scav.beRepaired(15);
    scav.guardGate();
    
    // Test de la classe FragTrap
    std::cout << "\n--- Test de la classe FragTrap ---" << std::endl;
    FragTrap frag("FR4G-TP");
    
    // Affichage des statistiques de base
    std::cout << "FragTrap " << frag.getName() << " stats:" << std::endl;
    std::cout << "Hit Points: " << frag.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << frag.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << frag.getAttackDamage() << std::endl;
    
    // Test des méthodes héritées
    frag.attack("Super Badass");
    frag.takeDamage(50);
    frag.beRepaired(25);
    
    // Test de la méthode spécifique
    frag.highFivesGuys();
    
    // Test des limites pour FragTrap
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
    
    // Test de la chaîne de construction/destruction
    std::cout << "\n--- Test de la chaîne de construction/destruction ---" << std::endl;
    {
        std::cout << "Création d'un FragTrap dans un bloc séparé:" << std::endl;
        FragTrap fragLocal("LOCAL-FR4G");
        std::cout << "Fin du bloc, le FragTrap va être détruit." << std::endl;
    }
    
    std::cout << "\n--- Fin du programme ---" << std::endl;
    return 0;
}