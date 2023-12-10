/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:51:31 by apayen            #+#    #+#             */
/*   Updated: 2023/10/20 10:21:09 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	truncstr(std::string *f, std::string *l, std::string *n)
{
	if (f->length() > 10)
	{
		f->resize(9);
		f->push_back('.');
	}
	if (l->length() > 10)
	{
		l->resize(9);
		l->push_back('.');
	}
	if (n->length() > 10)
	{
		n->resize(9);
		n->push_back('.');
	}
}

void	addspaces(std::string str)
{
	int	i;

	i = 0;
	while (i < 10 - (int)str.length())
	{
		std::cout << " ";
		i++;
	}
}

void	clearterminal()
{
	std::string	cmd;

	if (!std::cin)
		return ;
	std::cout << "Do you want to clear the terminal? (y/n) ";
	std::cin >> cmd;
	if (cmd == "y" || cmd == "Y" || cmd == "YES" || cmd == "yes")
		std::system("clear");
}

int	main(void)
{
	PhoneBook 	pb;
	std::string	cmd;
	int			i;

	i = 0;
	std::system("clear");
	std::cout << "So, what are we doing? ";
	while (1)
	{
		if (!std::cin)
		{
			std::cerr << std::endl << "Error: stdin was closed" << std::endl;
			return (1);
		}
		std::cout << "ADD, SEARCH, or EXIT?" << std::endl;
		std::cout << "I want to: "; std::cin >> cmd;
		if (!std::cin)
		{
			std::cerr << std::endl << "Error: stdin was closed" << std::endl;
			return (1);
		}
		else if (cmd == "ADD")
			i = pb.addcontact(i);
		else if (cmd == "SEARCH")
		{
			if (i > 0)
				pb.searchcontact(i);
			else
				std::cout << "You have no contact saved yet... Go quickly add one!" << std::endl;
		}
		else if (cmd == "EXIT")
		{
			std::cout << "See you soon!" << std::endl;
			return (0);
		}
		else
			continue ;
		clearterminal();
	}
}
