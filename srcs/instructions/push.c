/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:01:33 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/25 14:31:26 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	goto_head(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a)
		while ((*stack_a)->head != NULL)
			*stack_a = (*stack_a)->head;
	if (*stack_b)
		while ((*stack_b)->head != NULL)
			*stack_b = (*stack_b)->head;
}

int	push_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*keep;
	int	atoi;

	if (stack_b == NULL || *stack_b == NULL || stack_a == NULL)
		return (-1);
	goto_head(stack_a, stack_b);
	atoi = (*stack_b)->number;
	ft_lstadd_front_stack(stack_a, ft_lstnew_stack((int)atoi));
	if ((*stack_b)->next != NULL)
	{
		keep = (*stack_b);
		*stack_b = (*stack_b)->next;
		if ((*stack_b)->head != NULL)
		{
			ft_lstdelone_stack(keep);
			(*stack_b)->head = NULL;
		}
	}
	else
	{
		ft_lstdelone_stack(*stack_b);
		*stack_b = NULL;
	}
	return (1);
}

int	push_pb(t_stack **stack_a, t_stack **stack_b)
{
	int	atoi;

	if (stack_a == NULL || *stack_a == NULL || stack_b == NULL)
		return (-1);
	goto_head(stack_a, stack_b);
	atoi = (*stack_a)->number;
	ft_lstadd_front_stack(stack_b, ft_lstnew_stack((int)atoi));
	if ((*stack_a)->next != NULL)
	{
		*stack_a = (*stack_a)->next;
		if ((*stack_a)->head != NULL)
		{
			ft_lstdelone_stack((*stack_a)->head);
			(*stack_a)->head = NULL;
		}
	}
	else
	{
		ft_lstdelone_stack(*stack_a);
		*stack_a = NULL;
	}
	return (1);
}
