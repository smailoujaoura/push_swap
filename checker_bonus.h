/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:42:14 by soujaour          #+#    #+#             */
/*   Updated: 2025/01/02 16:53:59 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	long			number;
	int				index;
}	t_stack;

typedef struct s_ops
{
	char			*op;
	struct s_ops	*next;
}	t_ops;

t_stack	*new_node(long n);
t_stack	*get_last(t_stack *stack);
int		is_sorted(t_stack *stack);
int		add_back(t_stack **stack, t_stack *new);
int		count_size(t_stack *stack);
int		ft_strcmp(const char *s1, const char *s2);
void	throw_error(t_stack *ptr, char **arr);
void	check_duplicates(t_stack *stack, long n, char **arr);
void	check_op(char *op, t_stack *a, t_stack *b, t_ops *ops);
long	custom_atoi(const char *str, int *error);
void	finish(t_stack *a, t_stack *b, t_ops *ops);
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