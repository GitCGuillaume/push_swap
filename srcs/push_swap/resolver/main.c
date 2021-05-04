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

t_stack	*get_smallest(t_stack **stack)
{
	t_stack	*smallest;

	smallest = NULL;
	if (*stack)
	{
		smallest = *stack;
		while (*stack != NULL)
		{
			if ((*stack)->number < smallest->number)
				smallest = *stack;
			stack = &(*stack)->next;
		}
	}
	return (smallest);
}

int	get_smallest_median(t_stack **stack, int median)
{
	int	find;
	int	size;
	int	first;
	int	second;

	find = 0;
	size = 0;
	first = 0;
	second = 0;
	if (stack && *stack)
	{
		while (*stack != NULL && find == 0)
		{
			if (median > (*stack)->number)
			{
				find = 1;
				first = size;
			}
			size++;
			stack = &(*stack)->next;
		}
/*		while (*stack != NULL)
		{
			if (median > (*stack)->number)
			{
				second = size;
			}
			size++;
			stack = &(*stack)->next;
		}*/
	}
	//printf("first=%d last=%d size=%d size/2=%d  size - first=%d size - second=%d", first, second, size, size / 2, size - first, size - second);
	//printf("\n");
/*	if (first > size - second)
	{
		return (second);
	}
	else
	{
		return (first);
	}*/
	return (first);
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

void	stack_a_order(t_stack **stack_a, t_stack **stack_b, t_stack **median)
{
	if (stack_a && *stack_a)
	{
		if ((*stack_a)->next != NULL)
		{
			//(void)stack_b;
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

int	get_bigger_than(t_stack **stack_a, int value)
{
	int	element;
	int	find;

	element = 0;
	find = 0;
	if (stack_a && *stack_a)
	{
		if (find == 0)
			element = (*stack_a)->number;
		while (*stack_a)
		{
			if ((*stack_a)->number > value)
			{
				if (find == 0)
				{
					element = (*stack_a)->number;
					find = 1;
				}
				if (element > (*stack_a)->number)
					element = (*stack_a)->number;
			}
			stack_a = &(*stack_a)->next;
		}
	}
	return (element);
}
/*
void	stack_a_order(t_stack **stack_a, t_stack **stack_b, t_stack **median)
{
	int	size;
	int	size_b;
	int	size_c;
	int	max_a;
	int	max_b;
	t_stack	*head;
	t_stack	*last;
	t_stack	*biggest;

	size = 0;
	size_b = 0;
	size_c = 0;
	if (stack_a && *stack_a)
	{	
		head = *stack_a;
		last = ft_lstlast_stack(*stack_a);
		if ((*stack_a)->next != NULL)
		{
			max_a = get_bigger_than(stack_a, (*stack_a)->number);
			size = rotation_move(stack_a, max_a);
			size--;
	//		printf("current=%d next=%d max_a=%d size=%d\n", (*stack_a)->number, (*stack_a)->next->number, max_a, size);
			//if ((*stack_a)->number==44)
			//	exit(0);
			if (stack_b && *stack_b)
			{
				biggest = get_biggest(stack_b);
				size_c = rotation_move(stack_b, biggest->number);
				size_c--;
		//		printf("current_b=%d size_c=%d biggest=%d\n", (*stack_b)->number, size_c, biggest->number);
				if (size_c == 1)
				{
				//printf("current_b=%d size_c=%d biggest=%d\n", (*stack_b)->number, size_c, biggest->number);
					swap_sb(stack_b);
					ft_putstr_fd("sb\n", 1);
					biggest = get_biggest(stack_b);
		//		printf("current_b=%d size_c=%d biggest=%d\n", (*stack_b)->number, size_c, biggest->number);
				}
				else
				{
					max_b = ft_lstsize_stack(*stack_b);
					while (size_c > 0 && max_b > size_c)
					{
						if (max_b / 2 > size)
						{
							rotate_rb(stack_b);
							ft_putstr_fd("rb\n", 1);
							size_c--;
						}
						else
						{
							rotate_rrb(stack_b);
							ft_putstr_fd("rrb\n", 1);
							size_c++;
						}
					}
					biggest = get_biggest(stack_b);
				}
				//printf("current_b=%d biggest=%d\n", (*stack_b)->number, biggest->number);
				max_b = get_bigger_than(stack_a, biggest->number);
			//	printf("max_b=%d\n", max_b);
				size_b = rotation_move(stack_a, max_b);
				size_b--;
			//	printf("size_b=%d\n", size_b);
			//	printf("size_b - size = %d\n", size_b - size);
			}
			if (max_a == (*stack_a)->number)
			{
				rotate_rra(stack_a, median);
				ft_putstr_fd("rra\n", 1);
			}
			else if (stack_b && *stack_b && size_b == 0)
			{
			//	printf("to_pa=%dcurrent=%d max_b=%d, size_b=%d size=%d size_b=%d", (*stack_b)->number, (*stack_b)->number, max_b, size_b, size, size_b);
				push_pa(stack_a, stack_b);
				ft_putstr_fd("pa\n", 1);
			}
			else if (size != 1 && size != ft_lstsize_stack(*stack_a))
			{
			//	printf("current=%d next=%d max_a=%d size=%d\n", (*stack_a)->number, (*stack_a)->next->number, max_a, size);
			//	printf("to_pb=%d", (*stack_a)->number);
				push_pb(stack_a, stack_b);
				ft_putstr_fd("pb\n", 1);
<<<<<<*/				/*printf("\nstack_a\n");
				display(*stack_a);
				printf("\nstack_b\n");
				display(*stack_b);
				exit(0);
			*/	/*if (stack_b && *stack_b)
				{
					biggest = get_biggest(stack_b);
					size = rotation_move(stack_b, biggest->number);
					size--;
					if (size == 1)
					{
						swap_sb(stack_b);
						ft_putstr_fd("sb\n", 1);
					}
					else
					{
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
					}
				}*/
/*			}
			else
			{
<<<<<<<<<<<*/				/*if (stack_b && *stack_b)
				{
					max_b = get_bigger_than(stack_a, (*stack_b)->number);
					size = rotation_move(stack_a, max_b);
					if (size == -1)
					{
						if (stack_b && *stack_b)
						{
							push_pa(stack_a, stack_b);
							ft_putstr_fd("pa\n", 1);
						}
					}
					else
					{
						rotate_rra(stack_a, median);
						ft_putstr_fd("rra\n", 1);
					}
				}
				else
				{*/
	//				rotate_rra(stack_a, median);
	//				ft_putstr_fd("rra\n", 1);
				//}
	/*		}
		}
	}
}*/

int	has_bigger(t_stack **stack, int number)
{
	if (stack && *stack)
	{
		while (*stack)
		{
			if ((*stack)->number > number)
				return (1);
			stack = &(*stack)->next;
		}
	}
	return (0);
}

t_stack	*get_middle_value(t_stack **stack_b, int size)
{
	int	i;
	t_stack	*stack_cpy;

	i = 0;
	if (stack_b && *stack_b)
	{
		while (*stack_b != NULL && size >= i)
		{
			if (i == size)
				return (stack_cpy = *stack_b);
			i++;
			stack_b = &(*stack_b)->next;
		}
	}
	return (NULL);
}

void	must_push_pb(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max;
	t_stack	*value;
	t_stack *head;
	t_stack	*tail;
t_stack	*median;

	ft_putstr_fd("pb\n", 1);
	push_pb(stack_a, stack_b);
	//(*stack_b)->is_median = 0;
	head = *stack_b;
	//head->is_median = 0;
	size = ft_lstsize_stack(*stack_b);
	value = get_middle_value(stack_b, size / 2);
	if (copy_stack(*stack_b) == -1)
	{
		error();
		ft_lstclear_stack(stack_b);
		exit(EXIT_FAILURE);
	}
	tail = ft_lstlast_stack(*stack_b);
	median = get_median_location(stack_b);
	if (median == NULL)
	{
		error();
		ft_lstclear_stack(stack_b);
		exit(EXIT_FAILURE);
	}
	head = *stack_b;
	//size = get_smallest_median(stack_b, median->number);
	//size--;	
//	max = ft_lstsize_stack(*stack_b);
	if (head->next)
	{
		if (median->number > head->number)
		{
			rotate_rb(stack_b);
			ft_putstr_fd("rb\n", 1);
		}
	/*	else if (head->number * 2 > median->number && head->number < head->next->number)
		{
			rotate_rb(stack_b);
			ft_putstr_fd("rb\n", 1);
		}*/
	}
	/*
	else
	{*/
	//}
	median->is_median = 0;
	(void)max;

/*if ((*stack_a)->number > head->number)
	{
		ft_putstr_fd("pb\n", 1);
		push_pb(stack_a, stack_b);
	}
	else if ((*stack_a)->number > tail->number)
	{
		rotate_rrb(stack_b);
		push_pb(stack_a, stack_b);
		ft_putstr_fd("rrb\npb\n", 1);
	}
	else*/ /*if (size == 1)
	{
		value = get_biggest(stack_b);
		size = rotation_move(stack_b, value->number);
		size--;
		max= ft_lstsize_stack(*stack_b);
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
		if (size == 0 || size > max)
		{
			ft_putstr_fd("pb\n", 1);
			push_pb(stack_a, stack_b);
			(*stack_b)->is_median = 0;
		}
	}
	else
	{
		ft_putstr_fd("pb\n", 1);
		push_pb(stack_a, stack_b);
	}*/
}

void	sort_stack_a(t_stack **stack_a, t_stack **stack_b, t_stack **median)
{
	int	size;
	int	max;
	t_stack	*head;

	size = get_smallest_median(stack_a, (*median)->number);
	size--;
	max = ft_lstsize_stack(*stack_a);
	head = *stack_a;
	if (stack_a && *stack_a)
	{
		//while (size > 0 && max > size)
		//{
		//printf("size=%dmax=%d\n", size, max);
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
	if (size == 0 || size > max)
	{
		ft_putstr_fd("pa\n", 1);
		push_pa(stack_a, stack_b);
	}
}

int	resolver(t_stack **stack_a)
{
	int	result;
	t_stack *stack_b;
	t_stack	*median;

	//t_stack	*head;
	stack_b = NULL;
	median = NULL;
	if (stack_a && *stack_a)
	{
		result = list_sorted(stack_a, ft_lstsize_stack(*stack_a));
		if (result == 1)
			exit(0);
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
	//	display(stack_b);exit(0);
		result = list_sorted(stack_a, ft_lstsize_stack(*stack_a));
		while (result == 0)
		{
			stack_a_order(stack_a, &stack_b, &median);
			result = list_sorted(stack_a, ft_lstsize_stack(*stack_a));
		}
		while (stack_b != NULL)
			sort_stack_b(stack_a, &stack_b);
	}
	//printf("\ndisplay_b\n");
	ft_lstclear_stack(&stack_b);
	return (0);
}
