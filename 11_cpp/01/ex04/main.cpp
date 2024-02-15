/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:24:29 by marvin            #+#    #+#             */
/*   Updated: 2023/10/26 11:08:31 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int	replace(char *filename, std::string s1, std::string s2)
{
	std::fstream	in;
	std::fstream	out;
	char			*outname;
	std::string		line;
	std::string		tmp;
	size_t			find;
	size_t			index;

	in.open(filename, std::fstream::in);
	if (in.fail())
	{
		std::cout << "Error" << std::endl << filename << ": " << std::strerror(errno);
		return (1);
	}
	outname = std::strcat(filename, ".replace");
	out.open(outname, std::fstream::out);
	if (out.fail())
	{
		in.close();
		std::cout << "Error" << std::endl << outname << ": " << std::strerror(errno);
		return (1);
	}
	while (std::getline(in, line))
	{
		index = 0;
		while (1)
		{
			find = line.find(s1, index);
			if (find == std::string::npos)
				break;
			tmp = line.substr(find + s1.length());
			line.resize(find);
			line.append(s2);
			line.append(tmp);
			index = find + s2.length();
		}
		out << line;
		if (!in.eof())
			out << std::endl;
	}
	in.close();
	out.close();
	return (0);
}

int	main(int argc, char **argv)
{

	if (argc != 4)
	{
		std::cout << "Usage: ./test infile old_string new_string" << std::endl;
		return (1);
	}
	if (argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		std::cout << "Invalid argument" << std::endl;
		return (1);
	}
	std::string	a2(argv[2]);
	std::string	a3(argv[3]);
	return (replace(argv[1], a2, a3));
}
