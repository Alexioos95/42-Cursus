/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:18:55 by marvin            #+#    #+#             */
/*   Updated: 2023/10/26 11:08:46 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	std::cout << "Print info 2 times:" << std::endl;
	harl.complain("INFO");
	harl.complain("INFO");
	std::cout << "Print debug 2 times:" << std::endl;
	harl.complain("DEBUG");
	harl.complain("DEBUG");
	std::cout << "Print error 2 times:" << std::endl;
	harl.complain("ERROR");
	harl.complain("ERROR");
	std::cout << "Print warning 2 times:" << std::endl;
	harl.complain("WARNING");
	harl.complain("WARNING");
	std::cout << "Send unknown str 2 times:" << std::endl;
	harl.complain("ABC");
	harl.complain("XYZ");
	return (0);
}
