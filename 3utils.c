#include "header.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = 0;
	while (src[s_len])
		s_len++;
	if (dstsize == 0)
		return (s_len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s_len);
}


t_stack *new_node(long n)
{
	t_stack *new;

	new = malloc(sizeof new);
	new->next = NULL;
	new->number = n;
	return (new);
}

void	add_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}

t_stack	*get_last(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (*stack)
	{
		last = get_last(*stack);
		last->next = new;
	}
	else
		*stack = new;
}

long	custom_atoi(const char *str, t_stack *a)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	if ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			num = num * 10 + (*str - '0');
		else
			throw_error(0, a);
		str++;
	}
	return (num * sign);
}

// Split BEGIN
static int	ft_word_len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_words_counter(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **arr, int i)
{
	int	index;

	index = 0;
	while (index < i)
	{
		free(arr[index]);
		index++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	char	*alt_s;

	if (!s)
		return (NULL);
	alt_s = (char *)s;
	arr = (char **)malloc(sizeof(char *) * (ft_words_counter(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < ft_words_counter(s, c))
	{
		while (*alt_s == c)
			alt_s++;
		arr[i] = (char *)malloc(sizeof(char) * ft_word_len(alt_s, c) + 1);
		if (!arr[i])
			return (ft_free(arr, i));
		ft_strlcpy(arr[i], alt_s, ft_word_len(alt_s, c) + 1);
		alt_s += ft_word_len(alt_s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
// Split END
