/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:04:22 by mbarrah           #+#    #+#             */
/*   Updated: 2025/04/16 20:04:22 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

    if (check_args(ac, av, &table))
        return (1);
    init_table(&table, ac, av);
	init_philosophers(&table);
	init_locks(&table);
	philosophers_to_threads(&table);
	start_dinner_monitor(&table);
	return (0);
}