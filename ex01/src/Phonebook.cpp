/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 02:10:53 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/04 23:41:43 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {}

void PhoneBook::addContact(const Contact& contact) {
	if (contactCount < 8) {
		contacts_array[contactCount] = contact;
		contactCount++;
	}
	else {
		contacts_array[oldestContactIndex] = contact;
		oldestContactIndex = (oldestContactIndex + 1) % 8;
	}
}

void PhoneBook::searchContact() const {
	if (contactCount == 0) {
		std::cout << "The phonebook is empty!" << std::endl;
		return;
	}
	
	std::cout << "+----------+----------+----------+----------+" << std::endl << '|' 
			  << std::setw(10) << "Index" << '|'
			  << std::setw(10) << "First Name" << '|'
			  << std::setw(10) << "Last Name" << '|'
			  << std::setw(10) << "Nickname" << '|' << std::endl
			  << "+----------+----------+----------+----------+" << std::endl;	
	for (int i = 0; i < contactCount; i++) {
		std::cout << '|' << std::setw(10) << i << '|';
		contacts_array[i].displayContactPreview();
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	
	int index;
	
	while (true) {
		std::cout << "Enter index to display contact details or -1 to returning to main menu: ";
		
		if (!(std::cin >> index)) {
			if (std::cin.eof()) {
				std::cout << std::endl << "EOF detected, exiting program..." << std::endl;
				exit(0);
			}
			
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error input, please enter a number!" << std::endl;
			continue;
		}
		
		if (index == -1) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Returning to main menu" << std::endl;
			return;
		}
		
		if (index < 0 || index >= contactCount) {
			std::cout << "Invalid index!" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	}
	
	contacts_array[index].displayContactDetails();
}
