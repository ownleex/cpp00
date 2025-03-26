/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:03:04 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/03/26 23:44:44 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int hordeSize = 5;
	Zombie* horde = zombieHorde(hordeSize, "Horde Member");
	
	for (int i = 0; i < hordeSize; i++) {
		horde[i].announce();
	}
	
	delete[] horde;
	
	return 0;
}