#include "../../includes/push_swap.h"

int	push_pa(t_stack **stack_a, t_stack **stack_b)
{
	ssize_t	atoi;
	t_stack	*keep;

	if (stack_b == NULL || *stack_b == NULL || stack_a == NULL)
		return (-1);
	if (*stack_a)
	{
		while ((*stack_a)->head != NULL)
			*stack_a = (*stack_a)->head;
	}
	if (*stack_b)
	{
		while ((*stack_b)->head != NULL)
			*stack_b = (*stack_b)->head;
	}
	atoi = (*stack_b)->number;
	ft_lstadd_front_stack(stack_a, ft_lstnew_stack((int)atoi));
	if ((*stack_b)->next != NULL)
	{
		keep = (*stack_b);
		*stack_b = (*stack_b)->next;
		if ((*stack_b)->head != NULL)
		{
			ft_lstdelone_stack(keep);
			(*stack_b)->head = NULL;
		}
	}
	else
	{
		ft_lstdelone_stack(*stack_b);
		*stack_b = NULL;
	}
	return (1);
}

int	push_pb(t_stack **stack_a, t_stack **stack_b)
{
	ssize_t	atoi;

	if (stack_a == NULL || *stack_a == NULL || stack_b == NULL)
		return (-1);
	if (*stack_a)
	{
		while ((*stack_a)->head != NULL)
			*stack_a = (*stack_a)->head;
	}
	if (*stack_b)
	{
		while ((*stack_b)->head != NULL)
			*stack_b = (*stack_b)->head;
	}
	atoi = (*stack_a)->number;
	ft_lstadd_front_stack(stack_b, ft_lstnew_stack((int)atoi));
	if ((*stack_a)->next != NULL)
	{
		*stack_a = (*stack_a)->next;
		if ((*stack_a)->head != NULL)
		{
			ft_lstdelone_stack((*stack_a)->head);
			(*stack_a)->head = NULL;
		}
	}
	else
	{
		ft_lstdelone_stack(*stack_a);
		*stack_a = NULL;
	}
	return (1);
}
