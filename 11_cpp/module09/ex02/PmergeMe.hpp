/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:00:23 by apayen            #+#    #+#             */
/*   Updated: 2023/12/07 13:10:38 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# ifndef DEBUG
#  define DEBUG false
# endif

# include <exception>
# include <algorithm>
# include <iostream>
# include <cstdlib>
# include <utility>
# include <vector>
# include <deque>
# include <ctime>

class PmergeMe
{
	public:
	// ** Constructors and Destructor ** //
		PmergeMe(void);
		PmergeMe(PmergeMe const &rhs);
		~PmergeMe(void);
	// ** Overload ** //
		PmergeMe	&operator=(PmergeMe const &rhs);
	// ** Exceptions ** //
		class UnexpectedCharException : public std::exception
			{ public: const char *what(void) const throw(); };
		class InvalidNumberException : public std::exception
			{ public: const char *what(void) const throw(); };
		class DuplicateException : public std::exception
			{ public: const char *what(void) const throw(); };
		class SortedException : public std::exception
			{ public: const char *what(void) const throw(); };
	// ** Functions ** //
		int					run(int argc, char **argv);

	private:
	// ** Functions ** //
		template<typename T>
		void				insert(T &tab, int nb, int size);
		template<typename T>
		void				swap(T b1, T e1, T b2, T e2);
		std::deque<int>		sort_dq(int loop, std::deque<int>::iterator i1, std::deque<int>::iterator i2);
		std::vector<int>	sort_v(int loop, std::vector<int>::iterator i1, std::vector<int>::iterator i2);
		void				parsing(int argc, char **argv);
	// ** Attributes ** //
		std::vector<int>	_v;
		std::deque<int>		_dq;
		clock_t				_clockparse;
		clock_t				_clockvec;
		clock_t				_clockdeq;
		bool				debug;
};

#endif
