#include "header.h"

void throw_error(int flag, t_stack *ptr)
{
	// free anything if flag = 1
	if (flag == 1)
		free(ptr);
}

int is_sorted(t_stack *stack)
{
    t_stack *current = stack;
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

int	check_duplicates(t_stack *stack, long n)
{
	while (stack)
	{
		if (n == stack->number)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	check_numbers(char **av, t_stack **a)
{
	int		i;
	long 	n;

	i = 0;
	while(av[i])
	{
		n = custom_atoi(av[i], *a);
		if (n > INT_MAX || n < INT_MIN || !check_duplicates(*a, n))
			throw_error(1, *a);
		check_duplicates(*a, n);
		add_back(a, new_node(n));
		i++;
	} 
}