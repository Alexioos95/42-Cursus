/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <madaguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:35:24 by apayen            #+#    #+#             */
/*   Updated: 2024/03/26 13:50:28 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Manager.hpp"

bool g_sigint = false;

void	sig_handler(int sig)
{
	if (sig == SIGINT)
		g_sigint = true;
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = static_cast<unsigned char *>(s);
	while (i < n)
	{
		s2[i] = c;
		i++;
	}
	return (s);
}

std::string	itoa(int nbi)
{
	std::string nb;

	if (nbi == 0)
		return ("0");
	while (nbi > 0)
	{
		nb.insert(nb.begin(), (nbi % 10) + '0');
		nbi = nbi / 10;
	}
	return (nb);
}

int	autoindex(const char *directory_name, std::string root, std::string &res) {
	DIR* directory = opendir(directory_name);
	std::string fullPath;
	std::string	relative = "/Servers/" + root;
	size_t len = relative.length();
	relative = std::string(directory_name).substr(len, strlen(directory_name) - len);
	res = "<!DOCTYPE html>\n<html lang=\"fr\">\n\t<head>\n\t<meta charset=\"UTF-8\">\n\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n\t<title>Index des fichiers</title>\n\t</head>\n<body>\n\t<body>\n\t\t<ul>\n</html>";
	struct dirent *entry;
	if (directory == NULL) {
		std::cerr << "error open" << std::endl;
		return (0);
	}
	while ((entry = readdir(directory)) != NULL)
	{
		if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
		{
			fullPath = std::string(directory_name) + "/" + entry->d_name;
			std::string	en(entry->d_name);
			struct stat fileStat;
			if (stat(fullPath.c_str(), &fileStat) != -1)
			{
				if (S_ISDIR(fileStat.st_mode))
					res+="\t\t\t<li><a href=\"" + relative + "/" + en + "\"> " + en + " </a></li>\n";
				else
					res+="\t\t\t<li><a href=\"" + relative + "/" + en + "\"> " + en + " </a></li>\n";
			}
		}
	}
	res += "\t\t</ul>\n\t</body>";
	closedir(directory);
	return (1);
}

std::string	asciiart(void)
{
	std::string	ret;

	ret = ret + "\n[!] The program has been closed.\n";
	ret = ret + "  _ _____ _ _     __  _ _____   _______   _____ _ __ __ ___ _ \n";
	ret = ret + " `.\\_   _| | |   |  \\| | __\\ \\_/ /_   _| |_   _| |  V  | __/ \\\n";
	ret = ret + "     | | | | |_  | | ' | _| > , <  | |     | | | | \\_/ | _|\\_/\n";
	ret = ret + "     |_| |_|___| |_|\\__|___/_/ \\_\\ |_|     |_| |_|_| |_|___(_)\n";
	return (ret);
}

void	printvector(std::vector<char> v, int minus)
{
	std::vector<char>::iterator	it;
	std::string					tmp;
	int							i;
	int							j;

	it = v.begin();
	i = 0;
	j = v.size() - minus;
	while (i < j)
	{
		tmp = *it + '\0';
		std::cout << tmp;
		i++;
		it++;
	}
	std::cout << std::endl;
}
