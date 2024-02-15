/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:46:09 by apayen            #+#    #+#             */
/*   Updated: 2023/10/19 15:22:26 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		// set
		void		setIndex(int i);
		void		setFirstName(void);
		void		setLastName(void);
		void		setNickName(void);
		void		setPhone(void);
		void		setSecret(void);
		// get
		int			getIndex(void) const;
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickName(void) const;
		std::string	getPhone(void) const;
		std::string	getSecret(void) const;

	private:
		int			_index;
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phone;
		std::string	_secret;
};

#endif
