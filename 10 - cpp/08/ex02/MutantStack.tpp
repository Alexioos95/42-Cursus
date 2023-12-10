/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:05:52 by apayen            #+#    #+#             */
/*   Updated: 2023/11/23 10:34:46 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template<typename T, typename U>
MutantStack<T, U>::MutantStack(void)
{
	std::cout << "Default constructor of MutantStack called" << std::endl;
}

template<typename T, typename U>
MutantStack<T, U>::MutantStack(MutantStack const &rhs)
{
	std::cout << "Copy constructor of MutantStack called" << std::endl;
	*this = rhs;
}

template<typename T, typename U>
MutantStack<T, U>::~MutantStack<T, U>(void)
{
	std::cout << "Destructor of MutantStack called" << std::endl;
}

// overload
template<typename T, typename U>
MutantStack<T, U>	&MutantStack<T, U>::operator=(MutantStack const &rhs)
{
	std::cout << "Default constructor of MutantStack called" << std::endl;
	static_cast<void>(rhs);
}

#endif
