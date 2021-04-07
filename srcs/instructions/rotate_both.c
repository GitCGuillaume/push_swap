#include "../../includes/push_swap.h"

int	rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_ra(stack_a);
	rotate_rb(stack_b);
	return (1);
}

int	rotate_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_rra(stack_a);
	rotate_rrb(stack_b);
	return (1);
}
