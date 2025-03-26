/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:08:41 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/03/26 22:42:33 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->name << " has been destroyed." << std::endl;
}

void Zombie::announce(void) const{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}