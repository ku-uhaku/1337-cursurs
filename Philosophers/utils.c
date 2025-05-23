/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:03:54 by mbarrah           #+#    #+#             */
/*   Updated: 2025/04/16 21:10:57 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	advance_time(t_philo *philo, long long stop)
{
	long long	begin;

	begin = now();
	while (!is_time_to_finish(philo, FALSE) && (now() - begin) < stop)
		usleep(100);
}

void	print_action(t_philo *philo, const char *status)
{
	long long	time;

	safe_mutex_lock(&philo->table->print_lock, philo->table);
	if (!is_time_to_finish(philo, FALSE))
	{
		time = now() - philo->table->start_time;
		printf("%lld %d %s\n", time, philo->id, status);
	}
	safe_mutex_unlock(&philo->table->print_lock, philo->table);
}

long long	now(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000) + (timeval.tv_usec / 1000));
}

void	exit_error(char *msg, t_table *table, int n)
{
	printf("Error: %s\n", msg);
	if (n == 1)
		clean_table(table);
	if (n == 2)
		destroy_locks(table);
	if (n == 3)
		finish_dinner(table);
	exit(1);
}

int	ft_atoi(const char *s)
{
	int	r;
	int	sg;

	r = 0;
	sg = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sg *= -1;
		s++;
	}
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (-1);
		else if (*s >= '0' && *s <= '9')
			r = (r * 10) + (*s - '0');
		s++;
	}
	return (sg * r);
}
