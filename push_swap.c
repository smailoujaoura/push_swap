/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:38:20 by soujaour          #+#    #+#             */
/*   Updated: 2025/01/02 21:28:04 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack **a, t_stack **b)
{
	if (count_size(*a) == 2)
		sa(a, 1);
	else if (count_size(*a) == 3)
		sort_three(a);
	else if (count_size(*a) == 4)
		sort_four(a, b);
	else if (count_size(*a) == 5)
		sort_five(a, b);
	else
	{
		assign_index(*a);
		pushing_to_b(a, b, 0, 0);
		pushing_to_a(a, b, 0, 0);
	}
}

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

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	parse(&a, argv, 1);
	if (!is_sorted(a) && count_size(a) > 1)
		sort(&a, &b);
	while (a)
	{
		b = a->next;
		free(a);
		a = b;
	}
	return (0);
}
