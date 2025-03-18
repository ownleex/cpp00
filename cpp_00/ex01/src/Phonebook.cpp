/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 02:10:53 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/03/18 14:21:41 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <limits>

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {}

void PhoneBook::addContact(const Contact& contact) {
	if (contactCount < 8) {
		contacts[contactCount] = contact;
		contactCount++;
	} else {
		contacts[oldestContactIndex] = contact;
		oldestContactIndex = (oldestContactIndex + 1) % 8;
	}
}

void PhoneBook::searchContact() const {
	std::cout << std::setw(10) << "Index" << '|'
			  << std::setw(10) << "First Name" << '|'
			  << std::setw(10) << "Last Name" << '|'
			  << std::setw(10) << "Nickname" << '|' << std::endl;
	
	for (int i = 0; i < contactCount; i++) {
		std::cout << std::setw(10) << i << '|';
		contacts[i].displayContactPreview();
	}
	
	int index;
	while (true) {
		std::cout << "Enter index to display contact details: ";
		std::cin >> index;
		if (std::cin.fail() || index < 0 || index >= contactCount) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid index!" << std::endl;
		} else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
	contacts[index].displayContactDetails();
}