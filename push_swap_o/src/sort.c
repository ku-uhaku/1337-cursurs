/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:13:51 by mbarrah           #+#    #+#             */
/*   Updated: 2025/01/05 03:41:15 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	median;

	stack_size = stack_len(*stack_a);
	pushed = 0;
	median = stack_size / 2;
	while (stack_size > 3 && pushed < stack_size - 3)
	{
		if ((*stack_a)->index <= median)
		{
			do_pb(stack_a, stack_b, 1);
			pushed++;
		}
		else
			do_ra(stack_a, 1);
		stack_size = stack_len(*stack_a);
	}
	while (stack_len(*stack_a) > 3)
	{
		do_pb(stack_a, stack_b, 1);
	}
}

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_target(t_stack **stack_a, int b_index, int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index > b_index && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	target_pos = 0;
	while (tmp_b)
	{
		tmp_b->target_pos = get_target(stack_a, tmp_b->index, INT_MAX,
				target_pos);
		tmp_b = tmp_b->next;
	}
}

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_b;
	int		size_a;
	int		size_b;
	int		median_b;
	int		median_a;

	size_a = stack_len(*stack_a);
	size_b = stack_len(*stack_b);
	current_b = *stack_b;
	median_b = size_b / 2;
	median_a = size_a / 2;
	while (current_b)
	{
		if (current_b->pos <= median_b)
			current_b->cost_b = current_b->pos;
		else
			current_b->cost_b = (size_b - current_b->pos) * -1;
		if (current_b->target_pos <= median_a)
			current_b->cost_a = current_b->target_pos;
		else
			current_b->cost_a = (size_a - current_b->target_pos) * -1;
		current_b = current_b->next;
	}
}
