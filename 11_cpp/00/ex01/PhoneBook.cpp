/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:49:34 by apayen            #+#    #+#             */
/*   Updated: 2023/10/20 11:39:25 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	;
}

PhoneBook::~PhoneBook(void)
{
	;
}

void	PhoneBook::displaytab(int i)
{
	int			j;
	std::string	fname;
	std::string	lname;
	std::string	nname;

	j = 0;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	while (j < i)
	{
		fname = this->_tab[j].getFirstName();
		lname = this->_tab[j].getLastName();
		nname = this->_tab[j].getNickName();
		truncstr(&fname, &lname, &nname);
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "|";
		std::cout << "         " << this->_tab[j].getIndex() << "|";
		addspaces(fname);
		std::cout << fname << "|";
		addspaces(lname);
		std::cout << lname << "|";
		addspaces(nname);
		std::cout << nname << "|" << std::endl;
		j++;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void	PhoneBook::searchcontact(int i)
{
	int	index;

	index = -1;
	this->displaytab(i);
	while (index < 0 || index >= i)
	{
		if (!std::cin)
			return ;
		std::cout << "Select the index of a contact: ";
		std::cin >> index;
		if ((index < 0 || index > 8 || index >= i) && std::cin)
			std::cout << "Invalid choice!" << std::endl;
		if (!std::cin)
			return ;
	}
	std::cout << "Index: " << this->_tab[index].getIndex() << std::endl;
	std::cout << "First name: " << this->_tab[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->_tab[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_tab[index].getNickName() << std::endl;
	std::cout << "Phone number: " << this->_tab[index].getPhone() << std::endl;
	std::cout << "Darkest secret: " << this->_tab[index].getSecret() << std::endl;
}

int	PhoneBook::addcontact(int i)
{
	int	j;

	j = 0;
	if (i == 8)
	{
		while (j < 7)
		{
			this->_tab[j] = this->_tab[j + 1];
			this->_tab[j].setIndex(j);
			j++;
		}
		i--;
	}
	this->_tab[i].setIndex(i);
	if (!std::cin)
		return (i + 1);
	this->_tab[i].setFirstName();
	if (!std::cin)
		return (i + 1);
	this->_tab[i].setLastName();
	if (!std::cin)
		return (i + 1);
	this->_tab[i].setNickName();
	if (!std::cin)
		return (i + 1);
	this->_tab[i].setPhone();
	if (!std::cin)
		return (i + 1);
	this->_tab[i].setSecret();
	if (!std::cin)
		return (i + 1);
	std::cout << "Successfully added new contact!" << std::endl;
	if (j > 0)
		std::cout << "But you lost a previous one..." << std::endl;
	return (i + 1);
}
