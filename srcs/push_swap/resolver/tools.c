/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:03:36 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/23 16:21:22 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_smaller_value(t_stack **stack, int value)
{
	int	size;

	size = 0;
	if (stack && *stack)
	{
		while (*stack != NULL)
		{
			if (value > (*stack)->number)
				return (size);
			size++;
			stack = &(*stack)->next;
		}
	}
	return (size);
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
