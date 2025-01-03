/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_sa_sb_ss_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:40:01 by soujaour          #+#    #+#             */
/*   Updated: 2025/01/02 15:29:09 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pa(t_stack **a, t_stack **b, int i)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (i)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int i)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (i)
		write(1, "pb\n", 3);
}

void	sa(t_stack **a, int i)
{
	int	tmp;

	if (count_size(*a) < 2)
		return ;
	tmp = (*a)->number;
	(*a)->number = (*a)->next->number;
	(*a)->next->number = tmp;
	if (i)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int i)
{
	int	tmp;

	if (count_size(*b) < 2)
		return ;
	tmp = (*b)->number;
	(*b)->number = (*b)->next->number;
	(*b)->next->number = tmp;
	if (i)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int i)
{
	sa(a, 0);
	sb(b, 0);
	if (i)
		write(1, "ss\n", 3);
}
