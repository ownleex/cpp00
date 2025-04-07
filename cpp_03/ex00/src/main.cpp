/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:01:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/07 21:01:03 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    // Création d'un ClapTrap
    ClapTrap clap1("CL4P-TP");
    
    // Tests des méthodes
    clap1.attack("Skag");
    clap1.takeDamage(5);
    clap1.beRepaired(3);
    
    // Test des limites
    std::cout << "\n--- Tests des limites ---" << std::endl;
    
    // Création d'un second ClapTrap pour tester les limites
    ClapTrap clap2("FR4G-TP");
    
    // Test de perte de tous les points de vie
    std::cout << "\nTest: perte de tous les points de vie" << std::endl;
    clap2.takeDamage(15); // Plus que ses points de vie
    clap2.attack("cible"); // Ne devrait pas pouvoir attaquer
    clap2.beRepaired(5);   // Ne devrait pas pouvoir se réparer
    
    // Test de perte de tous les points d'énergie
    std::cout << "\nTest: perte de tous les points d'énergie" << std::endl;
    ClapTrap clap3("EN3R-TP");
    
    // Épuiser les points d'énergie (10 actions)
    for (int i = 0; i < 10; i++) {
        std::cout << "Action " << (i + 1) << ": ";
        clap3.attack("cible");
    }
    
    // Essayer d'effectuer des actions sans énergie
    std::cout << "\nTentatives d'actions sans énergie:" << std::endl;
    clap3.attack("cible");
    clap3.beRepaired(5);
    
    // Test du constructeur de copie et de l'opérateur d'affectation
    std::cout << "\n--- Tests de copie ---" << std::endl;
    ClapTrap clap4(clap1); // Constructeur de copie
    clap4.attack("ennemi");
    
    ClapTrap clap5;
    clap5 = clap1; // Opérateur d'affectation
    clap5.attack("autre ennemi");
    
    std::cout << "\n--- Fin du programme ---" << std::endl;
    return 0;
}