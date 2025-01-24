/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:52:40 by mbarrah           #+#    #+#             */
/*   Updated: 2025/01/05 03:40:26 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_len)
{
	if (stack_len == 2 && !is_sorted(*stack_a))
		do_sa(stack_a, 1);
	else if (stack_len == 3 && !is_sorted(*stack_a))
		sort_three(stack_a);
	else if (stack_len > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}
