/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:39:15 by soujaour          #+#    #+#             */
/*   Updated: 2025/01/02 15:29:20 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra(t_stack **a, int i)
{
	t_stack	*before_last;
	t_stack	*last;

	if (count_size(*a) < 2)
		return ;
	before_last = *a;
	while (before_last->next->next)
	{
		before_last = before_last->next;
	}
	last = before_last->next;
	before_last->next = NULL;
	last->next = *a;
	*a = last;
	if (i)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int i)
{
	t_stack	*before_last;
	t_stack	*last;

	if (count_size(*b) < 2)
		return ;
	before_last = *b;
	while (before_last->next->next)
	{
		before_last = before_last->next;
	}
	last = before_last->next;
	before_last->next = NULL;
	last->next = *b;
	*b = last;
	if (i)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int i)
{
	rra(a, 0);
	rrb(b, 0);
	if (i)
		write(1, "rrr\n", 4);
}
