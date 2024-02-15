/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:03:56 by apayen            #+#    #+#             */
/*   Updated: 2023/05/10 16:47:55 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	createthreads(struct s_table *table)
{
	pthread_mutex_lock(&table->lock);
	while (table->i < table->nbphilo)
	{
		table->starttime = gettime();
		table->philo[table->i].lastmeal = table->starttime;
		if (pthread_create(&table->philo[table->i].thread, NULL, \
			&routine, &table->philo[table->i]) != 0)
		{
			table->fail = 1;
			printf("philo: error pthread");
			break ;
		}
		table->i++;
	}
	pthread_mutex_unlock(&table->lock);
	monitor(table);
	while (table->j < table->i)
	{
		pthread_join(table->philo[table->j].thread, NULL);
		table->j++;
	}
}

int	createphilos(struct s_table *table)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(struct s_philo) \
		* (unsigned long)table->nbphilo);
	if (table->philo == NULL)
	{
		frees(table, table->nbphilo);
		return ((void)printf("philo: error malloc\n"), 1);
	}
	while (i < table->nbphilo)
	{
		table->philo[i].nb = i + 1;
		table->philo[i].table = table;
		table->philo[i].leftfork = &table->forks[i];
		if (table->nbphilo == 1)
			table->philo[i].rightfork = NULL;
		else
			table->philo[i].rightfork = &table->forks[(i + 1) % table->nbphilo];
		table->philo[i].lastmeal = table->starttime;
		table->philo[i].totalmeal = 0;
		i++;
	}
	return (0);
}

int	createforks(struct s_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * (size_t)table->nbphilo);
	if (table->forks == NULL)
		return ((void)printf("philo: error malloc\n"), 1);
	while (i < table->nbphilo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			frees(table, i - 1);
			return ((void)printf("philo: error mutex\n"), 1);
		}
		i++;
	}
	if (createphilos(table) == 1)
		return ((void)frees(table, i), 1);
	return (0);
}

int	init2(struct s_table *table)
{
	table->nbphilo = ft_atoi(table->argv[1]);
	table->timedie = ft_atoi(table->argv[2]);
	table->timeeat = ft_atoi(table->argv[3]);
	table->timesleep = ft_atoi(table->argv[4]);
	if (table->nbphilo < 1 || table->timedie < 1 || table->timeeat < 1 \
		|| table->timesleep < 1)
		return ((void)printf("philo: invalid argument\n"), 1);
	if (table->argc == 6)
	{
		table->maxsimu = ft_atoi(table->argv[5]);
		if (table->maxsimu < 1)
			return ((void)printf("philo: invalid argument\n"), 1);
	}
	if (pthread_mutex_init(&table->lock, NULL) != 0)
		return ((void)printf("philo: error mutex\n"), 1);
	if (createforks(table) == 1)
		return (1);
	return (0);
}

int	init(int argc, char **argv, struct s_table *table)
{
	if (argc < 5 || argc > 6)
	{
		printf("philo: usage: ./philo number_of_philo time_to_die ");
		printf("time_to_eat time_to_sleep number_of_simulation\n");
		return (1);
	}
	if (checkarg(argc, argv) == 1)
		return ((void)printf("philo: invalid argument\n"), 1);
	table->i = 0;
	table->j = 0;
	table->fail = 0;
	table->argc = argc;
	table->argv = argv;
	table->maxsimu = -1;
	table->died = 0;
	table->starttime = 0;
	table->philo = NULL;
	table->forks = NULL;
	if (init2(table) == 1)
		return (1);
	return (0);
}
