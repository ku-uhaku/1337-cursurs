/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:59:43 by mbarrah           #+#    #+#             */
/*   Updated: 2025/04/16 21:10:31 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_table(t_table *table)
{
	free(table->philo);
	free(table->fork_lock);
}

void	destroy_locks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philosophers)
		pthread_mutex_destroy(&table->fork_lock[i]);
	clean_table(table);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->eat_lock);
	pthread_mutex_destroy(&table->finish_lock);
}

void	finish_dinner(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philosophers)
		pthread_join(table->philo[i].thread, NULL);
	destroy_locks(table);
}

void	start_dinner_monitor(t_table *table)
{
	int	i;
	int	continue_flag;

	continue_flag = 1;
	while (continue_flag)
	{
		i = -1;
		table->ate_enough = 0;
		while (++i < table->philosophers)
		{
			if (continue_flag && is_someone_dead_or_full(&table->philo[i]))
				continue_flag = 0;
		}
		usleep(10);
	}
	finish_dinner(table);
}
