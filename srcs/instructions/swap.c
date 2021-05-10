/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:02:25 by gchopin           #+#    #+#             */
/*   Updated: 2021/05/10 14:02:27 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_sa(t_stack **stack_a, t_stack **median)
{
	int	old_a;
	int	old_b;

	if (ft_lstsize_stack(*stack_a) <= 1)
		return (0);
	old_a = (*stack_a)->number;
	old_b = (*stack_a)->next->number;
	ft_swap(&(*stack_a)->number, &(*stack_a)->next->number);
	ft_swap(&(*stack_a)->is_median, &(*stack_a)->next->is_median);
	if (median && *median)
	{
		if ((*median)->next != NULL)
			*median = (*median)->next;
		else
		{
			while ((*median)->head != NULL)
				*median = (*median)->head;
		}
	}
	if (old_a == (*stack_a)->number || old_b == (*stack_a)->next->number)
		return (0);
	return (1);
}

int	swap_sb(t_stack **stack_b)
{
	int	old_a;
	int	old_b;

	if (ft_lstsize_stack(*stack_b) <= 1)
		return (0);
	old_a = (*stack_b)->number;
	old_b = (*stack_b)->next->number;
	ft_swap(&(*stack_b)->number, &(*stack_b)->next->number);
	if (old_a == (*stack_b)->number || old_b == (*stack_b)->next->number)
		return (0);
	return (1);
}

int	swap_ss(t_stack **stack_a, t_stack **stack_b, t_stack **median)
{
	int	sa;
	int	sb;

	sa = swap_sa(stack_a, median);
	sb = swap_sb(stack_b);
	if (sa == 0 || sb == 0)
		return (0);
	return (1);
}
