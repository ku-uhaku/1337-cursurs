/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:04:03 by mbarrah           #+#    #+#             */
/*   Updated: 2025/04/16 20:04:03 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_time_to_finish(t_philo *philo, int finish_order)
{
	safe_mutex_lock(&philo->table->finish_lock, philo->table);
	if (finish_order || philo->table->finish_flag)
	{
		if (finish_order)
			philo->table->finish_flag = 1;
		safe_mutex_unlock(&philo->table->finish_lock, philo->table);
		return (1);
	}
	safe_mutex_unlock(&philo->table->finish_lock, philo->table);
	return (0);
}

int	is_someone_dead_or_full(t_philo *philo)
{
	safe_mutex_lock(&philo->table->eat_lock, philo->table);
	if (now() - philo->last_eat >= philo->table->time_to_die)
	{
		print_action(philo, DIE);
		is_time_to_finish(philo, TRUE);
		safe_mutex_unlock(&philo->table->eat_lock, philo->table);
		return (1);
	}
	else if (philo->table->must_eat_times > 0
		&& philo->eat_count >= philo->table->must_eat_times)
	{
		philo->table->ate_enough++;
		if (philo->table->ate_enough >= philo->table->philosophers)
		{
			is_time_to_finish(philo, TRUE);
			safe_mutex_unlock(&philo->table->eat_lock, philo->table);
			return (1);
		}
	}
	safe_mutex_unlock(&philo->table->eat_lock, philo->table);
	return (0);
}

void	time_to_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		safe_mutex_lock(&philo->table->fork_lock[philo->l_fork], philo->table);
		safe_mutex_lock(&philo->table->fork_lock[philo->r_fork], philo->table);
	}
	else
	{
		safe_mutex_lock(&philo->table->fork_lock[philo->r_fork], philo->table);
		safe_mutex_lock(&philo->table->fork_lock[philo->l_fork], philo->table);
	}
	print_action(philo, TAKE);
	print_action(philo, TAKE);
	print_action(philo, EAT);
	advance_time(philo, philo->table->time_to_eat);
	safe_mutex_lock(&philo->table->eat_lock, philo->table);
	philo->eat_count++;
	philo->last_eat = now();
	safe_mutex_unlock(&philo->table->eat_lock, philo->table);
	safe_mutex_unlock(&philo->table->fork_lock[philo->r_fork], philo->table);
	safe_mutex_unlock(&philo->table->fork_lock[philo->l_fork], philo->table);
}

int	lone_philosopher(t_table *table)
{
	print_action(&table->philo[0], TAKE);
	advance_time(&table->philo[0], table->time_to_die);
	print_action(&table->philo[0], DIE);
	is_time_to_finish(&table->philo[0], TRUE);
	return (0);
}

void	*start_dinner(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		advance_time(philo, philo->table->time_to_eat); /*This check is for make sure that the philo with even id will eat first*/
	while (1)
	{
		if (philo->table->philosophers == 1)
		{
			lone_philosopher(philo->table);
			return (0);
		}
		if (is_time_to_finish(philo, FALSE))
			return (0);
		time_to_eat(philo);
		print_action(philo, SLEEP);
		advance_time(philo, philo->table->time_to_sleep);
		print_action(philo, THINK);
		if (philo->table->philosophers % 2 != 0)
			advance_time(philo, philo->table->time_to_eat);
	}	
	return (0);
}

int	philosophers_to_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philosophers)
	{
		if (pthread_create(&table->philo[i].thread, NULL, \
			start_dinner, &table->philo[i]))
			exit_error("Couldn't create thread", table, 3);
	}
	return (0);
}