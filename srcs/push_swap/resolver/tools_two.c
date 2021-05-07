#include "push_swap.h"

void	clear_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	error();
	ft_lstclear_stack(stack_a);
	ft_lstclear_stack(stack_b);
	exit(EXIT_FAILURE);
}

void	must_push_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*median;

	ft_putstr_fd("pb\n", 1);
	push_pb(stack_a, stack_b);
	if (copy_stack(*stack_b) == -1)
		clear_stack_b(stack_a, stack_b);
	median = get_median_location(stack_b);
	if (median == NULL)
		clear_stack_b(stack_a, stack_b);
	if ((*stack_b)->next)
	{
		if (median->number > (*stack_b)->number)
		{
			rotate_rb(stack_b);
			ft_putstr_fd("rb\n", 1);
		}
	}
	median->is_median = 0;
}

void	rotate_stack(t_stack **stack_a, t_stack **stack_b,
		t_stack **median, char *str)
{
	int	result;

	result = ft_strcmp(str, "ra");
	if (result == 0)
		rotate_ra(stack_a, median);
	result = ft_strcmp(str, "rra");
	if (result == 0)
	{
		rotate_rra(stack_a, median);
		ft_putstr_fd("rra\n", 1);
	}
	result = ft_strcmp(str, "rb");
	if (result == 0)
	{
		rotate_rb(stack_b);
		ft_putstr_fd("rb\n", 1);
	}
	result = ft_strcmp(str, "rrb");
	if (result == 0)
	{
		rotate_rrb(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
}
