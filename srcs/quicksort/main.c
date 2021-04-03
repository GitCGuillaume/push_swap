#include <stdio.h>
#include "../../includes/push_swap.h"
#include "../libft/libft.h"

/*
 ** getting the stack from argv
*/

int	get_stack(char *str, t_stack **stack_a)
{
	ssize_t	atoi;
	int	i;
	int	start;
	int	pos;
	char	*ptr;

	atoi = 0;
	i = 0;
	start = 0;
	pos = 0;
	ptr = NULL;
	if (str)
	{
		while (str[i])
		{
			while (str[i] && str[i] == ' ')
				i++;
			if ((str[i] != '-' || (ft_isdigit(str[i - 1]) == 1 && str[i] == '-')) && ft_isdigit(str[i]) == 0
					&& str[i] != ' ' && str[i] != '\0')
				return (0);
			else
			{
				start = i;
				if (ft_isdigit(str[i]) == 0)
					i++;
				while (str[i] && ft_isdigit(str[i]) == 1)
					i++;
				if (ft_isdigit(str[i]) == 0)
				{
					ptr = ft_substr(str, start, i - start);
					atoi = ft_atoi(ptr);
					free(ptr);
					if (atoi < -2147483648 || atoi > 2147483647)
						return (0);
					ft_lstadd_front_stack(stack_a, ft_lstnew_stack((int)atoi), ++pos);
					start = 0;
				}
			}
		}
	}
	if (ptr != NULL)
		free(ptr);
	return (1);
}

/*
 * * Check duplicate values
*/
int	check_duplicate(t_stack stack)
{
	int	value;

	return (1);
}

/*
 ** main program push_swap
*/

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;
	int	i;
	int	get_stack_ok;

	i = i;
	get_stack_ok = 0;
	stack_a = ft_lstnew_stack(0);
	stack_b = ft_lstnew_stack(0);
	while (argc > i)
	{
		get_stack_ok = get_stack(argv[i], &stack_a);
		i++;
	}
	if (get_stack_ok == 0)
		check_int_stack();
	printf("\n");
	while (stack_a->head != NULL)
	{
		printf("number=%d\n", stack_a->number);
		printf("position=%zu\n", stack_a->position);
		stack_a = stack_a->head;
	}
	return (0);
}
