/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:44:46 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/22 09:24:15 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"

/*
 ** execute x_a stack
*/

static void	execute_a(t_stack **stack_a, t_stack **stack_b, char *str)
{
	int	result;

	result = compare_strings(str, "sa");
	if (result == 1)
		swap_sa(stack_a, NULL);
	result = compare_strings(str, "pa");
	if (result == 1)
		push_pa(stack_a, stack_b);
	result = compare_strings(str, "ra");
	if (result == 1)
		rotate_ra(stack_a, 0);
	result = compare_strings(str, "rra");
	if (result == 1)
		rotate_rra(stack_a, 0);
}

/*
 ** execute x_b stack
*/

static void	execute_b(t_stack **stack_a, t_stack **stack_b, char *str)
{
	int	result;

	result = compare_strings(str, "sb");
	if (result == 1)
		swap_sb(stack_b);
	result = compare_strings(str, "pb");
	if (result == 1)
		push_pb(stack_a, stack_b);
	result = compare_strings(str, "rb");
	if (result == 1)
		rotate_rb(stack_b);
	result = compare_strings(str, "rrb");
	if (result == 1)
		rotate_rrb(stack_b);
}

static void	execute_both(t_stack **stack_a, t_stack **stack_b, char *str)
{
	int	result;

	result = compare_strings(str, "ss");
	if (result == 1)
		swap_ss(stack_a, stack_b, NULL);
	result = compare_strings(str, "rr");
	if (result == 1)
		rotate_rr(stack_a, stack_b, 0);
	result = compare_strings(str, "rrr");
	if (result == 1)
		rotate_rrr(stack_a, stack_b, 0);
}

int	execute_instruction(t_stack **stack_a, char **split)
{
	int		i;
	t_stack	*stack_b;

	i = 0;
	stack_b = NULL;
	if (split)
	{
		while (split[i] != NULL)
		{
			execute_a(stack_a, &stack_b, split[i]);
			execute_b(stack_a, &stack_b, split[i]);
			execute_both(stack_a, &stack_b, split[i]);
			i++;
		}
	}
	if (stack_b != NULL)
	{
		ft_lstclear_stack(&stack_b);
		return (0);
	}
	return (1);
}
