/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 02:10:57 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/02/12 02:11:03 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Phonebook.hpp"

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::cin >> command;

        if (command == "ADD") {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

            std::cout << "First Name: ";
            std::cin.ignore();
            std::getline(std::cin, firstName);

            std::cout << "Last Name: ";
            std::getline(std::cin, lastName);

            std::cout << "Nickname: ";
            std::getline(std::cin, nickname);

            std::cout << "Phone Number: ";
            std::getline(std::cin, phoneNumber);

            std::cout << "Darkest Secret: ";
            std::getline(std::cin, darkestSecret);

            Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            phoneBook.addContact(newContact);
        }
        else if (command == "SEARCH") {
            phoneBook.searchContact();
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}