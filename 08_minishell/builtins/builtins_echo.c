/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:37:39 by apayen            #+#    #+#             */
/*   Updated: 2023/09/18 14:20:32 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// Regarde si la str envoyee est compose que de n apres le -n initial.
int	ft_echo_isfulln(char *str)
{
	int	i;

	i = 2;
	while (str[i] != '\0')
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

// Regarde si le tab contient des str avec -n.
int	ft_echo_option(char	**tab, int *n)
{
	int	i;

	i = 1;
	while (tab[i] != NULL && ft_strncmp(tab[i], "-n", 2) == 0)
	{
		if (ft_echo_isfulln(tab[i]) == 0)
			break ;
		*n = 1;
		i++;
	}
	return (i);
}

// Print les str.
// Si la 1ere str est "-n", ne print pas le \n a la fin du resultat.
int	ft_echo(char **tab)
{
	int	i;
	int	n;

	n = 0;
	i = ft_echo_option(tab, &n);
	while (tab[i] != NULL)
	{
		write(1, tab[i], (size_t)ft_strlen(tab[i]));
		if (errno == ENOSPC)
		{
			write(2, "-minishell: echo: write error: No space left on device\n" \
				, 55);
			return (1);
		}
		if (tab[i][0] != '\0' && tab[i + 1] != NULL)
			write(1, " ", 1);
		i++;
	}
	if (n == 0)
		write(1, "\n", 1);
	return (0);
}
