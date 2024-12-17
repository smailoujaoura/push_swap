#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct	s_stack
{
	struct s_stack	*next;
	long			number;
}	t_stack;

long	custom_atoi(const char *str, t_stack *a);
char	**ft_split(char const *s, char c);

void	add_back(t_stack **stack, t_stack *new);
t_stack *new_node(long n);

void	check_numbers(char **av, t_stack **a);

void throw_error(int flag, t_stack *ptr);


void	swap_stack(t_stack *stack);
void	push_stack(t_stack *dst, t_stack *src);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

t_stack	*get_last(t_stack *node);

#endif