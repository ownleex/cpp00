/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:01:01 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 14:16:42 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    // Creating a ClapTrap
    ClapTrap clap1("CL4P-TP");
    
    // Testing the methods
    clap1.attack("Skag");
    clap1.takeDamage(5);
    clap1.beRepaired(3);
    
    // Testing limits
    std::cout << "\n--- Limits tests ---" << std::endl;
    
    // Creating a second ClapTrap to test limits
    ClapTrap clap2("FR4G-TP");
    
    // Test of losing all hit points
    std::cout << "\nTest: losing all hit points" << std::endl;
    clap2.takeDamage(15); // More than its hit points
    clap2.attack("target"); // Should not be able to attack
    clap2.beRepaired(5);   // Should not be able to repair
    
    // Test of losing all energy points
    std::cout << "\nTest: losing all energy points" << std::endl;
    ClapTrap clap3("EN3R-TP");
    
    // Depleting energy points (10 actions)
    for (int i = 0; i < 10; i++) {
        std::cout << "Action " << (i + 1) << ": ";
        clap3.attack("target");
    }
    
    // Trying to perform actions without energy
    std::cout << "\nAttempts to perform actions without energy:" << std::endl;
    clap3.attack("target");
    clap3.beRepaired(5);
    
    // Testing copy constructor and assignment operator
    std::cout << "\n--- Copy tests ---" << std::endl;
    ClapTrap clap4(clap1); // Copy constructor
    clap4.attack("enemy");
    
    ClapTrap clap5;
    clap5 = clap1; // Assignment operator
    clap5.attack("other enemy");
    
    std::cout << "\n--- End of program ---" << std::endl;
    return 0;
}