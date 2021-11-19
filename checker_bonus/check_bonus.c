/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:44:32 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/05 14:44:37 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_entry_a(char *split)
{
	int	result;

	result = compare_strings(split, "sa");
	if (result == 0)
		result = compare_strings(split, "pa");
	if (result == 0)
		result = compare_strings(split, "ra");
	if (result == 0)
		result = compare_strings(split, "rra");
	return (result);
}

int	check_entry_b(char *split)
{
	int	result;

	result = compare_strings(split, "sb");
	if (result == 0)
		result = compare_strings(split, "pb");
	if (result == 0)
		result = compare_strings(split, "rb");
	if (result == 0)
		result = compare_strings(split, "rrb");
	return (result);
}

int	check_entry_both(char *split)
{
	int	result;

	result = compare_strings(split, "ss");
	if (result == 0)
		result = compare_strings(split, "rr");
	if (result == 0)
		result = compare_strings(split, "rrr");
	return (result);
}

int	check_entries(t_stack **stack_a, char **split)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (split)
	{
		while (split[i] != NULL)
		{
			result = check_entry_a(split[i]);
			if (result == 0)
				result = check_entry_b(split[i]);
			if (result == 0)
				result = check_entry_both(split[i]);
			if (result == 0)
			{
				error();
				free_array(split);
				ft_lstclear_stack(stack_a);
				exit(EXIT_FAILURE);
			}
			i++;
		}
	}
	return (result);
}

int	check_instruction(t_stack **stack_a, char *str)
{
	int		result;
	char	**split;

	result = 0;
	split = ft_split(str, '|');
	free(str);
	if (split)
		result = check_entries(stack_a, split);
	result = execute_instruction(stack_a, split);
	if (result == 0)
	{
		ft_lstclear_stack(stack_a);
		free_array(split);
		ft_putstr_fd("KO\n", 2);
		exit(EXIT_FAILURE);
	}
	free_array(split);
	return (1);
}
