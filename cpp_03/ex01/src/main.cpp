/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:01:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/07 21:18:46 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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
    
    // Test des méthodes héritées
    scav.attack("Psycho");
    scav.takeDamage(30);
    scav.beRepaired(15);
    
    // Test de la méthode spécifique
    scav.guardGate();
    
    // Test des limites pour ScavTrap
    std::cout << "\n--- Tests des limites pour ScavTrap ---" << std::endl;
    
    // Test de perte de tous les points de vie
    std::cout << "\nTest: perte de tous les points de vie" << std::endl;
    ScavTrap scav2("SC4V-TP-2");
    scav2.takeDamage(200); // Plus que ses points de vie
    scav2.attack("cible"); // Ne devrait pas pouvoir attaquer
    scav2.guardGate();     // Devrait pouvoir activer le mode garde
    
    // Test de perte de tous les points d'énergie
    std::cout << "\nTest: perte de tous les points d'énergie" << std::endl;
    ScavTrap scav3("SC4V-TP-3");
    
    // Épuiser les points d'énergie (50 actions)
    for (int i = 0; i < 50; i++) {
        if (i % 10 == 0) // Afficher seulement tous les 10 pour éviter trop de sortie
            std::cout << "Action " << (i + 1) << ": ";
        scav3.attack("cible");
        if (i % 10 == 0)
            std::cout << std::endl;
    }
    
    // Essayer d'effectuer des actions sans énergie
    std::cout << "\nTentatives d'actions sans énergie:" << std::endl;
    scav3.attack("cible");
    scav3.beRepaired(5);
    scav3.guardGate(); // Devrait pouvoir activer le mode garde même sans énergie
    
    // Test de la chaîne de construction/destruction
    std::cout << "\n--- Test de la chaîne de construction/destruction ---" << std::endl;
    {
        std::cout << "Création d'un ScavTrap dans un bloc séparé:" << std::endl;
        ScavTrap scavLocal("LOCAL-SC4V");
        std::cout << "Fin du bloc, le ScavTrap va être détruit." << std::endl;
    }
    
    std::cout << "\n--- Fin du programme ---" << std::endl;
    return 0;
}