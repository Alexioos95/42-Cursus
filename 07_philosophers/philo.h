/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:06:58 by apayen            #+#    #+#             */
/*   Updated: 2023/05/15 09:53:15 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

struct				s_philo
{
	pthread_mutex_t	*leftfork;
	pthread_mutex_t	*rightfork;
	pthread_t		thread;
	int				nb;
	int				start;
	struct s_table	*table;
	int				lastmeal;
	int				totalmeal;
};

struct				s_table
{
	char			**argv;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	int				argc;
	int				i;
	int				j;
	int				nbphilo;
	int				timedie;
	int				timeeat;
	int				timesleep;
	int				maxsimu;
	struct s_philo	*philo;
	int				starttime;
	int				fail;
	int				died;
	int				paddingstruct;
};

int					init(int argc, char **argv, struct s_table *table);
int					init2(struct s_table *table);
int					createforks(struct s_table *table);
int					createphilos(struct s_table *table);
void				createthreads(struct s_table *table);
void				loop(struct s_philo *philo);
void				monitor(struct s_table *table);
int					checknbmeals(struct s_table *table);

void				*onephilo(void *ptr);
void				*routine(void *ptr);
int					takeforks(struct s_philo *philo);
int					eats(struct s_philo *philo);
void				ft_usleep(struct s_philo *philo, int delay);

int					checkarg(int argc, char **argv);
int					ft_atoi(char *str);
int					gettime(void);
void				printmsg(struct s_philo *philo, char *str);
int					readdeath(struct s_philo *philo);
void				frees(struct s_table *table, int i);

#endif
