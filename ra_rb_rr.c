/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:37:57 by soujaour          #+#    #+#             */
/*   Updated: 2025/01/02 16:56:42 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int i)
{
	t_stack	*first;
	t_stack	*last;

	if (count_size(*a) < 2)
		return ;
	first = *a;
	last = get_last(*a);
	last->next = first;
	*a = first->next;
	first->next = NULL;
	if (i)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int i)
{
	t_stack	*first;
	t_stack	*last;

	if (count_size(*b) < 2)
		return ;
	first = *b;
	last = get_last(*b);
	last->next = first;
	*b = first->next;
	first->next = NULL;
	if (i)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int i)
{
	ra(a, 0);
	rb(b, 0);
	if (i)
		write(1, "rr\n", 3);
}
