/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:06:35 by apayen            #+#    #+#             */
/*   Updated: 2023/05/15 09:52:54 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checknbmeals(struct s_table *table)
{
	int	i;

	i = 0;
	if (table->maxsimu == -1)
		return (0);
	while (i < table->nbphilo)
	{
		if (table->philo[i].totalmeal < table->maxsimu)
			return (0);
		i++;
	}
	table->died = 1;
	pthread_mutex_unlock(&table->lock);
	return (1);
}

void	monitor(struct s_table *table)
{
	int	i;

	if (table->fail == 1)
		return ;
	while (1)
	{
		pthread_mutex_lock(&table->lock);
		i = 0;
		while (i < table->nbphilo)
		{
			if (gettime() - table->philo[i].lastmeal > table->timedie)
			{
				table->died = 1;
				printf("%d %d died\n", gettime() - table->starttime, i + 1);
				pthread_mutex_unlock(&table->lock);
				return ;
			}
			i++;
		}
		if (checknbmeals(table) == 1)
			return ;
		pthread_mutex_unlock(&table->lock);
		usleep(5000);
	}
}

void	loop(struct s_philo *philo)
{
	while (1)
	{
		if (readdeath(philo) == 1)
			return ;
		if (takeforks(philo) == 1)
			return ;
		if (eats(philo) == 1)
			return ;
		printmsg(philo, "is sleeping");
		ft_usleep(philo, philo->table->timesleep);
		if (readdeath(philo) == 1)
			return ;
		printmsg(philo, "is thinking");
		ft_usleep(philo, (unsigned int)(philo->table->timedie \
			- (philo->table->timeeat + philo->table->timesleep)) / 2);
	}
}

void	*routine(void *ptr)
{
	struct s_philo	*philo;

	philo = (struct s_philo *)ptr;
	pthread_mutex_lock(&philo->table->lock);
	if (philo->table->fail == 1)
		return (0);
	pthread_mutex_unlock(&philo->table->lock);
	if (philo->nb % 2 == 0)
		ft_usleep(philo, philo->table->timeeat);
	loop(philo);
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_table	table;

	if (init(argc, argv, &table) == 1)
		return (1);
	if (table.nbphilo == 1)
	{
		pthread_mutex_lock(&table.lock);
		table.starttime = gettime();
		table.philo[0].lastmeal = table.starttime;
		if (pthread_create(&table.philo[0].thread, NULL, \
			&onephilo, &table.philo[0]) != 0)
			return ((void)printf("philo: error pthread"), \
				(void)frees(&table, table.nbphilo), 1);
		pthread_mutex_unlock(&table.lock);
		monitor(&table);
		pthread_join(table.philo[0].thread, NULL);
	}
	else
		createthreads(&table);
	frees(&table, table.nbphilo - 1);
	if (table.fail == 1)
		return (1);
	return (0);
}
