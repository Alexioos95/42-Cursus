/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:24:51 by apayen            #+#    #+#             */
/*   Updated: 2023/03/27 10:51:03 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	errors(int argc, char c)
{
	if (write(1, "Error\n", 6) == -1)
		perror("Write : ");
	if (argc < 2)
		write(1, "Please select a map. (./so_long MAP_PATH)\n", 42);
	else if (argc > 2)
		write(1, "Please, select only one map.\n", 29);
	else if (c == 'V')
		write(1, "The map you tried to load doesn't exist.\n", 41);
	else if (c == 'M')
	{
		write(1, "An error of memory happened. ", 29);
		write(1, "(Are you sure all your files are valid ? ", 41);
		write(1, "Maybe your map is too big)\n", 27);
	}
	else if (c == '?')
		write(1, "The map you tried to load contain an unexpected character.\n",
			59);
	else if (c == '!')
		write(1, "A texture file could not be loaded.\n", 36);
}

void	errorsmapdesign(char c)
{
	if (write(1, "Error\n", 6) == -1)
		perror("Write : ");
	write(1, "The map you selected is not valid. ", 35);
	if (c == 'N')
		write(1, "(It must be a .ber file)\n", 25);
	else if (c == '1')
		write(1, "(It isn't closed)\n", 18);
	else if (c == 'W')
		write(1, "(It isn't a rectangle)\n", 23);
	else if (c == 'P')
		write(1, "(It must have only 1P, 1E and atleast 1C)\n", 42);
	else if (c == '0')
		write(1, "(A part of it is not accessible)\n", 33);
}

int	checkname(char *str)
{
	int		i;
	int		j;
	char	*name;

	name = "ber";
	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (i > 0 && str[i] != '.')
		i--;
	i++;
	while (name[j] != '\0' && str[i + j] == name[j])
		j++;
	if (name[j] != '\0' || str[i + j] != '\0')
		return (1);
	return (0);
}
