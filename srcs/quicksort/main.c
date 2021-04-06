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
					ft_lstadd_front_stack(stack_a, ft_lstnew_stack((int)atoi), 1 + (*stack_a)->position);
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
 * * Check duplicate values
*/
int	check_duplicate(t_stack stack)
{
	int	value;
	size_t	position;

	value = stack.number;
	position = stack.position;
	while (stack.head != NULL)
		stack = *stack.head;
	while (stack.next != NULL)
	{
		if (position != stack.position)
			if (value == stack.number)
				return (0);
		stack = *stack.next;
		printf("value=%d position=%zu\n", value, position);
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
	stack_a = ft_lstnew_stack(0);
	stack_b = ft_lstnew_stack(0);
	while (argc > i)
	{
		get_stack_ok = get_stack(argv[i], &stack_a);
		i++;
		if (get_stack_ok == 0)
			error_int_stack();
	}
	if (get_stack_ok == 0)
		error_int_stack();
	while (stack_a->next != NULL)
	{
		get_stack_ok = check_duplicate(*stack_a);
		if (get_stack_ok == 0)
			error_int_stack();
		stack_a = stack_a->next;
	}
	while (stack_a->head != NULL)
		stack_a = stack_a->head;
	while (stack_a->next != NULL)
	{
		printf("anumber=%d\n", stack_a->number);
		printf("position=%zu\n", stack_a->position);
		printf("next=%p\n", stack_a);
		stack_a = stack_a->next;
	}
	while (stack_a->head != NULL)
		stack_a = stack_a->head;
	ft_lstclear_stack(&stack_b);
	ft_lstclear_stack(&stack_a);
	return (0);
}
