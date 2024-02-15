/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:23:12 by apayen            #+#    #+#             */
/*   Updated: 2023/05/10 16:43:26 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printmsg(struct s_philo *philo, char *str)
{
	int	time;

	pthread_mutex_lock(&philo->table->lock);
	if (philo->table->died == 0)
	{
		time = gettime() - philo->table->starttime;
		printf("%d %d %s\n", time, philo->nb, str);
	}
	pthread_mutex_unlock(&philo->table->lock);
}

void	ft_usleep(struct s_philo *philo, int delay)
{
	int	start;

	start = gettime();
	while (gettime() - start < delay && readdeath(philo) == 0)
		usleep(500);
}

int	eats(struct s_philo *philo)
{
	philo->lastmeal = gettime();
	philo->totalmeal++;
	printmsg(philo, "is eating");
	ft_usleep(philo, philo->table->timeeat);
	pthread_mutex_unlock(philo->leftfork);
	pthread_mutex_unlock(philo->rightfork);
	if (readdeath(philo) == 1)
		return (1);
	return (0);
}

int	takeforks(struct s_philo *philo)
{
	if (philo->nb % 2 == 0)
	{
		pthread_mutex_lock(philo->rightfork);
		printmsg(philo, "has taken a fork");
		pthread_mutex_lock(philo->leftfork);
		printmsg(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->leftfork);
		printmsg(philo, "has taken a fork");
		pthread_mutex_lock(philo->rightfork);
		printmsg(philo, "has taken a fork");
	}
	if (readdeath(philo) == 1)
	{
		pthread_mutex_unlock(philo->rightfork);
		pthread_mutex_unlock(philo->leftfork);
		return (1);
	}
	return (0);
}

void	*onephilo(void *ptr)
{
	struct s_philo	*philo;

	philo = (struct s_philo *)ptr;
	pthread_mutex_lock(philo->leftfork);
	printmsg(philo, "has taken a fork");
	ft_usleep(philo, philo->table->timedie * 2);
	pthread_mutex_unlock(philo->leftfork);
	return (0);
}
