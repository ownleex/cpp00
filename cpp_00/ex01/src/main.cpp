/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 02:10:57 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/03/19 01:24:17 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Phonebook.hpp"

std::string getNonEmptyInput(const std::string& prompt) {
	std::string input;
	do {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty()) {
			std::cout << "This field cannot be empty. Please enter again." << std::endl;
		}
	} while (input.empty());
	return input;
}

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command.empty())
			continue;
		if (command == "ADD") {
			std::string firstName = getNonEmptyInput("First Name: ");
			std::string lastName = getNonEmptyInput("Last Name: ");
			std::string nickname = getNonEmptyInput("Nickname: ");
			std::string phoneNumber = getNonEmptyInput("Phone Number: ");
			std::string darkestSecret = getNonEmptyInput("Darkest Secret: ");

			phoneBook.addContact(Contact(firstName, lastName, nickname, phoneNumber, darkestSecret));
		}
		else if (command == "SEARCH") {
			phoneBook.searchContact();
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "BAD COMMAND" << std::endl;
	}
	return 0;
}
