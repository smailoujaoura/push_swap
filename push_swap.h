/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:42:18 by soujaour          #+#    #+#             */
/*   Updated: 2025/01/02 16:03:04 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	long			number;
	int				index;
}	t_stack;

int		is_sorted(t_stack *stack);
void	throw_error(t_stack *ptr, char **arr);
void	check_duplicates(t_stack *stack, long n, char **arr);
long	custom_atoi(const char *str, int *error);
t_stack	*new_node(long n);
t_stack	*get_last(t_stack *stack);
int		add_back(t_stack **stack, t_stack *new);
int		count_size(t_stack *stack);
int		find_max(t_stack *stack, int i);
int		find_min(t_stack *stack, int i);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	assign_index(t_stack *a);
void	pushing_to_a(t_stack **a, t_stack **b, int size, int i);
void	pushing_to_b(t_stack **a, t_stack **b, int i, int s);
void	pa(t_stack **a, t_stack **b, int i);
void	pb(t_stack **a, t_stack **b, int i);
void	sa(t_stack **a, int i);
void	sb(t_stack **b, int i);
void	ss(t_stack **a, t_stack **b, int i);
void	ra(t_stack **a, int i);
void	rb(t_stack **b, int i);
void	rr(t_stack **a, t_stack **b, int i);
void	rra(t_stack **a, int i);
void	rrr(t_stack **a, t_stack **b, int i);
void	rrb(t_stack **b, int i);

#endif