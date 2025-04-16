/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:44:12 by mbarrah           #+#    #+#             */
/*   Updated: 2025/04/16 18:44:12 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				l_fork;
	int				r_fork;
	long long		last_eat;
	struct s_table	*table;
	pthread_t		thread;
}					t_philo;

typedef struct s_table
{
	int				philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_times;
	int				ate_enough;
	int				finish_flag;
	long long		start_time;
	t_philo			*philo;
	pthread_mutex_t	*fork_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	finish_lock;
}					t_table;

# define TAKE "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"
# define TRUE 1
# define FALSE 0

int         check_args(int argc, char **argv, t_table *table);  
void		advance_time(t_philo *philo, long long ms);
void		print_action(t_philo *philo, const char *status);
long long	now();
void		exit_error(char *msg, t_table *table, int n);
int			ft_atoi(const char *s);
void		safe_mutex_lock(pthread_mutex_t *mutex, t_table *table);
void		safe_mutex_unlock(pthread_mutex_t *mutex, t_table *table);
int			lone_philosopher(t_table *table);
void		init_locks(t_table *table);
void		init_philosophers(t_table *table);
void		init_table(t_table *table, int ac, char **av);
int			is_time_to_finish(t_philo *philo, int order);
int			is_someone_dead_or_full(t_philo *philo);
void		time_to_eat(t_philo *philo);
void		*start_dinner(void *arg);
int			philosophers_to_threads(t_table *table);
void		clean_table(t_table *table);
void		destroy_locks(t_table *table);
void		finish_dinner(t_table *table);
void		start_dinner_monitor(t_table *table);

#endif