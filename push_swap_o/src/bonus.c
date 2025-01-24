/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-05 23:35:57 by mbarrah           #+#    #+#             */
/*   Updated: 2025-01-05 23:35:57 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "./get_next_line.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	get_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	get_input(char *inp, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(inp, "ra\n") == 0)
		do_ra(stack_a, 0);
	else if (ft_strcmp(inp, "rb\n") == 0)
		do_rb(stack_b, 0);
	else if (ft_strcmp(inp, "rr\n") == 0)
		do_rr(stack_a, stack_b, 0);
	else if (ft_strcmp(inp, "rra\n") == 0)
		do_rra(stack_a, 0);
	else if (ft_strcmp(inp, "rrb\n") == 0)
		do_rrb(stack_b, 0);
	else if (ft_strcmp(inp, "rrr\n") == 0)
		do_rrr(stack_a, stack_b, 0);
	else if (ft_strcmp(inp, "sa\n") == 0)
		do_sa(stack_a, 0);
	else if (ft_strcmp(inp, "sb\n") == 0)
		do_sb(stack_b, 0);
	else if (ft_strcmp(inp, "ss\n") == 0)
		do_ss(stack_a, stack_b, 0);
	else if (ft_strcmp(inp, "pa\n") == 0)
		do_pa(stack_a, stack_b, 0);
	else if (ft_strcmp(inp, "pb\n") == 0)
		do_pb(stack_a, stack_b, 0);
	else
		get_error();
}

static void	process_and_check(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int len = stack_len(*stack_a);
	line = get_next_line(0);
	while (line != NULL)
	{
		get_input(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (!is_sorted(*stack_a) || stack_len(*stack_a) != len)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		if (argc == 2 && !argv[1][0])
			write(2, "Error\n", 6);
		return (1);
	}
	init_stack_a(argc - 1, argv + 1, &stack_a);
	process_and_check(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
