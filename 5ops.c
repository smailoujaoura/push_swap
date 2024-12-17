#include "header.h"

void	swap_stack(t_stack *stack)
{
	int	tmp;
	if (!stack || !stack->next)
		return ;
	tmp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = tmp;
}

void	push_stack(t_stack *dst, t_stack *src)
{
	t_stack	*tmp;

	if (!src)
		return ;
	tmp = src;
	src = src->next;
	tmp->next = dst;
	dst = tmp;
}

void	rotate_stack(t_stack *stack)
{
	t_stack *first = stack;
	t_stack *last = get_last(stack);

	if (!stack || !stack->next)
		return ;
	last->next = first;
	stack = first->next;
	first->next = NULL;
}

void	reverse_rotate_stack(t_stack *stack)
{
	if (!stack || !stack->next)
		return ;
	t_stack *last;
	t_stack *before_last = stack;

	while (before_last->next->next)
		before_last = before_last->next;

	last = before_last->next;
	before_last->next = NULL;
	last->next = stack;
	stack = last;
}
