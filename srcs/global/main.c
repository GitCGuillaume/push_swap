#include "push_swap.h"

/*
 ** Add number into stack
*/

int	add_into_stack(t_stack **stack_a, char *str, int i, int start)
{
	ssize_t	atoi;
	char	*ptr;

	atoi = 0;
	ptr = NULL;
	if (str)
	{
		if (ft_isdigit(str[i]) == 0)
		{
			ptr = ft_substr(str, start, i - start);
			if (ptr == NULL)
				return (-1);
			atoi = ft_atoi(ptr);
			if (ptr != NULL)
				free(ptr);
			if (atoi < -2147483648 || atoi > 2147483647)
				return (-1);
			if (*stack_a != NULL)
				ft_lstadd_back_stack(stack_a, ft_lstnew_stack((int)atoi));
			else
				ft_lstadd_front_stack(stack_a, ft_lstnew_stack((int)atoi));
			start = 0;
		}
	}
	return (1);
}

/*
 ** Get number from the string
*/

int	get_number(t_stack **stack_a, char *str, int *i, int start)
{
	int	result;

	result = 0;
	if (str)
	{
		if (str[*i] == '-')
			(*i)++;
		if (ft_isdigit(str[*i]) == 0)
			return (-1);
		while (str[*i] && ft_isdigit(str[*i]) == 1)
			(*i)++;
		if (stack_a)
			result = add_into_stack(stack_a, str, *i, start);
		if (result == -1)
			return (-1);
		if (str[*i] != '\0' && str[*i] != ' ')
			return (-1);
	}
	return (1);
}

/*
 ** getting the stack from argv
*/

int	get_stack(char *str, t_stack **stack_a)
{
	int	i;
	int	start;
	int	result;

	i = 0;
	start = 0;
	result = 0;
	if (str)
	{
		while (str[i])
		{
			while (str[i] && str[i] == ' ')
				i++;
			if (((ft_isdigit(str[i]) == 0 && str[i] != '-') && str[i] != '\0'))
				return (-1);
			else
			{
				start = i;
				result = get_number(stack_a, str, &i, start);
				if (result == -1)
					return (-1);
			}
		}
	}
	return (1);
}
