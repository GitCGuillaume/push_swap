/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:01:10 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/26 13:17:18 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * * Check duplicate values
*/

int	check_duplicate(t_stack *stack)
{
	int		value;
	size_t	position;

	value = stack->number;
	position = stack->position;
	if (!stack)
		return (-1);
	while (stack != NULL)
	{
		if (position != stack->position)
			if (value == stack->number)
				return (-1);
		stack = stack->next;
	}
	return (1);
}

int	loop_duplicate(t_stack *stack_a)
{
	int	get_stack_ok;

	get_stack_ok = 0;
	if (stack_a == NULL)
		return (-1);
	while (stack_a != NULL)
	{
		get_stack_ok = check_duplicate(stack_a);
		if (get_stack_ok == -1)
		{
			return (-1);
		}
		stack_a = stack_a->next;
	}
	return (1);
}
