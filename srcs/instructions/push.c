#include "../../includes/push_swap.h"

int	push_pa(t_stack **stack_a, t_stack **stack_b)
{
	ssize_t	atoi;

	if (ft_lstsize_stack(*stack_b) == 0)
		return (0);
	if (*stack_a == NULL)
		return (1);
	while ((*stack_a)->head != NULL)
		stack_a = &(*stack_a)->head;
	while ((*stack_b)->head != NULL)
		stack_b = &(*stack_b)->head;
	atoi = (*stack_b)->number;
	ft_lstadd_front_stack(&(*stack_a), ft_lstnew_stack((int)atoi), 1 + (*stack_a)->position);
	if ((*stack_b)->next != NULL)
	{
		*stack_b = (*stack_b)->next;
		ft_lstdelone_stack((*stack_b)->head);
		(*stack_b)->head = NULL;
	}
	else
	{
		ft_lstdelone_stack((*stack_b));
		*stack_b = NULL;
	}
	return (1);
}

int	push_pb(t_stack **stack_a, t_stack **stack_b)
{
	ssize_t	atoi;

	if (*stack_a == NULL)
		return (0);
	if (*stack_b)
		return (1);
	while ((*stack_a)->head != NULL)
		stack_a = &(*stack_a)->head;
	if (*stack_b)
	{	
		while ((*stack_b)->head != NULL)
			stack_b = &(*stack_b)->head;
	}
	atoi = (*stack_a)->number;
	if (*stack_b == NULL)
		ft_lstadd_front_stack(&(*stack_b), ft_lstnew_stack((int)atoi), 1);
	else
		ft_lstadd_front_stack(&(*stack_b), ft_lstnew_stack((int)atoi), 1 + (*stack_b)->position);
	if ((*stack_a)->next != NULL)
	{
		*stack_a = (*stack_a)->next;
		ft_lstdelone_stack((*stack_a)->head);
		(*stack_a)->head = NULL;
	}
	else
	{
		ft_lstdelone_stack((*stack_a)->head);
		*stack_a = NULL;
	}
	return (1);
}
