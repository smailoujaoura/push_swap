#include "header.h"

int main(int ac, char *av[])
{
	if (ac == 1)
	{
		exit(0);
	}
	else if (ac == 2)
	{
		// split
		av = ft_split(av[1], ' '); // may need to split with other chars
	}
	int	size;
	size = 0;
	t_stack *stack_a;
	//t_stack *stack_b;
	check_numbers(av, &stack_a);
	// other checks
	// sort logic
}


/*
	- check that we have at least two args
	- if we have two args we should split them based on one space
	- if we have more than 2 args we should just start these other checks:
		- they are numeric and in integer range
		- check that there is no duplicates
*/