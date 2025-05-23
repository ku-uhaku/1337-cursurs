/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:04:17 by mbarrah           #+#    #+#             */
/*   Updated: 2025/04/16 21:12:02 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_locks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philosophers)
	{
		if (pthread_mutex_init(&table->fork_lock[i], NULL))
			exit_error("Couldn't init forks mutex", table, 2);
	}
	if (pthread_mutex_init(&table->print_lock, NULL))
		exit_error("Couldn't init print mutex", table, 2);
	if (pthread_mutex_init(&table->eat_lock, NULL))
		exit_error("Couldn't init eat mutex", table, 2);
	if (pthread_mutex_init(&table->finish_lock, NULL))
		exit_error("Couldn't init finish mutex", table, 2);
}

void	init_philosophers(t_table *table)
{
	int	i;

	i = -1;
	table->philo = malloc(sizeof(t_philo) * table->philosophers);
	table->fork_lock = malloc(sizeof(pthread_mutex_t) * table->philosophers);
	if (!table->philo || !table->fork_lock)
		exit_error("Couldn't create the philosophers or forks", table, 1);
	table->start_time = now();
	while (++i < table->philosophers)
	{
		table->philo[i].id = i + 1;
		table->philo[i].l_fork = i;
		if (i == table->philosophers - 1)
			table->philo[i].r_fork = 0;
		else
			table->philo[i].r_fork = i + 1;
		table->philo[i].eat_count = 0;
		table->philo[i].last_eat = table->start_time;
		table->philo[i].table = table;
	}
}

void	init_table(t_table *table, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		exit_error("Wrong number of arguments", NULL, 0);
	table->philosophers = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->must_eat_times = ft_atoi(av[5]);
	else
		table->must_eat_times = -1;
	table->finish_flag = 0;
}
