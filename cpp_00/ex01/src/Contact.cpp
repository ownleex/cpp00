/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 02:10:38 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/04 15:05:13 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
				 const std::string& phoneNumber, const std::string& darkestSecret) {
    setFirstName(firstName);
    setLastName(lastName);
    setNickname(nickname);
    setPhoneNumber(phoneNumber);
    setDarkestSecret(darkestSecret);
}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

void Contact::setFirstName(const std::string& fname) { firstName = fname; }
void Contact::setLastName(const std::string& lname) { lastName = lname; }
void Contact::setNickname(const std::string& nick) { nickname = nick; }
void Contact::setPhoneNumber(const std::string& number) { phoneNumber = number; }
void Contact::setDarkestSecret(const std::string& secret) { darkestSecret = secret; }

void Contact::displayContactPreview() const {
	std::cout << std::setw(10) << (getFirstName().size() > 10 ? getFirstName().substr(0, 9) + "." : getFirstName()) << '|'
			  << std::setw(10) << (getLastName().size() > 10 ? getLastName().substr(0, 9) + "." : getLastName()) << '|'
			  << std::setw(10) << (getNickname().size() > 10 ? getNickname().substr(0, 9) + "." : getNickname()) << '|' << std::endl;
}

void Contact::displayContactDetails() const {
	std::cout << std::endl;
	std::cout << "First Name:       " << getFirstName() << std::endl;
	std::cout << "Last Name:        " << getLastName() << std::endl;
	std::cout << "Nickname:         " << getNickname() << std::endl;
	std::cout << "Phone Number:     " << getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret:   " << getDarkestSecret() << std::endl << std::endl;
}