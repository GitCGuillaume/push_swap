#include "push_swap.h"

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
	if (*stack)
	{
		while (*stack != NULL)
		{
			if (median > (*stack)->number)
			{
				return (size);
			}
			size++;
			stack = &(*stack)->next;
		}
	}
	return (median);
}

int	rotation_move(t_stack **stack, int biggest)
{
	int	size;

	size = 0;
	while (*stack != NULL)
	{
		size++;
		if ((*stack)->number == biggest)
			return (size);
		stack = &(*stack)->next;
	}
	return (-1);
}

t_stack	*get_median_location(t_stack **stack)
{
	t_stack	*median;

	median = NULL;
	if (stack)
	{
		while (stack != NULL && median == NULL)
		{
			if ((*stack)->is_median == 1)
				return (median = *stack);
			stack = &(*stack)->next;
		}
	}
	return (median);
}

int	median_smallest(t_stack **stack, int median)
{
	if (stack)
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

int	list_sorted(t_stack **stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack == NULL)
		return (-1);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (*stack != NULL)
			{
				if ((*stack)->next != NULL)
				{
					if ((*stack)->number > (*stack)->next->number)
						return (0);
				}
				stack = &(*stack)->next;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	stack_a_order(t_stack **stack_a, t_stack **median)
{
	if (stack_a && *stack_a)
	{
		if ((*stack_a)->next != NULL)
		{
			if ((*stack_a)->number > (*stack_a)->next->number)
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

void	sort_stack_a(t_stack **stack_a, t_stack **stack_b, t_stack **median)
{
	int	size;
	int	max;
	t_stack	*head;

	size = get_smallest_median(stack_a, (*median)->number);
	size--;
	max = ft_lstsize_stack(*stack_b);
	head = *stack_a;
	if (stack_a && *stack_a)
	{
		//while (size > 0 && max > size)
		//{
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
		{
			ft_putstr_fd("pb\n", 1);
			push_pb(stack_a, stack_b);
		}
		/*if ((*median)->number > head->number)
		{
			ft_putstr_fd("pb\n", 1);
			push_pb(stack_a, stack_b);
		}*/
		/*if (head->number > (*median)->number)
		{
			ft_putstr_fd("ra\n", 1);
			rotate_ra(stack_a, median);
		}
		else if ((*median)->number > head->number)
		{
			//ft_putstr_fd("pb\n", 1);
			printf("pb\n");
			push_pb(stack_a, stack_b);
		}
		else if (*median == head)
		{
			ft_putstr_fd("ra\n", 1);
			rotate_ra(stack_a, median);
		}*/
	}
}

void	sort_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max;
	t_stack	*biggest;

	biggest = get_biggest(stack_b);
	size = rotation_move(stack_b, biggest->number);
	size--;
	max = ft_lstsize_stack(*stack_b);
	while (size > 0 && max > size)
	{
		if (max / 2 > size)
		{
			rotate_rb(stack_b);
			ft_putstr_fd("rb\n", 1);
			size--;
		}
		else
		{
			rotate_rrb(stack_b);
			ft_putstr_fd("rrb\n", 1);
			size++;
		}
	}
	ft_putstr_fd("pa\n", 1);
	push_pa(stack_a, stack_b);
}

int	resolver(t_stack **stack_a)
{
	t_stack *stack_b;
	t_stack	*median;
	int	result;

	//t_stack	*head;
	stack_b = NULL;
	median = NULL;
	if (stack_a && *stack_a)
	{
		while (ft_lstsize_stack(*stack_a) > 3)
		{
			if (median != NULL)
				median->is_median = 0;
			if (copy_stack(*stack_a) == -1)
			{
				error();
				ft_lstclear_stack(stack_a);
				exit(EXIT_FAILURE);
			}
			median = get_median_location(stack_a);
			while (median_smallest(stack_a, median->number) == 0)
				sort_stack_a(stack_a, &stack_b, &median);
		}
		result = list_sorted(stack_a, ft_lstsize_stack(*stack_a));
		while (result == 0)
		{
			stack_a_order(stack_a, &median);
			result = list_sorted(stack_a, ft_lstsize_stack(*stack_a));
		}
		while (stack_b != NULL)
			sort_stack_b(stack_a, &stack_b);
	}
	display(stack_b);
	ft_lstclear_stack(&stack_b);
	return (0);
}
