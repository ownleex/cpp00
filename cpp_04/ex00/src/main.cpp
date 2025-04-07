/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:36:15 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/07 22:36:17 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    // Tests avec les classes Animal, Dog et Cat
    std::cout << "=== Tests avec polymorphisme correct ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // va afficher le son du chat
    j->makeSound(); // va afficher le son du chien
    meta->makeSound(); // va afficher le son de l'animal
    
    delete meta;
    delete j;
    delete i;
    
    // Tests avec les classes WrongAnimal et WrongCat
    std::cout << "\n=== Tests avec polymorphisme incorrect ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongCat->makeSound(); // va afficher le son du WrongAnimal, pas du WrongCat!
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;
    
    // Test direct avec WrongCat
    std::cout << "\n=== Test direct avec WrongCat ===" << std::endl;
    WrongCat directWrongCat;
    directWrongCat.makeSound(); // Cette fois, ça affichera le son du WrongCat
    
    return 0;
}