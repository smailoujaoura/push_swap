#include "header.h"

void	sort_three(t_stack *stack)
{
	int	a = stack->number;
	int	b = stack->next->number;
	int c = stack->next->next->number;

	if (a > b && a < c)
		swap_stack(stack);
	else if (a > b && a > c && b < c)
		rotate_stack(stack);
	else if (a < b && b > c && c < a)
		reverse_rotate_stack(stack);
	else if (a > b && b > c)
	{
		rotate_stack(stack);
		swap_stack(stack);
	}
	else if (a < b && b > c)
	{
		reverse_rotate_stack(stack);
		swap_stack(stack);
	}
}