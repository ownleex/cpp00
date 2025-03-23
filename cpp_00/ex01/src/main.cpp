/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 02:10:57 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/03/23 17:22:13 by ayarmaya         ###   ########.fr       */
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
        std::getline(std::cin, input);
        
        bool onlySpaces = true;
        for (size_t i = 0; i < input.length(); i++) {
            if (!std::isspace(input[i])) {
                onlySpaces = false;
                break;
            }
        }
        
        if (input.empty() || onlySpaces) {
            std::cout << "This field cannot be empty or contain only spaces. Please enter again." << std::endl;
            continue;
        }
        
        isValid = true;
        
        if (fieldType == "name") {
            for (size_t i = 0; i < input.length(); i++) {
                if (!std::isalpha(input[i]) && !std::isspace(input[i])) {
                    std::cout << "This field can only contain letters and spaces. Please enter again." << std::endl;
                    isValid = false;
                    break;
                }
            }
        } 
        else if (fieldType == "alphanumeric") {
            for (size_t i = 0; i < input.length(); i++) {
                if (!std::isalnum(input[i]) && !std::isspace(input[i])) {
                    std::cout << "This field can only contain letters, numbers and spaces. Please enter again." << std::endl;
                    isValid = false;
                    break;
                }
            }
        } 
        else if (fieldType == "numeric") {
            for (size_t i = 0; i < input.length(); i++) {
                if (!std::isdigit(input[i]) && !std::isspace(input[i])) {
                    std::cout << "This field can only contain numbers and spaces. Please enter again." << std::endl;
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
		std::getline(std::cin, command);

		if (command.empty())
			continue;
			if (command == "ADD") {
				std::string firstName = getValidInput("First Name: ", "name");
				std::string lastName = getValidInput("Last Name: ", "name");
				std::string nickname = getValidInput("Nickname: ", "alphanumeric");
				std::string phoneNumber = getValidInput("Phone Number: ", "numeric");
				std::string darkestSecret = getValidInput("Darkest Secret: ", "alphanumeric");
			
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
