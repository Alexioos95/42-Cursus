/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:25:41 by apayen            #+#    #+#             */
/*   Updated: 2023/11/21 13:59:47 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	std::cout << "** Subject Test **" << std::endl;
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "** addNumber Test **" << std::endl;
	Span	sp1(3);

	try
	{
		sp1.addNumber(1);
		sp1.addNumber(15);
		sp1.addNumber(100);
		sp1.addNumber(400);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** Longest/Shortest Span Test **" << std::endl;
	std::cout << "Longest span is of: " << sp1.longestSpan() << std::endl;
	std::cout << "Shortest span is of: " << sp1.shortestSpan() << std::endl;

	Span	sp2(0);
	try
	{
		sp2.longestSpan();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** addRange Test **" << std::endl;
	unsigned int				i;
	std::vector<unsigned int>	v;
	Span						sp3(10);

	i = 0;
	while (i < 20)
	{
		v.push_back(i);
		i = i + 2;
	}
	sp3.addRange(v, v.begin(), v.end());
}
