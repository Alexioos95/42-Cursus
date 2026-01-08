/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:49:37 by apayen            #+#    #+#             */
/*   Updated: 2023/10/19 13:25:29 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>

Contact::Contact(void)
{
	;
}

Contact::~Contact(void)
{
	;
}

// set
void	Contact::setIndex(int i)
{
	this->_index = i;
}

void	Contact::setFirstName(void)
{
	std::cout << "First name: ";
	std::cin >> this->_firstname;
}

void	Contact::setLastName(void)
{
	std::cout << "Last name: ";
	std::cin >> this->_lastname;
}

void	Contact::setNickName(void)
{
	std::cout << "Nick name: ";
	std::cin >> this->_nickname;
}

void	Contact::setPhone(void)
{
	std::cout << "Phone number: ";
	std::cin >> this->_phone;
}

void	Contact::setSecret(void)
{
	std::cout << "Darkest secret: ";
	std::cin >> this->_secret;
}

// get
int	Contact::getIndex(void) const
{
	return (this->_index);
}

std::string	Contact::getFirstName(void) const
{
	return (this->_firstname);
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastname);
}

std::string	Contact::getNickName(void) const
{
	return (this->_nickname);
}

std::string	Contact::getPhone(void) const
{
	return (this->_phone);
}

std::string	Contact::getSecret(void) const
{
	return (this->_secret);
}
