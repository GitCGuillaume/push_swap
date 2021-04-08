#include <stdio.h>
#include "../../includes/push_swap.h"
#include "../libft/libft.h"

void	copy_stack(t_stack *stack_a)
{
	t_stack *lst_cpy;

	while (stack_a != NULL)
	{
		ft_lstadd_back_stack(&lst_cpy, ft_lstnew_stack(stack_a->number), stack_a->position);
		stack_a = stack_a->next;
	}
	quicksort_main(lst_cpy);
	//display(lst_cpy);
	free(lst_cpy);
}

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
			if (((ft_isdigit(str[i]) == 0 && str[i] != '-') && str[i] != '\0'))
				return (0);
			else
			{
				start = i;
				if (str[i] == '-')
					i++;
				if (ft_isdigit(str[i]) == 0)
					return (0);
				while (str[i] && ft_isdigit(str[i]) == 1)
					i++;
				if (ft_isdigit(str[i]) == 0)
				{
					ptr = ft_substr(str, start, i - start);
					atoi = ft_atoi(ptr);
					free(ptr);
					if (atoi < -2147483648 || atoi > 2147483647)
						return (0);
					if (*stack_a != NULL)
						ft_lstadd_front_stack(stack_a, ft_lstnew_stack((int)atoi), 1 + (*stack_a)->position);
					else
					{
						ft_lstadd_front_stack(stack_a, ft_lstnew_stack((int)atoi), 1);
					}
					start = 0;
				}
				if (str[i] != '\0' && str[i] != ' ')
					return (0);
			}
		}
	}
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

	i = 1;
	get_stack_ok = 0;
	if (argc < 2)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	while (argc > i)
	{
		get_stack_ok = get_stack(argv[i], &stack_a);
		i++;
		if (get_stack_ok == 0)
		{
			error();
			ft_lstclear_stack(&stack_a);
			ft_lstclear_stack(&stack_b);
			exit(EXIT_FAILURE);
		}
	}
	if (get_stack_ok == 0)
		error_int_stack();
	get_stack_ok = loop_duplicate(stack_a);
	if (get_stack_ok == 0)
	{
		ft_lstclear_stack(&stack_a);
		ft_lstclear_stack(&stack_b);
		exit(EXIT_FAILURE);
	}
	/*rotate_rb(&stack_a);
	push_pb(&stack_a, &stack_b);
	push_pb(&stack_a, &stack_b);
	rotate_ra(&stack_a);
	swap_sa(&stack_a);
	push_pb(&stack_a, &stack_b);
	rotate_rra(&stack_a);
	push_pa(&stack_a, &stack_b);
	rotate_rrb(&stack_b);
	swap_sa(&stack_a);
	push_pa(&stack_a, &stack_b);
	rotate_rb(&stack_b);
	push_pa(&stack_a, &stack_b);
	*/
	//test(*stack_a);
	//swap_sa(&stack_a);
	//copy_stack(stack_a);
	//printf("-----------------------\n");
	rotate_rra(&stack_a);
	push_pb(&stack_a, &stack_b);
	rotate_ra(&stack_a);
	push_pa(&stack_a, &stack_b);
	display(stack_a);
	printf("-----------------------\n");
	display(stack_b);
	ft_lstclear_stack(&stack_a);
	ft_lstclear_stack(&stack_b);
	return (0);
}
