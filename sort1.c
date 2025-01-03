/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:41:47 by soujaour          #+#    #+#             */
/*   Updated: 2024/12/30 16:27:51 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if (is_sorted(*a))
		return ;
	if ((get_last(*a))->number == find_max(*a, 0))
		sa(a, 1);
	else if ((*a)->number == find_max(*a, 0))
	{
		ra(a, 1);
		if (!is_sorted(*a))
			sa(a, 1);
	}
	else
	{
		rra(a, 1);
		if (!is_sorted(*a))
			sa(a, 1);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	while (find_min(*a, 0) != (*a)->number && count_size(*a) > 3)
	{
		if (find_min(*a, 1) <= 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pb(a, b, 1);
	sort_three(a);
	pa(a, b, 1);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (count_size(*b) < 2)
	{
		if (find_min(*a, 0) == (*a)->number)
			pb(a, b, 1);
		else if (find_min(*a, 1) <= 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
	sort_three(a);
	pa(a, b, 1);
	pa(a, b, 1);
}

void	assign_index(t_stack *a)
{
	int		i;
	t_stack	*cur;
	t_stack	*ptr;

	i = 0;
	cur = a;
	while (cur)
	{
		ptr = a;
		while (ptr)
		{
			if (cur->number > ptr->number)
				i++;
			ptr = ptr->next;
		}
		cur->index = i;
		cur = cur->next;
		i = 0;
	}
}
