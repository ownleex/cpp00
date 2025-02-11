#include "Phonebook.hpp"

PhoneBook::PhoneBook() : currentIndex(0) {
    // Initialisation du répertoire vide
}

void PhoneBook::addContact(const Contact& contact) {
    if (currentIndex < 8) {
        contacts[currentIndex] = contact;
        currentIndex++;
    } else {
        // Si le répertoire est plein, remplacer le plus ancien contact
        for (int i = 0; i < 7; i++) {
            contacts[i] = contacts[i + 1];
        }
        contacts[7] = contact;
    }
}

void PhoneBook::searchContact() const {
    displayContacts();

    int index;
    std::cout << "Enter index to display contact details: ";
    std::cin >> index;

    if (index >= 0 && index < currentIndex) {
        contacts[index].displayContactDetails();
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << '|'
              << std::setw(10) << "First Name" << '|'
              << std::setw(10) << "Last Name" << '|'
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < currentIndex; i++) {
        std::cout << std::setw(10) << i << '|';
        contacts[i].displayContactPreview();
    }
}