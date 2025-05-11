/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:06:09 by apayen            #+#    #+#             */
/*   Updated: 2023/11/23 10:37:16 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <deque>
# include <list>

template<typename T, class container=std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		// constructors and destructor
		MutantStack(void);
		MutantStack(MutantStack const &rhs);
		~MutantStack(void);
		// overload
		MutantStack	&operator=(MutantStack const &rhs);
		// iterators
		typedef typename container::iterator iterator;
		iterator	begin(void) { return (this->c.begin()); }
		iterator	end(void) { return (this->c.end()); }
};

#endif
