/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:00:12 by apayen            #+#    #+#             */
/*   Updated: 2023/12/10 18:51:45 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ** Constructors and Destructor ** //
PmergeMe::PmergeMe(void) { }

PmergeMe::PmergeMe(PmergeMe const &rhs) { *this = rhs; }

PmergeMe::~PmergeMe(void) { }

// ** Overload ** //
PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	this->_v = rhs._v;
	this->_dq = rhs._dq;
	this->debug = rhs.debug;
	return (*this);
}

// ** Exceptions ** //
const char	*PmergeMe::UnexpectedCharException::what(void) const throw()
{ return ("Error: Invalid character detected in the sequence"); }

const char	*PmergeMe::InvalidNumberException::what(void) const throw()
{ return ("Error: Invalid number detected in the sequence"); }

const char	*PmergeMe::DuplicateException::what(void) const throw()
{ return ("Error: A duplicate has been detected in the sequence"); }

const char	*PmergeMe::SortedException::what(void) const throw()
{ return ("Error: The sequence is already sorted"); }

// ** Functions ** //
template<typename T>
void	PmergeMe::insert(T &tab, int nb, int size)
{
	typename T::iterator	start;
	typename T::iterator	half;

	if (this->debug) // Print the number to insert
		std::cout << "  nb to insert: " << nb << std::endl;
	// If size of tab is 0, push back
	if (tab.size() == 0)
		tab.push_back(nb);
	// Else, if size of tab is 1, look for placement
	else if (tab.size() == 1)
	{
		if (nb > tab.front())
			tab.push_back(nb);
		else
			tab.insert(tab.begin(), nb);
	}
	// Else, binary insertion
	else
	{
		start = tab.begin();
		while (size > 0)
		{
			half = start + (size / 2);
			if (half >= tab.end())
				half = tab.end() - 1;
			if (nb > *half)
			{
				if (half + 1 == tab.end())
					tab.push_back(nb);
				else if (nb < *(half + 1))
					tab.insert(half + 1, nb);
				else if (half + 2 == tab.end() || nb < *(half + 2))
					tab.insert(half + 2, nb);
				else
				{
					start = half;
					continue ;
				}
				size = 0;
				nb = -1;
			}
			size = size / 2;
		}
		if (nb != -1)
			tab.insert(tab.begin(), nb);
	}
	if (this->debug) // Print sequence post insertion
	{
		start = tab.begin();
		std::cout << "    Sequence post insertion: ";
		while (start != tab.end())
		{
			std::cout << *start << ", ";
			start++;
		}
		std::cout << "(null)" << std::endl;
	}
}

template<typename T>
void	PmergeMe::swap(T b1, T e1, T b2, T e2)
{
	int	tmp;

	if (this->debug && b2 != e2 - 1) // Print beginning and ending of ranges
	{								 // Only if the range is larger than one
		std::cout << "  Ranges:" << std::endl;
		std::cout << "    From " << *b1 << " to " << *(e1 - 1) << std::endl;
		std::cout << "    From " << *b2 << " to " << *(e2 - 1) << std::endl;
	}
	// Swap a range of int
	while (b1 != e1 && b2 != e2)
	{
		if (this->debug) // Print the 2 values swapped
			std::cout << "  Swapping " << *b1 << " and " << *b2 << std::endl;
		tmp = *b2;
		*b2 = *b1;
		*b1 = tmp;
		b1++;
		b2++;
	}
}

std::deque<int>	PmergeMe::sort_dq(int loop, std::deque<int>::iterator i1, std::deque<int>::iterator i2)
{
	std::deque<int>::iterator					it;
	std::deque<int>::iterator					ite;
	std::deque<std::pair<int, int> >			pairs;
	std::deque<std::pair<int, int> >::iterator	pit;
	std::deque<int>								ret;
	std::deque<int>								tmp;
	int											lost;
	int											lostindex;
	int											index;
	int											search;

	it = i1;
	ite = i2;
	lost = -1;
	lostindex = 0;
	// If there is no comparison to do, stop recursion
	if (i2 >= this->_dq.end())
	{
		ret.push_back(*i1);
		return (ret);
	}
	// Compare numbers by pair
	while (ite < this->_dq.end())
	{
		// Swap sequences of values if needed
		if (*it > *ite)
			swap(it - loop + 1, it + 1, it + 1, ite + 1);
		// Make pair, and stock it in container
		std::pair<int, int> p = std::make_pair(*it, *ite);
		pairs.push_back(p);
		it = it + (loop * 2);
		ite = ite + (loop * 2);
		lostindex = lostindex + (loop * 2);
	}
	// Catch the lost number if the list is odd
	if (it < this->_dq.end() && it + loop >= this->_dq.end())
		lost = *it;
	// Recursion
	tmp = sort_dq(loop * 2, i1 + loop, i2 + (loop * 2));
	// Create sorted list with container returned by previous iteration
	ret = tmp;
	it = tmp.begin();
	pit = pairs.begin();
	index = 0;
	while (it != tmp.end())
	{
		search = *it;
		// Search the (high) number (returned by the previous iteration) in my pairs
		pit = pairs.begin();
		while (pit != pairs.end())
		{
			if ((pit)->second == search)
				break ;
			pit++;
		}
		// Binary insertion of the (little) number paired to the one we searched
		if (pit != pairs.end())
			insert(ret, (pit)->first, index);
		it++;
		index++;
	}
	// If there is a lost number, insert it
	if (lost > -1)
		insert(ret, lost, ret.size() - 1);
	// Return the container of the previous iteration, that we filled with our number
	return (ret);
}

std::vector<int>	PmergeMe::sort_v(int loop, std::vector<int>::iterator i1, std::vector<int>::iterator i2)
{
	std::vector<int>::iterator					it;
	std::vector<int>::iterator					ite;
	std::vector<std::pair<int, int> >			pairs;
	std::vector<std::pair<int, int> >::iterator	pit;
	std::vector<int>							ret;
	std::vector<int>							tmp;
	int											index;
	int											lost;
	int											search;

	it = i1;
	ite = i2;
	lost = -1;
	if (this->debug)
		std::cout << "/v\\ Dived down to loop " << loop / 2 << std::endl;
	// If there is no comparison to do, stop recursion
	if (i2 >= this->_v.end())
	{
		if (this->debug) // Print recursion's end, and number to return
			std::cout << "/!\\ Stopping recursion, and adding " << *i1 << " to return" << std::endl << std::endl;
		ret.push_back(*i1);
		return (ret);
	}
	// Compare numbers by pair
	while (ite < this->_v.end())
	{
		if (this->debug) // Print the 2 values compared
			std::cout << "Comparing " << *it << " and " << *ite << std::endl;
		// Swap sequences of values if needed
		if (*it > *ite)
		{
			swap(it - loop + 1, it + 1, it + 1, ite + 1);
			if (this->debug) // Print sequences post-swaps
			{
				std::cout << "    Sequence post swap: ";
				std::vector<int>::iterator	vit = this->_v.begin();
				while (vit != this->_v.end())
				{
					std::cout << *vit << ", ";
					vit++;
				}
				std::cout << "(null)" << std::endl;
			}
		}
		// Make pair, and stock it in container
		std::pair<int, int> p = std::make_pair(*it, *ite);
		pairs.push_back(p);
		it = it + (loop * 2);
		ite = ite + (loop * 2);
	}
	// Catch the lost number if the list is odd
	if (it < this->_v.end() && it + loop >= this->_v.end())
	{
		if (this->debug) // Print it
			std::cout << "/!\\ Lost: " << *it << std::endl;
		lost = *it;
	}
	if (this->debug) // Print sequence post actual recursion
	{
		std::vector<int>::iterator	iter = this->_v.begin();
		std::cout << "/*\\ Final at loop " << loop / 2 << ": ";
		while (iter != this->_v.end())
		{
			std::cout << *iter << ", ";
			iter++;
		}
		std::cout << "(null)" << std::endl << std::endl;
	}
	// Recursion
	tmp = sort_v(loop * 2, i1 + loop, i2 + (loop * 2));
	if (this->debug) // Print change of iteration
		std::cout << "/^\\ Climbed up to loop " << loop / 2 << std::endl;
	// Create sorted list with container returned by previous iteration
	ret = tmp;
	index = 0;
	it = tmp.begin();
	pit = pairs.begin();
	while (it != tmp.end())
	{
		search = *it;
		if (DEBUG) // Print the high number to search in pairs
			std::cout << "Searching for " << search << " in my pairs" << std::endl;
		// Search the (high) number (returned by the previous iteration) in my pairs
		pit = pairs.begin();
		while (pit != pairs.end())
		{
			if ((pit)->second == search)
				break ;
			pit++;
		}
		// Binary insertion of the (little) number paired to the one we searched
		if (pit != pairs.end())
			insert(ret, (pit)->first, index);
		it++;
		index++;
	}
	// If there is a lost number, insert it
	if (lost > -1)
	{
		if (this->debug)
			std::cout << "Inserting lost number" << std::endl;
		insert(ret, lost, ret.size() - 1);
	}
	if (this->debug) // For lisibility
		std::cout << std::endl;
	// Return the container of the previous iteration, that we filled with our number
	return (ret);
}

void	PmergeMe::parsing(int argc, char **argv)
{
	int							i;
	int							j;
	int							nbi;
	int							tmp;
	long long int				nbll;
	bool						sorted;
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	ite;

	i = 1;
	sorted = true;
	tmp = -1;
	while (i < argc)
	{
		// Catch not numbers arguments
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				throw (UnexpectedCharException());
				return ;
			}
			j++;
		}
		// Catch negatif and overflow values
		nbi = std::atoi(argv[i]);
		nbll = std::atoll(argv[i]);
		if (nbi != nbll || nbi < 0)
		{
			throw (InvalidNumberException());
			return ;
		}
		// Check if the sequence is already sorted
		if (nbi < tmp)
			sorted = false;
		tmp = nbi;
		// Add the number to the containers
		this->_v.push_back(nbi);
		this->_dq.push_back(nbi);
		i++;
	}
	// Check if there is a duplicate, or if the sequence is already sorted
	std::vector<int>	vtmp(this->_v);
	std::sort(vtmp.begin(), vtmp.end());
	ite = std::unique(vtmp.begin(), vtmp.end());
	if (ite != vtmp.end())
	{
		throw (DuplicateException());
		return ;
	}
	if (sorted == true)
	{
		throw (SortedException());
		return ;
	}
	this->debug = false;
}

int	PmergeMe::run(int argc, char **argv)
{
	try // Parsing
	{
		this->parsing(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	// Print the starting sequence
	std::vector<int>::iterator	it = this->_v.begin();
	std::cout << "Start with: ";
	while (it != this->_v.end())
	{
		std::cout << *it << ", ";
		it++;
	}
	std::cout << "(null)" << std::endl;
	// Time the parsing
	this->_clockparse = clock();
	// Sort the deque, and time it
	this->_dq = this->sort_dq(1, this->_dq.begin(), this->_dq.begin() + 1);
	this->_clockdeq = clock();
	// Activate debug, if asked
	if (DEBUG)
		this->debug = true;
	// Sort the vector, and time it
	this->_v = this->sort_v(1, this->_v.begin(), this->_v.begin() + 1);
	this->_clockvec = clock();
	// Print the final sequence
	std::vector<int>::iterator	ite = this->_v.begin();
	std::cout << "Final sequence: ";
	while (ite != this->_v.end())
	{
		std::cout << *ite << ", ";
		ite++;
	}
	std::cout << "(null)" << std::endl;
	// Print the time used to sort the containers
	if (!DEBUG)
	{
		float	timeparse = static_cast<float>(this->_clockparse);
		float	timedeq = static_cast<float>(this->_clockdeq);
		float	timevec = static_cast<float>(this->_clockvec);
		std::cout << "Time to sort deque (parsing included): " << ((timedeq / CLOCKS_PER_SEC) * 1000) << "ms" << std::endl;
		std::cout << "Time to sort vector (parsing included): " << ((((timeparse + timevec) - timedeq) / CLOCKS_PER_SEC) * 1000) << "ms" << std::endl;
	}
	return (0);
}
