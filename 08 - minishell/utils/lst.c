/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:35:46 by eewu              #+#    #+#             */
/*   Updated: 2023/09/21 14:50:09 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../header.h"

// t_cmd	*ft_lstnew_cmd(char **str, char **redir, char **built)
// {
// 	struct s_cmd	*new;

// 	new = malloc(sizeof(struct s_lst));
// 	if (new == NULL)
// 		return (NULL);
// 	new->split = str;
// 	new->redirection = redir;
// 	new->builtin = built;
// 	new->next = NULL;
// 	new->back = NULL;
// 	return (new);
// }

// void	ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new)
// {
// 	t_cmd	*last;

// 	if (new == NULL)
// 	{
// 		printf("minishell: malloc: %s\n", strerror(errno));
// 		frees(new->ms, 1);
// 	}
// 	if ((*lst) == NULL)
// 	{
// 		(*lst) = new;
// 		return ;
// 	}
// 	last = *lst;
// 	while (last->next != NULL)
// 		last = last->next;
// 	last->next = new;
// 	new->back = last;
// }
