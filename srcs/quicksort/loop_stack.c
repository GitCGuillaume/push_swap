#include "../../includes/push_swap.h"
#include <stdio.h>
void	display(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("number=%d\n", stack->number);
		printf("position=%d\n", stack->position);
		stack = stack->next;
	}
}

/*
 * * Check duplicate values
*/
int	check_duplicate(t_stack *stack)
{
	int	value;
	size_t	position;

	value = stack->number;
	position = stack->position;
	while (stack != NULL)
	{
		if (position != stack->position)
			if (value == stack->number)
				return (0);
		stack = stack->next;
	}
	return (1);
}

int	loop_duplicate(t_stack *stack_a)
{
	int	get_stack_ok;

	get_stack_ok = 0;
	while (stack_a != NULL)
	{
		get_stack_ok = check_duplicate(stack_a);
		if (get_stack_ok == 0)
		{
			error();
			return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}
