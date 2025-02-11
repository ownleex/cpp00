#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    // Constructeur par défaut
    Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

    Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
            const std::string& phoneNumber, const std::string& darkestSecret);

    void displayContactPreview() const;
    void displayContactDetails() const;
};

#endif // CONTACT_HPP