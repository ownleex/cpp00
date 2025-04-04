/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:08:51 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/04 16:24:13 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    
    randomChump("Stack Zombie");
    
    delete heapZombie;
    
    return 0;
}
