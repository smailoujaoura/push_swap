/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:42:02 by soujaour          #+#    #+#             */
/*   Updated: 2025/01/01 09:20:26 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	parse(t_stack **a, char *argv[], int i)
{
	long	n;
	int		error;
	char	**arr;

	while (*(++argv))
	{
		i = 0;
		arr = ft_split(*argv, ' ');
		if (!arr || !*arr)
			throw_error(*a, arr);
		while (arr[i])
		{
			error = 0;
			n = custom_atoi(arr[i++], &error);
			check_duplicates(*a, n, arr);
			if (error)
				throw_error(*a, arr);
			if (add_back(a, new_node(n)))
				throw_error(*a, arr);
		}
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

static t_ops	*store_op(char *op, t_ops **ops)
{
	t_ops	*new;
	t_ops	*ptr;

	new = malloc(sizeof(t_ops));
	if (!new)
		return (NULL);
	new->op = op;
	new->next = NULL;
	ptr = *ops;
	if (!*ops)
		*ops = new;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	return (new);
}

static void	apply_op(t_stack **a, t_stack **b, char *op)
{
	if (ft_strcmp(op, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(op, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(op, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(a, b, 0);
}

static void	apply_ops(t_ops *ops, t_stack **a, t_stack **b)
{
	while (ops)
	{
		apply_op(a, b, ops->op);
		ops = ops->next;
	}
}
#include <stdio.h>
int	main(int argc, char *argv[])
{
	char	*line;
	t_stack	*a;
	t_stack	*b;
	t_ops	*ops;

	a = NULL;
	b = NULL;
	ops = NULL;
	if (argc < 2)
		return (0);
	parse(&a, argv, 1);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		check_op(line, a, b, ops);
		store_op(line, &ops);
	}
	apply_ops(ops, &a, &b);
	if (is_sorted(a) && count_size(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	finish(a, b, ops);
}
