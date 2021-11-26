/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:03:06 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/26 12:27:11 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	seek_median(t_stack **stack, int median)
{
	if (stack == NULL)
		return ;
	while (*stack)
	{
		if ((*stack)->number == median)
			(*stack)->is_median = 1;
		stack = &(*stack)->next;
	}
}

int	copy_stack(t_stack *stack, int is_b)
{
	t_stack	*lst_median;
	t_stack	*keep_address;
	t_stack	*median;

	keep_address = stack;
	lst_median = NULL;
	if (keep_address == NULL || stack == NULL)
		return (-1);
	while (keep_address != NULL)
	{
		ft_lstadd_back_stack(&lst_median,
			ft_lstnew_stack(keep_address->number));
		keep_address = keep_address->next;
	}
	if (lst_median == NULL)
		return (-1);
	median = quicksort_median(lst_median, is_b);
	if (median == NULL)
		return (-1);
	seek_median(&stack, median->number);
	ft_lstclear_stack(&lst_median);
	return (1);
}

/*
 ** main program push_swap
*/

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		get_stack_ok;

	i = 1;
	get_stack_ok = 0;
	stack_a = NULL;
	if (argc < 2)
		exit(0);
	while (argc > i)
	{
		get_stack_ok = get_stack(argv[i], &stack_a);
		i++;
		is_stack_ok(&stack_a, get_stack_ok);
	}
	if (stack_a == NULL)
		return (0);
	is_stack_ok(&stack_a, get_stack_ok);
	get_stack_ok = loop_duplicate(stack_a);
	is_stack_ok(&stack_a, get_stack_ok);
	while (stack_a->head != NULL)
		stack_a = stack_a->head;
	resolver(&stack_a);
	ft_lstclear_stack(&stack_a);
	return (0);
}
