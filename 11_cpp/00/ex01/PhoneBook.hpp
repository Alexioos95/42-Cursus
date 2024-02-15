/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:46:12 by apayen            #+#    #+#             */
/*   Updated: 2023/10/20 10:21:25 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		int		addcontact(int i);
		void	searchcontact(int i);
		void	displaytab(int i);
	private:
		Contact	_tab[8];
};

void	truncstr(std::string *f, std::string *l, std::string *n);
void	addspaces(std::string str);
void	clearterminal();

#endif
