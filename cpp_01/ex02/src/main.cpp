/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:02:05 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/03/27 00:23:27 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::cout << std::endl;

    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;
    
    std::cout << "Memory address of the string variable:   " << &brain << std::endl;
    std::cout << "Memory address held by stringPTR:        " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF:        " << &stringREF << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Value of the string:                     " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR:           " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF:           " << stringREF << std::endl;
    
    std::cout << std::endl;
    
    return 0;
}
