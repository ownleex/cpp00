/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 02:10:57 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/04 23:25:51 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>
#include "Phonebook.hpp"

std::string getValidInput(const std::string& prompt) {
	std::string input;
	
	while (true) {
		std::cout << prompt;
		if (!std::getline(std::cin, input) && std::cin.eof()) {
			std::cout << std::endl << "EOF detected, exiting program..." << std::endl;
			return "";
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
		
		break;
	}
	
	return input;
}

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command)) {
			if (std::cin.eof()) {
				std::cout << std::endl << "EOF detected, exiting program..." << std::endl;
			}
			break;
		}

		if (command.empty())
			continue;
		if (command == "ADD") {
			std::string firstName = getValidInput("First Name: ");
			if (firstName.empty()) break;
			std::string lastName = getValidInput("Last Name: ");
			if (lastName.empty()) break;
			std::string nickname = getValidInput("Nickname: ");
			if (nickname.empty()) break;
			std::string phoneNumber = getValidInput("Phone Number: ");
			if (phoneNumber.empty()) break;
			std::string darkestSecret = getValidInput("Darkest Secret: ");
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