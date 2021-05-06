#include "push_swap.h"

#include <stdio.h>
t_stack	*get_biggest(t_stack **stack)
{
	t_stack	*biggest;

	biggest = NULL;
	if (*stack)
	{
		biggest = *stack;
		while (*stack != NULL)
		{
			if ((*stack)->number > biggest->number)
				biggest = *stack;
			stack = &(*stack)->next;
		}
	}
	return (biggest);
}

int	get_smallest_median(t_stack **stack, int median)
{
	int	size;

	size = 0;
	if (stack && *stack)
	{
		while (*stack != NULL)
		{
			if (median > (*stack)->number)
			{
				return(size);
			}
			size++;
			stack = &(*stack)->next;
		}
	}
	return (size);
}
int	rotation_move(t_stack **stack, int value)
{
	int	size;

	size = 0;
	if (stack && *stack)
	{
		while (*stack != NULL)
		{
			size++;
			if ((*stack)->number == value)
				return (size);
			stack = &(*stack)->next;
		}
	}
	return (-1);
}

t_stack	*get_median_location(t_stack **stack)
{
	t_stack	*median;

	median = NULL;
	if (stack && *stack)
	{
		while (*stack != NULL)
		{
			if ((*stack)->is_median == 1)
				return (median = *stack);
			stack = &(*stack)->next;
		}
	}
	return (NULL);
}

int	median_smallest(t_stack **stack, int median)
{
	if (stack && *stack)
	{
		while ((*stack)->head != NULL)
			stack = &(*stack)->head;
		while (*stack)
		{
			if (median > (*stack)->number)
				return (0);
			stack = &(*stack)->next;
		}
	}
	return (1);
}

void	stack_a_order(t_stack **stack_a, t_stack **stack_b, t_stack **median)
{
	if (stack_a && *stack_a)
	{
		if ((*stack_a)->next != NULL)
		{
			if (stack_b && *stack_b && (*stack_b)->next
					&& (*stack_a)->number > (*stack_a)->next->number
					&& (*stack_b)->number < (*stack_b)->next->number)
			{
				swap_ss(stack_a, stack_b, median);
				ft_putstr_fd("ss\n", 1);
			}
			else if ((*stack_a)->number > (*stack_a)->next->number)
			{
				swap_sa(stack_a, median);
				ft_putstr_fd("sa\n", 1);
			}
			else
			{
				rotate_rra(stack_a, median);
				ft_putstr_fd("rra\n", 1);
			}
		}
	}
}

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
	{
		clear_stack_b(stack_a, stack_b);
	}
	median = get_median_location(stack_b);
	if (median == NULL)
	{
		clear_stack_b(stack_a, stack_b);
	}
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

void	rotate_stack(t_stack **stack, int max, int *size)
{
	while (*size > 0 && max > *size)
	{
		if (max / 2 > *size)
		{
			rotate_rb(stack);
			ft_putstr_fd("rb\n", 1);
			(*size)--;
		}
		else
		{
			rotate_rrb(stack);
			ft_putstr_fd("rrb\n", 1);
			(*size)++;
		}
	}

}

void	sort_stack_a(t_stack **stack_a, t_stack **stack_b, t_stack **median, int size)
{
	int	max;

	size--;
	max = ft_lstsize_stack(*stack_a);
	if (stack_a && *stack_a)
	{
		if (size != -1)
		{
			if (max / 2 > size)
			{
				rotate_ra(stack_a, median);
				ft_putstr_fd("ra\n", 1);
				size--;
			}
			else
			{
				rotate_rra(stack_a, median);
				ft_putstr_fd("rra\n", 1);
				size++;
			}
		}
		if (size == -1)
			must_push_pb(stack_a, stack_b);
	}
}

void	sort_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max;

	size = rotation_move(stack_b, get_biggest(stack_b)->number);
	size--;
	max = ft_lstsize_stack(*stack_b);
	rotate_stack(stack_b, max, &size);
	if (size == 0 || size > max)
	{
		ft_putstr_fd("pa\n", 1);
		push_pa(stack_a, stack_b);
	}
}

void	sort_median(t_stack **stack_a, t_stack **stack_b, t_stack **median)
{
	int	size;
	int	result;

	size = ft_lstsize_stack(*stack_a);
	while (size > 3)
	{
		if (*median != NULL)
			(*median)->is_median = 0;
		result = copy_stack(*stack_a);
		if (result == -1)
		{
			error();
			ft_lstclear_stack(stack_a);
			ft_lstclear_stack(stack_b);
			exit(EXIT_FAILURE);
		}
		*median = get_median_location(stack_a);
		result = median_smallest(stack_a, (*median)->number);
		while (result == 0)
		{
			sort_stack_a(stack_a, stack_b, median,
					get_smallest_median(stack_a, (*median)->number));
			result = median_smallest(stack_a, (*median)->number);
		}
		size = ft_lstsize_stack(*stack_a);
	}
}

int	resolver(t_stack **stack_a)
{
	int	result;
	t_stack *stack_b;
	t_stack	*median;

	stack_b = NULL;
	median = NULL;
	if (stack_a && *stack_a)
	{
		result = list_sorted(stack_a, ft_lstsize_stack(*stack_a));
		if (result == 1)
			exit(0);
		sort_median(stack_a, &stack_b, &median);
		result = list_sorted(stack_a, ft_lstsize_stack(*stack_a));
		while (result == 0)
		{
			stack_a_order(stack_a, &stack_b, &median);
			result = list_sorted(stack_a, ft_lstsize_stack(*stack_a));
		}
		while (stack_b != NULL)
			sort_stack_b(stack_a, &stack_b);
	}
	ft_lstclear_stack(&stack_b);
	return (0);
}
