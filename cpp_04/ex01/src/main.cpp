/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:36:15 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/13 01:51:52 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define NUM_ANIMALS 4

int main() {
    // Test des destructeurs et de la gestion de mémoire avec des objets simples
    std::cout << "\n=== Test avec des objets simples ===\n" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; // Ne devrait pas créer de fuites
    delete i;

    // Test du tableau d'animaux
    std::cout << "\n=== Test avec un tableau d'animaux ===\n" << std::endl;
    Animal* animals[NUM_ANIMALS];
    
    // Remplir le tableau (moitié chiens, moitié chats)
    for (int k = 0; k < NUM_ANIMALS; k++) {
        if (k < NUM_ANIMALS / 2) {
            animals[k] = new Dog();
        } else {
            animals[k] = new Cat();
        }
    }
    
    // Libérer la mémoire
    for (int k = 0; k < NUM_ANIMALS; k++) {
        delete animals[k];
    }

    
    
    // Test spécifique mentionné dans l'évaluation pour vérifier la copie profonde
    std::cout << "\n=== Test spécifique de la copie profonde (test de l'évaluation) ===\n" << std::endl;
    {
        Dog basic;
        basic.getBrain()->setIdea(0, "Idée originale de basic");
        
        // Afficher l'idée originale
        std::cout << "Idée de basic avant la copie: " << basic.getBrain()->getIdea(0) << std::endl;
        
        {
            // Création d'une copie dans un nouveau scope
            Dog tmp = basic;
            std::cout << "Idée de tmp après copie: " << tmp.getBrain()->getIdea(0) << std::endl;
            
            // Modifier l'idée de tmp
            tmp.getBrain()->setIdea(0, "Nouvelle idée de tmp");
            std::cout << "Idée de tmp après modification: " << tmp.getBrain()->getIdea(0) << std::endl;
            std::cout << "Idée de basic après modification de tmp: " << basic.getBrain()->getIdea(0) << std::endl;
            
            // À la fin de ce bloc, tmp est détruit
            std::cout << "Fin du bloc intérieur, tmp va être détruit" << std::endl;
        }
        
        // Vérifier que basic est toujours valide après la destruction de tmp
        std::cout << "Après destruction de tmp, basic est toujours valide." << std::endl;
        std::cout << "Idée de basic après destruction de tmp: " << basic.getBrain()->getIdea(0) << std::endl;
    }
    
    // Test de la copie profonde avec constructeur de copie
    std::cout << "\n=== Test de la copie profonde avec constructeur de copie ===\n" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "Je suis le chien original!");
    
    // Créer une copie et vérifier qu'elle a les mêmes idées
    Dog* copyDog = new Dog(*originalDog);
    std::cout << "Idée originale: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idée de la copie: " << copyDog->getBrain()->getIdea(0) << std::endl;
    
    // Modifier l'idée de l'original et vérifier que la copie n'est pas affectée
    originalDog->getBrain()->setIdea(0, "J'ai changé d'idée!");
    std::cout << "Idée originale après modification: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idée de la copie après modification: " << copyDog->getBrain()->getIdea(0) << std::endl;
    
    // Nettoyage
    delete originalDog;
    delete copyDog;


    
    // Test supplémentaire avec l'opérateur d'assignation
    std::cout << "\n=== Test avec l'opérateur d'assignation ===\n" << std::endl;
    Cat firstCat;
    firstCat.getBrain()->setIdea(0, "Je suis le premier chat!");
    
    Cat secondCat;
    secondCat = firstCat; // Utilisation de l'opérateur d'assignation
    
    std::cout << "Idée du premier chat: " << firstCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Idée du second chat: " << secondCat.getBrain()->getIdea(0) << std::endl;
    
    // Modifier l'idée du premier chat
    firstCat.getBrain()->setIdea(0, "J'ai maintenant une autre idée!");
    
    std::cout << "Idée du premier chat après modification: " << firstCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Idée du second chat après modification: " << secondCat.getBrain()->getIdea(0) << std::endl;
    
    return 0;
}