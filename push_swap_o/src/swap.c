/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:04:15 by mbarrah           #+#    #+#             */
/*   Updated: 2025/01/05 03:43:40 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	*stack = second;
	first->next = second->next;
	second->next = first;
}

void	do_sa(t_stack **stack, int print)
{
	swap(stack);
	if (print)
		write(1, "sa\n", 3);
}

void	do_sb(t_stack **stack, int print)
{
	swap(stack);
	if (print)
		write(1, "sb\n", 3);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		write(1, "ss\n", 3);
}
