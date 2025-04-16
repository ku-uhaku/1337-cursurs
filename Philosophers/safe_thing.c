/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_thing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:04:06 by mbarrah           #+#    #+#             */
/*   Updated: 2025/04/16 20:04:06 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_mutex_lock(pthread_mutex_t *mutex, t_table *table)
{
	if (pthread_mutex_lock(mutex) != 0)
		exit_error("Failed to lock mutex", table, 2);
}

void	safe_mutex_unlock(pthread_mutex_t *mutex, t_table *table)
{
	if (pthread_mutex_unlock(mutex) != 0)
		exit_error("Failed to unlock mutex", table, 2);
}

