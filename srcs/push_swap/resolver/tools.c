/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:03:36 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/26 12:19:41 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_biggest(t_stack **stack, t_stack **stack_a)
{
	t_stack	*biggest;

	biggest = NULL;
	if (!stack || !*stack)
		error_stack(stack, stack_a, -1);
	if (*stack)
	{
		biggest = *stack;
		while (*stack != NULL)
		{
			if ((*stack)->number > biggest->number)
				biggest = *stack;
			stack = &(*stack)->next;
		}
		return (biggest->number);
	}
	return (0);
}

int	rotation_move(t_stack **stack, t_stack **stack_a)
{
	int	value;
	int	size;

	size = 0;
	if (!stack || !*stack)
		error_stack(stack, stack_a, -1);
	value = get_biggest(stack, stack_a);
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

int	get_smaller_value(t_stack **stack, t_stack **stack_b, t_stack **median)
{
	int	size;
	int	value;

	size = 0;
	if (!stack || !*stack || !median || !*median)
		error_stack(stack, stack_b, -1);
	value = (*median)->number;
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

/*
 ** Return a double ptr,
 ** need to update the median value to 0
 ** in quicksort median
*/

t_stack	*get_median_location(t_stack **stack, t_stack **stack_2)
{
	if (!stack || !*stack)
		error_stack(stack, stack_2, -1);
	if (stack && *stack)
	{
		while (*stack != NULL)
		{
			if ((*stack)->is_median == 1)
				return (*stack);
			stack = &(*stack)->next;
		}
	}
	return (NULL);
}

/*
 ** Sort median will loop until median smallest
 ** find that stack is not sorted
*/

int	median_smallest(t_stack **stack, int median)
{
	if (!stack)
		return (-1);
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
