/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:02:05 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/03/27 00:15:18 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;
    
    std::cout << "Adresse mémoire de la variable string: " << &brain << std::endl;
    std::cout << "Adresse mémoire contenue dans stringPTR: " << stringPTR << std::endl;
    std::cout << "Adresse mémoire contenue dans stringREF: " << &stringREF << std::endl;
    
    std::cout << "Valeur de la string: " << brain << std::endl;
    std::cout << "Valeur pointée par stringPTR: " << *stringPTR << std::endl;
    std::cout << "Valeur pointée par stringREF: " << stringREF << std::endl;
    
    return 0;
}