/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 02:10:38 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/01 18:08:39 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

// Constructeur modifié pour utiliser les setters au lieu d'initialiser directement
Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
				 const std::string& phoneNumber, const std::string& darkestSecret) {
    // Utilisation des setters pour initialiser les attributs
    setFirstName(firstName);
    setLastName(lastName);
    setNickname(nickname);
    setPhoneNumber(phoneNumber);
    setDarkestSecret(darkestSecret);
}

// Implémentation des getters
std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

// Implémentation des setters
void Contact::setFirstName(const std::string& name) { firstName = name; }
void Contact::setLastName(const std::string& name) { lastName = name; }
void Contact::setNickname(const std::string& nick) { nickname = nick; }
void Contact::setPhoneNumber(const std::string& number) { phoneNumber = number; }
void Contact::setDarkestSecret(const std::string& secret) { darkestSecret = secret; }

void Contact::displayContactPreview() const {
	// Utilisation des getters au lieu d'accéder directement aux attributs
	std::cout << std::setw(10) << (getFirstName().size() > 10 ? getFirstName().substr(0, 9) + "." : getFirstName()) << '|'
			  << std::setw(10) << (getLastName().size() > 10 ? getLastName().substr(0, 9) + "." : getLastName()) << '|'
			  << std::setw(10) << (getNickname().size() > 10 ? getNickname().substr(0, 9) + "." : getNickname()) << '|' << std::endl;
}

void Contact::displayContactDetails() const {
	// Utilisation des getters au lieu d'accéder directement aux attributs
	std::cout << "First Name: " << getFirstName() << std::endl;
	std::cout << "Last Name: " << getLastName() << std::endl;
	std::cout << "Nickname: " << getNickname() << std::endl;
	std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << getDarkestSecret() << std::endl;
}
