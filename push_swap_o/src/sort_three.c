/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:13:03 by mbarrah           #+#    #+#             */
/*   Updated: 2025/01/05 03:36:31 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*highest_node;

	highest_node = find_highest_node(*stack);
	if ((*stack)->value == highest_node->value)
		do_ra(stack, 1);
	else if ((*stack)->next->value == highest_node->value)
		do_rra(stack, 1);
	if ((*stack)->value > (*stack)->next->value)
		do_sa(stack, 1);
}
