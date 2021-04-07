#include "../../includes/push_swap.h"

int	rotate_ra(t_stack **stack_a)
{
	while ((*stack_a)->head != NULL)
		stack_a = &(*stack_a)->head;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->next != NULL)
			ft_swap(&(*stack_a)->number, &(*stack_a)->next->number);
		stack_a = &(*stack_a)->next;
	}
	return (1);
}

int	rotate_rb(t_stack **stack_b)
{
	while ((*stack_b)->head != NULL)
		stack_b = &(*stack_b)->head;
	while (*stack_b != NULL)
	{
		if ((*stack_b)->next != NULL)
			ft_swap(&(*stack_b)->number, &(*stack_b)->next->number);
		stack_b = &(*stack_b)->next;
	}
	return (1);
}

int	rotate_rra(t_stack **stack_a)
{
	while ((*stack_a)->next != NULL)
		stack_a = &(*stack_a)->next;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->head != NULL)
			ft_swap(&(*stack_a)->number, &(*stack_a)->head->number);
		stack_a = &(*stack_a)->head;
	}
	return (1);
}

int	rotate_rrb(t_stack **stack_b)
{
	while ((*stack_b)->next != NULL)
		stack_b = &(*stack_b)->next;
	while (*stack_b != NULL)
	{
		if ((*stack_b)->head != NULL)
			ft_swap(&(*stack_b)->number, &(*stack_b)->head->number);
		stack_b = &(*stack_b)->head;
	}
	return (1);
}
