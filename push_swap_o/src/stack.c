/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:54:07 by mbarrah           #+#    #+#             */
/*   Updated: 2025/01/05 03:54:53 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_index(t_stack *stack)
{
	int		current_index;
	t_stack	*ptr;
	t_stack	*smallest;
	int		smallest_value;

	current_index = 1;
	ptr = stack;
	while (1)
	{
		ptr = stack;
		smallest = NULL;
		smallest_value = INT_MAX;
		while (ptr)
		{
			if (ptr->index == 0 && ptr->value < smallest_value)
			{
				smallest_value = ptr->value;
				smallest = ptr;
			}
			ptr = ptr->next;
		}
		if (!smallest)
			break ;
		smallest->index = current_index++;
	}
}

static void	append_node_to_stack(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->index = 0;
	new_node->pos = 0;
	new_node->target_pos = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->next = NULL;
	if (!(*stack))
		*stack = new_node;
	else
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}

static void	validate_and_append(char **res, t_stack **stack_a, int j)
{
	long	n;

	if (syntax_check(res[j]))
	{
		free_split(res, j);
		free_stack(stack_a);
		write(2, "Error\n", 6);
		exit(1);
	}
	n = ft_atol(res[j]);
	if (n > INT_MAX || n < INT_MIN || error_duplicate(*stack_a, (int)n))
	{
		free_split(res, j);
		free_stack(stack_a);
		write(2, "Error\n", 6);
		exit(1);
	}
	append_node_to_stack(stack_a, (int)n);
	free(res[j]);
}

static void	process_arg(char *arg, t_stack **stack_a)
{
	char	**res;
	int		j;

	j = 0;
	res = ft_split(arg, ' ');
	if (!res)
	{
		free_stack(stack_a);
		write(2, "Error\n", 6);
		exit(1);
	}
	while (res[j])
	{
		validate_and_append(res, stack_a, j);
		j++;
	}
	free(res);
}

void	init_stack_a(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		process_arg(argv[i], stack_a);
		i++;
	}
}
