/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:01:40 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/25 10:00:02 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_rr(t_stack **stack_a, t_stack **stack_b, t_stack **median)
{
	if (!rotate_ra(stack_a, median))
		return (0);
	if (!rotate_rb(stack_b))
		return (0);
	return (1);
}

int	rotate_rrr(t_stack **stack_a, t_stack **stack_b, t_stack **median)
{
	if (!rotate_rra(stack_a, median))
		return (0);
	if (!rotate_rrb(stack_b))
		return (0);
	return (1);
}
