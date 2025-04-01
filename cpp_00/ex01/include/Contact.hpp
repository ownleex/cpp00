/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 02:10:34 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/01 18:09:05 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

	Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
			const std::string& phoneNumber, const std::string& darkestSecret);

	// Getters
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	// Setters
	void setFirstName(const std::string& name);
	void setLastName(const std::string& name);
	void setNickname(const std::string& nick);
	void setPhoneNumber(const std::string& number);
	void setDarkestSecret(const std::string& secret);

	void displayContactPreview() const;
	void displayContactDetails() const;
};

#endif