#include "../../includes/push_swap.h"

int	rotate_ra(t_stack **stack_a, t_stack **median)
{
	if (stack_a && *stack_a != NULL)
	{
		while ((*stack_a)->head != NULL)
			stack_a = &(*stack_a)->head;
		while (*stack_a != NULL)
		{
			if ((*stack_a)->next != NULL)
			{
				ft_swap(&(*stack_a)->number, &(*stack_a)->next->number);
				ft_swap(&(*stack_a)->is_median, &(*stack_a)->next->is_median);
				if (median && *median)
				{
					if ((*median)->next != NULL)
						*median = (*median)->next;
					else
					{
						while ((*median)->head != NULL)
							*median = (*median)->head;
					}
				}
			}
			stack_a = &(*stack_a)->next;
		}
	}
	return (1);
}

int	rotate_rb(t_stack **stack_b)
{
	if (stack_b && *stack_b)
	{
		while ((*stack_b)->head != NULL)
			stack_b = &(*stack_b)->head;
		while (*stack_b != NULL)
		{
			if ((*stack_b)->next != NULL)
			{
				ft_swap(&(*stack_b)->number, &(*stack_b)->next->number);
				ft_swap(&(*stack_b)->is_median, &(*stack_b)->next->is_median);
			}
			stack_b = &(*stack_b)->next;
		}
	}
	return (1);
}

int	rotate_rra(t_stack **stack_a, t_stack **median)
{
	if (stack_a && *stack_a)
	{
		while ((*stack_a)->next != NULL)
			stack_a = &(*stack_a)->next;
		while (*stack_a != NULL)
		{
			if ((*stack_a)->head != NULL)
			{
				ft_swap(&(*stack_a)->number, &(*stack_a)->head->number);
				ft_swap(&(*stack_a)->is_median, &(*stack_a)->head->is_median);
				if (median && *median)
				{
					if ((*median)->head != NULL)
						*median = (*median)->head;
					else
					{
						while ((*median)->next != NULL)
							*median = (*median)->next;
					}
				}
			}
			stack_a = &(*stack_a)->head;
		}
	}
	return (1);
}

int	rotate_rrb(t_stack **stack_b)
{
	if (stack_b && *stack_b)
	{
		while ((*stack_b)->next != NULL)
			stack_b = &(*stack_b)->next;
		while (*stack_b != NULL)
		{
			if ((*stack_b)->head != NULL)
				ft_swap(&(*stack_b)->number, &(*stack_b)->head->number);
			stack_b = &(*stack_b)->head;
		}
	}
	return (1);
}
