#include "../../includes/push_swap.h"

int	swap_sa(t_stack **stack_a)
{
	int	old_a;
	int	old_b;

	old_a = (*stack_a)->number;
	old_b = (*stack_a)->next->number;
	ft_swap(&(*stack_a)->number, &(*stack_a)->next->number);
	if (old_a == (*stack_a)->number || old_b == (*stack_a)->next->number)
		return (0);
	return (1);
}

int	swap_sb(t_stack **stack_b)
{
	int	old_a;
	int	old_b;

	old_a = (*stack_b)->number;
	old_b = (*stack_b)->next->number;
	ft_swap(&(*stack_b)->number, &(*stack_b)->next->number);
	if (old_a == (*stack_b)->number || old_b == (*stack_b)->next->number)
		return (0);
	return (1);
}


int	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	int	sa;
	int	sb;

	sa = swap_sa(stack_a);
	sb = swap_sb(stack_b);
	if (sa == 0 || sb == 0)
		return (0);
	return (1);
}
