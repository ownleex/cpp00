/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:06:26 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/04 21:11:50 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	Harl harl;
	
	std::cout << "Testing DEBUG level:" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	
	std::cout << "Testing INFO level:" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	
	std::cout << "Testing WARNING level:" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	
	std::cout << "Testing ERROR level:" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	
	std::cout << "Testing invalid level:" << std::endl;
	harl.complain("INVALID");
	
	return 0;
}