/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:35:18 by apayen            #+#    #+#             */
/*   Updated: 2022/11/17 10:45:30 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstsize(lst);
	while (i < len - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
