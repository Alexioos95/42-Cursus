/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:19:34 by eewu              #+#    #+#             */
/*   Updated: 2023/09/11 19:55:44 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_print_lexerlst(t_lexer *lst)
{
	int		i;
	t_lexer	*tmp;

	tmp = lst;
	printf("Taille du Lexer: %d\n", lst->len);
	while (tmp)
	{
		i = 0;
		printf("Word: %s\n", tmp->str);
		while (tmp->tab && tmp->tab[i])
			printf("Commande: %s\n", tmp->tab[i++]);
		printf("Token: %s\n", tmp->token.token);
		printf("file: %s\n", tmp->token.file);
		printf("Pipe: %s\n", tmp->token.pipe);
		printf("---------\n");
		tmp = tmp->next;
	}
}
