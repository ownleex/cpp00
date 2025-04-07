/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:36:15 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/07 22:58:03 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    // Tentative d'instanciation de AAnimal - Commenté car c'est une classe abstraite et cela ne compilera pas
    // AAnimal *meta = new AAnimal();
    
    // La ligne suivante provoquerait une erreur de compilation:
    // error: cannot declare variable 'animal' to be of abstract type 'AAnimal'
    // AAnimal animal;
    
    // Utilisation des classes concrètes
    std::cout << "=== Utilisation des classes concrètes ===" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound();
    j->makeSound();
    
    delete j;
    delete i;
    
    // Test plus approfondi avec le Brain
    std::cout << "\n=== Test de la copie profonde avec Brain ===" << std::endl;
    Dog* dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "J'aime les os!");
    
    Dog* dog2 = new Dog(*dog1);
    std::cout << "Idée du chien 1: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idée du chien 2: " << dog2->getBrain()->getIdea(0) << std::endl;
    
    // Modifier l'idée du premier chien
    dog1->getBrain()->setIdea(0, "J'aime les balles!");
    
    std::cout << "Idée du chien 1 après modification: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idée du chien 2 après modification: " << dog2->getBrain()->getIdea(0) << std::endl;
    
    delete dog1;
    delete dog2;
    
    return 0;
}