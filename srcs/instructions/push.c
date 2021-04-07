#include "../../includes/push_swap.h"

int	push_pa(t_stack **stack_a, t_stack **stack_b)
{
	ssize_t	atoi;

	if ((*stack_b)->position == 0)
		return (0);
	while ((*stack_a)->head != NULL)
		stack_a = &(*stack_a)->head;
	while ((*stack_b)->head != NULL)
		stack_b = &(*stack_b)->head;
	atoi = (*stack_b)->number;
	ft_lstadd_front_stack(&(*stack_a), ft_lstnew_stack((int)atoi), 1 + (*stack_a)->position);
	*stack_b = (*stack_b)->next;
	ft_lstdelone_stack((*stack_b)->head);
	(*stack_b)->head = NULL;
	return (1);
}

int	push_pb(t_stack **stack_a, t_stack **stack_b)
{
	ssize_t	atoi;

	if ((*stack_a)->position == 0)
		return (0);
	while ((*stack_a)->head != NULL)
		stack_a = &(*stack_a)->head;
	while ((*stack_b)->head != NULL)
		stack_b = &(*stack_b)->head;
	atoi = (*stack_a)->number;
	ft_lstadd_front_stack(&(*stack_b), ft_lstnew_stack((int)atoi), 1 + (*stack_b)->position);
	*stack_a = (*stack_a)->next;
	ft_lstdelone_stack((*stack_a)->head);
	(*stack_a)->head = NULL;
	return (1);
}

