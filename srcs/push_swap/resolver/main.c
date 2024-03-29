/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:03:20 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/26 15:21:31 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a_order(t_stack **stack_a, t_stack **stack_b, t_stack **median)
{
	if (!stack_a || !stack_a)
		error_stack(stack_a, stack_b, -1);
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
			swap_sa(stack_a, stack_b, median);
			ft_putstr_fd("sa\n", 1);
		}
		else
		{
			if (rotate_rra(stack_a, median) < 0)
				error_stack(stack_a, stack_b, -1);
			ft_putstr_fd("rra\n", 1);
		}
	}
}

void	sort_stack_a(t_stack **stack_a, t_stack **stack_b, t_stack **median)
{
	int	max;
	int	size;

	if (!stack_a || !*stack_a)
		error_stack(stack_a, stack_b, -1);
	size = get_smaller_value(stack_a, stack_b, median);
	size--;
	max = ft_lstsize_stack(*stack_a);
	if (size != -1)
	{
		if (max / 2 > size)
		{
			rotate_stack(stack_a, stack_b, median, "ra");
			ft_putstr_fd("ra\n", 1);
			size--;
		}
		else
		{
			rotate_stack(stack_a, stack_b, median, "rra");
			size++;
		}
	}
	if (size == -1)
		must_push_pb(stack_a, stack_b);
}

void	sort_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max;

	if (!stack_b || !*stack_b)
		error_stack(stack_a, stack_b, -1);
	size = rotation_move(stack_b, stack_a);
	size--;
	max = ft_lstsize_stack(*stack_b);
	sort_stack_b_two(stack_a, stack_b, &size, &max);
	if (size == 0 || size > max)
	{
		ft_putstr_fd("pa\n", 1);
		push_pa(stack_a, stack_b);
	}
}

void	sort_median(t_stack **stack_a, t_stack **stack_b, t_stack **median,
	int size)
{
	int	result;

	result = 0;
	if (median == NULL || stack_a == NULL || !stack_b)
		error_stack(stack_a, stack_b, -1);
	while (size > 3 && median && result == 0)
	{
		if (*median != NULL)
			(*median)->is_median = 0;
		result = copy_stack(*stack_a, 0);
		if (result == -1)
			error_stack(stack_a, stack_b, result);
		*median = get_median_location(stack_a, stack_b);
		result = median_smallest(stack_a, (*median)->number);
		error_stack(stack_a, stack_b, result);
		while (result == 0)
		{
			sort_stack_a(stack_a, stack_b, median);
			result = median_smallest(stack_a, (*median)->number);
		}
		size = ft_lstsize_stack(*stack_a);
		result = list_sorted(stack_a, ft_lstsize_stack(*stack_a));
	}
}

int	resolver(t_stack **stack_a)
{
	int		result;
	t_stack	*stack_b;
	t_stack	*median;

	stack_b = NULL;
	median = NULL;
	if (stack_a && *stack_a)
	{
		result = list_sorted(stack_a, ft_lstsize_stack(*stack_a));
		if (result == 1)
			return (0);
		sort_median(stack_a, &stack_b, &median, ft_lstsize_stack(*stack_a));
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
