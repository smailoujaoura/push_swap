/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:41:42 by soujaour          #+#    #+#             */
/*   Updated: 2024/12/26 12:18:13 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(long n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->number = n;
	return (new);
}

int	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return (-1);
	last = get_last(*stack);
	if (last)
		last->next = new;
	else
		*stack = new;
	return (0);
}

int	find_min(t_stack *stack, int i)
{
	int		min;
	int		pos;
	t_stack	*ptr;

	pos = 0;
	min = stack->number;
	ptr = stack;
	while (stack)
	{
		if (stack->number < min)
			min = stack->number;
		stack = stack->next;
	}
	while (ptr->number != min)
	{
		ptr = ptr->next;
		pos++;
	}
	if (i)
		return (pos);
	return (min);
}

int	find_max(t_stack *stack, int i)
{
	int		max;
	int		pos;
	t_stack	*ptr;

	max = stack->number;
	pos = 0;
	ptr = stack;
	while (stack)
	{
		if (stack->number > max)
			max = stack->number;
		stack = stack->next;
	}
	while (ptr->number != max)
	{
		ptr = ptr->next;
		pos++;
	}
	if (i)
		return (pos);
	return (max);
}

t_stack	*get_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}
