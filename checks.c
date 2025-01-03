/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:41:14 by soujaour          #+#    #+#             */
/*   Updated: 2025/01/02 15:59:30 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (!stack || !stack->next)
		return (1);
	while (current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

void	throw_error(t_stack *ptr, char **arr)
{
	t_stack	*tmp;
	int		i;

	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
	write(2, "Error\n", 6);
	exit(1);
}

void	check_duplicates(t_stack *stack, long n, char **arr)
{
	while (stack)
	{
		if (n == stack->number)
			throw_error(stack, arr);
		stack = stack->next;
	}
}

long	custom_atoi(const char *str, int *error)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	if ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	if (!*str)
		*error = 1;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			num = num * 10 + (*str - '0');
		else
			*error = 1;
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			*error = 1;
		str++;
	}
	return (num * sign);
}
