/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:35:18 by apayen            #+#    #+#             */
/*   Updated: 2023/09/18 14:41:48 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// Renvoir 0 si le char n'est pas valide.
int	ft_export_isvalid(char c, int i)
{
	if (i == 0 && c >= '0' && c <= '9')
		return (0);
	else if (c == '`' || c == '~' || c == '!' || c == '@' || c == '#' \
		|| c == '$' || c == '%' || c == '^' || c == '&' || c == '*' \
		|| c == '(' || c == ')' || c == '-' || c == '{' || c == '}' \
		|| c == '[' || c == ']' || c == '\\' || c == '|' || c == ';' \
		|| c == ':' || c == '"' || c == '\'' || c == '<' || c == '>' \
		|| c == ',' || c == '.' || c == '?' || c == '/')
		return (0);
	return (1);
}

// Cherche le char = pour avoir la valeur de la variable.
int	ft_export_searchequal(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0' && str[i] != '=')
		i++;
	if (str[i] == '\0' && i > 0)
		return (-1);
	if (i == 0)
		printf("minishell: export: `%s': not a valid identifier\n", str);
	return (i);
}

// Verifie que le nom de variable soit valide.
int	ft_export_parsing(char *str)
{
	int	i;
	int	equal;

	equal = ft_export_searchequal(str);
	if (equal < 1 || ft_strncmp(str, "_=", 2) == 0)
		return (0);
	i = equal;
	while (i > -1)
	{
		if (str[0] == '\0' || ft_export_isvalid(str[i], i) == 0)
		{
			printf("minishell: export: `%s': not a valid identifier\n", str);
			return (0);
		}
		i--;
	}
	return (equal);
}
