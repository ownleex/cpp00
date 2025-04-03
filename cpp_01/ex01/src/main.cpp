/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:03:04 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/03 18:11:07 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	std::cout << std::endl << "Test 1: Basic horde creation and announcement" << std::endl << std::endl;
	Zombie* horde = zombieHorde(5, "Horde Member");
	for (int i = 0; i < 5; i++) {
		horde[i].announce();
	}
	delete[] horde;

	std::cout << std::endl << "Test 2: Custom naming within a horde" << std::endl << std::endl;
	Zombie* customHorde = zombieHorde(5, "Default");
	customHorde[0].setName("Leader");
	customHorde[4].setName("LastOne");
	for (int i = 0; i < 5; i++)
		customHorde[i].announce();
	delete[] customHorde;

	std::cout << std::endl << "Test 3: Single zombie horde" << std::endl << std::endl;
	Zombie* singleZombie = zombieHorde(1, "Lonely");
	singleZombie[0].announce();
	delete[] singleZombie;

	std::cout << std::endl << "Test 4: Empty horde (N=0) handling" << std::endl << std::endl;
	Zombie* emptyHorde = zombieHorde(0, "Nobody");
	if (emptyHorde == NULL)
		std::cout << "Empty horde correctly returned NULL" << std::endl;
	else {
		delete[] emptyHorde;
		std::cout << "Empty horde did not return NULL" << std::endl;
	}

	std::cout << std::endl << "Test 5: Horde with empty name strings" << std::endl << std::endl;
	Zombie* anonymousHorde = zombieHorde(3, "");
	for (int i = 0; i < 3; i++)
		anonymousHorde[i].announce();
	delete[] anonymousHorde;

	std::cout << std::endl << "Test 6: Horde with special characters in names" << std::endl << std::endl;
	Zombie* specialHorde = zombieHorde(2, "Éç@#!?");
	for (int i = 0; i < 2; i++)
		specialHorde[i].announce();
	delete[] specialHorde;

	std::cout << std::endl << "Test 7: Large horde stress test (100 zombies)" << std::endl << std::endl;
	Zombie* largeHorde = zombieHorde(100, "Maxi");
	for (int i = 0; i < 100; i++)
		largeHorde[i].announce();
	delete[] largeHorde;

	std::cout << std::endl << "------------Finish------------" << std::endl << std::endl;
	return 0;
}
