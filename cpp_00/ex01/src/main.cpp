/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 02:10:57 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/03/26 21:24:26 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>
#include "Phonebook.hpp"

std::string getValidInput(const std::string& prompt, const std::string& fieldType) {
	std::string input;
	bool isValid = false;
	
	while (!isValid) {
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof()) {
				std::cout << std::endl << "EOF detected, exiting program..." << std::endl;
				return "";
			}
		}
		
		bool onlySpaces = true;
		bool containsTab = false;
		
		for (size_t i = 0; i < input.length(); i++) {
			if (!std::isspace(input[i])) {
				onlySpaces = false;
			}
			if (input[i] == '\t') {
				containsTab = true;
			}
		}
		
		if (input.empty() || onlySpaces) {
			std::cout << "This field cannot be empty or contain only spaces. Please enter again." << std::endl;
			continue;
		}
		
		if (containsTab) {
			std::cout << "This field cannot contain tab characters. Please enter again." << std::endl;
			continue;
		}
		
		isValid = true;
		if (fieldType == "numeric") {
			for (size_t i = 0; i < input.length(); i++) {
				if (std::isalpha(input[i])) {
					std::cout << "Phone number cannot contain letters. Please enter again." << std::endl;
					isValid = false;
					break;
				}
			}
		}
	}
	
	return input;
}

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command)) {
			std::cout << std::endl << "EOF detected, exiting program..." << std::endl;
			break;
		}

		if (command.empty())
			continue;
		if (command == "ADD") {
			std::string firstName = getValidInput("First Name: ", "any");
			if (firstName.empty()) break;
			std::string lastName = getValidInput("Last Name: ", "any");
			if (lastName.empty()) break;
			std::string nickname = getValidInput("Nickname: ", "any");
			if (nickname.empty()) break;
			std::string phoneNumber = getValidInput("Phone Number: ", "numeric");
			if (phoneNumber.empty()) break;
			std::string darkestSecret = getValidInput("Darkest Secret: ", "any");
			if (darkestSecret.empty()) break;
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