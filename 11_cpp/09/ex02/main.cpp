/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:00:40 by apayen            #+#    #+#             */
/*   Updated: 2023/12/07 09:18:56 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	pm;

	if (argc == 1)
	{
		std::cout << "Usage: ./PmergeMe <sequence of positive int>" << std::endl;
		return (1);
	}
	return (pm.run(argc, argv));
}
