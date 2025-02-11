#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int currentIndex;

public:
    PhoneBook();
    void addContact(const Contact& contact);
    void searchContact() const;
    void displayContacts() const;
};

#endif // PHONEBOOK_HPP