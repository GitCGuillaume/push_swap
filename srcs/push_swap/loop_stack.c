#include "push_swap.h"
#include <stdio.h>

void	display(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("number=%d\n", stack->number);
		//printf("current=%p", stack);
	//	printf("number head=%p", stack->head);
	//	printf("number next=%p", stack->next);
		//printf("position=%d\n", stack->position);
		printf("is_median=%d\n", stack->is_median);
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
				return (-1);
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
		if (get_stack_ok == -1)
		{
			error();
			return (-1);
		}
		stack_a = stack_a->next;
	}
	return (1);
}
