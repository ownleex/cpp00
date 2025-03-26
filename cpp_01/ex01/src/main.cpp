/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:03:04 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/03/26 23:08:01 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int hordeSize = 5;
    Zombie* horde = zombieHorde(hordeSize, "Horde Zombie");
    
    for (int i = 0; i < hordeSize; i++) {
        std::cout << "Zombie #" << i + 1 << " announces: ";
        horde[i].announce();
    }
    
    // Important: delete avec [] pour un tableau d'objets
    delete[] horde;
    
    return 0;
}