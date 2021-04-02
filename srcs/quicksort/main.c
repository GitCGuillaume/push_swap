#include <stdio.h>
#include "../../includes/push_swap.h"
#include "../libft/libft.h"

/*
 ** getting the stack from argv
*/

int	get_stack(char *str, t_stack **stack_a)
{
	int	i;
	int	start;
	char	*ptr;

	i = 0;
	start = 0;
	ptr = NULL;
	if (str)
	{
		while (str[i])
		{
			if (ft_isdigit(str[i]) == 1)
			{
				start = i;
				while (ft_isdigit(str[i]) == 1)
				{
					i++;
					if (ft_isdigit(str[i]) == 0)
					{
						ptr = ft_substr(str, start, i - start);
						ft_lstadd_front_stack(stack_a, ft_lstnew_stack(ft_atoi(ptr)));
						free(ptr);
					}
				}
				i--;
			}
			i++;
		}
	}
	if (ptr != NULL)
		free(ptr);
	return (0);
}

/*
 ** main program push_swap
*/

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;
	int	i;

	stack_a = ft_lstnew_stack(0);
	stack_b = ft_lstnew_stack(0);
	i = i;
	while (argc > i)
	{
		get_stack(argv[i], &stack_a);
		i++;
	}
	while (stack_a->next != NULL)
	{
		printf("number=%d\n", stack_a->number);
		stack_a = stack_a->next;
	}
	return (0);
}
