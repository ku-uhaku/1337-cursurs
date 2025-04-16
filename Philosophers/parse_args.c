/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:16:18 by mbarrah           #+#    #+#             */
/*   Updated: 2025/04/16 21:10:46 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	__check_args_number(int argc)
{
	if (argc != 5 && argc != 6)
		return (1);
	return (0);
}

static int	__check_args_value(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (!argv[i][j])
			return (1);
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	__check_args_value_range(int argc, char **argv)
{
	long	num;
	int		i;

	num = ft_atoi(argv[1]);
	if (num <= 0 || num > 200)
		return (1);
	i = 1;
	while (++i <= 4)
	{
		num = ft_atoi(argv[i]);
		if (num < 60 || num > INT_MAX)
			return (1);
	}
	if (argc == 6)
	{
		num = ft_atoi(argv[5]);
		if (num < 0 || num > INT_MAX)
			return (1);
	}
	return (0);
}

static void	__do_nothing(void)
{
	exit(0);
}

int	check_args(int argc, char **argv, t_table *table)
{
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) == 0)
			__do_nothing();
	}
	if (__check_args_number(argc))
	{
		exit_error("Error: Invalid number of arguments\n", table, 0);
		return (1);
	}
	if (__check_args_value(argc, argv))
	{
		exit_error("Error: Invalid argument format\n", table, 0);
		return (1);
	}
	if (__check_args_value_range(argc, argv))
	{
		exit_error("Error: Arguments out of range\n", table, 0);
		return (1);
	}
	return (0);
}
