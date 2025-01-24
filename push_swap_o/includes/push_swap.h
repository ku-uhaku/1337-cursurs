/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:00:09 by mbarrah           #+#    #+#             */
/*   Updated: 2025/01/05 03:35:55 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	int				pos;
	int				target_pos;
	struct s_stack	*next;
}					t_stack;

char				**ft_split(const char *s, char c);
int					ft_isdigit(int c);
long				ft_atol(const char *s);
int					nb_abs(int nb);
void				init_stack_a(int argc, char **argv, t_stack **stack_a);
void				free_split(char **split, int i);
void				assign_index(t_stack *stack);
int					syntax_check(char *str_n);
int					error_duplicate(t_stack *a, int n);
void				free_stack(t_stack **stack);
void				free_errors(t_stack **stack_a, t_stack **stack_b,
						char **arr);
int					is_sorted(t_stack *stack);
void				shift_stack(t_stack **stack_a);
void				sort_three(t_stack **stack);
void				push_all_save_three(t_stack **stack_a, t_stack **stack_b);
void				get_position(t_stack **stack);
int					get_target(t_stack **stack_a, int b_index, int target_idx,
						int target_pos);
void				get_target_position(t_stack **stack_a, t_stack **stack_b);
void				do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void				push_swap(t_stack **stack_a, t_stack **stack_b,
						int stack_len);
void				get_cost(t_stack **stack_a, t_stack **stack_b);
int					stack_len(t_stack *stack);
t_stack				*find_highest_node(t_stack *stack);
int					get_lowest_index_position(t_stack **stack);
t_stack				*get_stack_before_bottom(t_stack *stack);
t_stack				*get_stack_bottom(t_stack *stack);
void				do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void				do_rotate_b(t_stack **b, int *cost);
void				do_rotate_a(t_stack **a, int *cost);
void				do_rotate_both(t_stack **a, t_stack **b, int *cost_a,
						int *cost_b);
void				do_rev_rotate_both(t_stack **a, t_stack **b, int *cost_a,
						int *cost_b);
void				do_sa(t_stack **stack, int print);
void				do_sb(t_stack **stack, int print);
void				do_ss(t_stack **stack_a, t_stack **stack_b, int print);
void				do_ra(t_stack **stack, int print);
void				do_rb(t_stack **stack, int print);
void				do_rr(t_stack **stack_a, t_stack **stack_b, int print);
void				do_rrr(t_stack **stack_a, t_stack **stack_b, int print);
void				do_rrb(t_stack **stack, int print);
void				do_rra(t_stack **stack, int print);
void				do_pb(t_stack **stack_a, t_stack **stack_b, int print);
void				do_pa(t_stack **stack_a, t_stack **stack_b, int print);
char				*get_next_line(int fd);
size_t				ft_strlen(char *str);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strndup(const char *s, int n);
ssize_t				check_cursor(char *cursor);

#endif