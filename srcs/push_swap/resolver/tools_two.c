/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:03:52 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/24 18:10:29 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_median_to_zero(t_stack **stack)
{
	if (stack)
	{
		while (*stack)
		{
			if ((*stack)->is_median == 1)
			{
				(*stack)->is_median = 0;
				return ;
			}
			stack = &(*stack)->next;
		}
	}
}
/*
#include <stdio.h>
void printf_stack(t_stack **stack)
{
	while (*stack != NULL)
	{
		printf("median=%d\n", (*stack)->is_median);
		stack = &(*stack)->next;
	}
}*/

void	must_push_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*median;

	if (stack_a && stack_b)
	{
		ft_putstr_fd("pb\n", 1);
		push_pb(stack_a, stack_b);
	}
	set_median_to_zero(stack_b);
	if (stack_b && copy_stack(*stack_b, 1) == -1)
		error_stack(stack_a, stack_b, -1);
	median = get_median_location(stack_b);
	if (median == NULL)
		error_stack(stack_a, stack_b, -1);
	if (stack_b && (*stack_b)->next)
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
