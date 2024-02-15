/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:06:21 by apayen            #+#    #+#             */
/*   Updated: 2023/12/02 07:52:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange	be;

	if (argc != 3)
	{
		std::cout << "Usage: ./btc data.csv <tosearch>.csv" << std::endl;
		return (1);
	}
	std::string		a1(argv[1]);
	std::string		a2(argv[2]);
	return (be.run(a1, a2));
}
