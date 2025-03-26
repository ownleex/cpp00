/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 02:10:38 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/03/26 18:30:09 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
				 const std::string& phoneNumber, const std::string& darkestSecret)
	: firstName(firstName), lastName(lastName), nickname(nickname),
	  phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

void Contact::displayContactPreview() const {
	std::cout << std::setw(10) << (firstName.size() > 10 ? firstName.substr(0, 9) + "." : firstName) << '|'
			  << std::setw(10) << (lastName.size() > 10 ? lastName.substr(0, 9) + "." : lastName) << '|'
			  << std::setw(10) << (nickname.size() > 10 ? nickname.substr(0, 9) + "." : nickname) << '|' << std::endl;
}

void Contact::displayContactDetails() const {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}