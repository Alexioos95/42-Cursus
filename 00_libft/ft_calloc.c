/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:52:09 by apayen            #+#    #+#             */
/*   Updated: 2022/11/22 13:02:35 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size != 0 && nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	tab = malloc(size * nmemb);
	if (tab == NULL)
	{
		return (NULL);
	}
	ft_bzero(tab, nmemb * size);
	return (tab);
}

/*
#include <stdio.h>
int	main(void)
{
	int	*tab;
	tab = ft_calloc(0, 0);
	free(tab);
}
*/
