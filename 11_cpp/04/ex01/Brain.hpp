/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:36:10 by apayen            #+#    #+#             */
/*   Updated: 2023/11/03 12:57:09 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_HPP
# define Brain_HPP

# include <iostream>

class Brain
{
	public:
		// constructors and destructor
		Brain(void);
		Brain(Brain const &src);
		~Brain(void);
		// overload
		Brain		&operator=(Brain const &rhs);
		// setters and getters
		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i);

	private:
		std::string	_ideas[100];
};

#endif
