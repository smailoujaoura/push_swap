/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:41:51 by soujaour          #+#    #+#             */
/*   Updated: 2024/12/30 17:19:14 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	detect_comb(t_stack *a, int size)
{
	int	diff;
	int	count;

	count = 0;
	while (a && a->next)
	{
		diff = a->index - a->next->index;
		if (diff == 2 || diff == 3 || diff == 4)
			count++;
		a = a->next;
	}
	if (count * 10 >= size * 6)
		return (1);
	return (0);
}

static int	chunck_size(int size)
{
	if (size > 100)
		return (34);
	else
		return (16);
}

void	pushing_to_b(t_stack **a, t_stack **b, int i, int s)
{
	t_stack	*ptr;
	int		comb;

	comb = detect_comb(*a, count_size(*a));
	s = chunck_size(count_size(*a));
	while (*a)
	{
		ptr = *a;
		if (ptr->index <= i)
		{
			pb(a, b, 1);
			i++;
		}
		else if (ptr->index <= i + s)
		{
			pb(a, b, 1);
			rb(b, 1);
			i++;
		}
		else if (comb)
			rra(a, 1);
		else
			ra(a, 1);
	}
}

void	pushing_to_a(t_stack **a, t_stack **b, int size, int pos)
{
	size = count_size(*b);
	while (size)
	{
		pos = find_max(*b, 1);
		if (pos <= size / 2)
		{
			while (pos--)
				rb(b, 1);
		}
		else
		{
			while (pos++ != size)
				rrb(b, 1);
		}
		pa(a, b, 1);
		size--;
	}
}
