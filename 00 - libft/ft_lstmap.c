/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:02:12 by apayen            #+#    #+#             */
/*   Updated: 2022/11/21 13:35:51 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*new;
	int		i;
	int		len;

	if (!lst || !f || !del)
	{
		return (0);
	}
	i = 0;
	len = ft_lstsize(lst);
	newlist = NULL;
	while (i < len)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
			(*del)(lst);
		ft_lstadd_back(&newlist, new);
		lst = lst->next;
		i++;
	}
	return (newlist);
}
