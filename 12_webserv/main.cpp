/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <madaguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:05:30 by apayen            #+#    #+#             */
/*   Updated: 2024/03/27 11:31:13 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Manager.hpp"

int	main(int argc, char **argv)
{
	Manager	mng;

	try
	{
		if (argc == 1)
		{
			std::cout << "No configuration file was given in argument. Loading default configuration...\n" << std::endl;
			mng.defaultconfig();
		}
		else if (argc >= 2)
		{
			if (argc == 2)
				std::cout << "Loading configuration file...\n" << std::endl;
			else if (argc >= 3)
				std::cout << "Multiple configuration files were given in argument. Only the first one will be loaded. Loading..." << std::endl;
			mng.parse(argv[1]);
		}
		if (signal(SIGPIPE, SIG_IGN) == SIG_ERR || signal(SIGINT, sig_handler) == SIG_ERR || signal(SIGQUIT, sig_handler) == SIG_ERR)
		{
			std::cerr << "[!] Critical error in the program: signal: " << strerror(errno) << std::endl;
			std::cout << asciiart() << std::endl;
			return (1);
		}
		mng.run();
	}
	catch (const std::exception &e)
	{
		int			ret;
		std::string res;

		ret = 0;
		res = e.what();
		mng.shutdown(true);
		if (!res.empty() && res != "std::exception")
		{
			std::cerr << "[!] Critical error in the program: " << e.what();
			if (errno != 0)
				std::cerr << strerror(errno);
			std::cerr << "\n[-] All connection have been closed." << std::endl;
			ret = 1;
		}
		std::cout << asciiart() << std::endl;
		return (ret);
	}
	return (0);
}
