/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:23:48 by apayen            #+#    #+#             */
/*   Updated: 2023/05/15 09:23:09 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	frees(struct s_table *table, int i)
{
	while (i >= 0)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i--;
	}
	free(table->forks);
	table->forks = NULL;
	if (table->philo)
		free(table->philo);
	pthread_mutex_destroy(&table->lock);
}

int	gettime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("philo: error gettimeofday");
		return (0);
	}
	return ((int)(time.tv_sec * 1000) + (int)(time.tv_usec / 1000));
}

int	readdeath(struct s_philo *philo)
{
	pthread_mutex_lock(&philo->table->lock);
	if (philo->table->died == 1)
	{
		pthread_mutex_unlock(&philo->table->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->lock);
	return (0);
}

int	ft_atoi(char *str)
{
	int				i;
	long long int	result;
	long long int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if ((result > INT_MAX) || (result * sign < INT_MIN))
			return (0);
	}
	return ((int)result * (int)sign);
}

int	checkarg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9') && argv[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
