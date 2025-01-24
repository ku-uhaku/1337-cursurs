/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:04:03 by mbarrah           #+#    #+#             */
/*   Updated: 2025/01/05 03:43:36 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	if (!(*stack) || !stack)
		return ;
	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	do_rra(t_stack **stack, int print)
{
	rev_rotate(stack);
	if (print)
		write(1, "rra\n", 4);
}

void	do_rrb(t_stack **stack, int print)
{
	rev_rotate(stack);
	if (print)
		write(1, "rrb\n", 4);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (print)
		write(1, "rrr\n", 4);
}
