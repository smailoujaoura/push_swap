/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:41:58 by soujaour          #+#    #+#             */
/*   Updated: 2025/01/01 09:20:36 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	finish(t_stack *a, t_stack *b, t_ops *ops)
{
	t_stack	*ptr;
	t_ops	*tmp;

	while (a)
	{
		ptr = a->next;
		free(a);
		a = ptr;
	}
	while (b)
	{
		ptr = b->next;
		free(b);
		b = ptr;
	}
	tmp = ops;
	while (ops)
	{
		tmp = ops->next;
		free(ops->op);
		free(ops);
		ops = tmp;
	}
}

static void	exit_cleanly(t_stack *a, t_stack *b, t_ops *ops)
{
	finish(a, b, ops);
	write(2, "Error\n", 6);
	exit(1);
}

void	check_op(char *op, t_stack *a, t_stack *b, t_ops *ops)
{
	if (ft_strcmp(op, "ra\n") == 0)
		return ;
	else if (ft_strcmp(op, "rb\n") == 0)
		return ;
	else if (ft_strcmp(op, "rr\n") == 0)
		return ;
	else if (ft_strcmp(op, "pa\n") == 0)
		return ;
	else if (ft_strcmp(op, "pb\n") == 0)
		return ;
	else if (ft_strcmp(op, "sa\n") == 0)
		return ;
	else if (ft_strcmp(op, "sb\n") == 0)
		return ;
	else if (ft_strcmp(op, "ss\n") == 0)
		return ;
	else if (ft_strcmp(op, "rra\n") == 0)
		return ;
	else if (ft_strcmp(op, "rrb\n") == 0)
		return ;
	else if (ft_strcmp(op, "rrr\n") == 0)
		return ;
	else
		exit_cleanly(a, b, ops);
}
