/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:44:57 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/22 12:08:41 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "gnl/get_next_line.h"
#include "push_swap_bonus.h"

int	read_instruction(t_stack **stack_a)
{
	int		result;
	char	*line;
	char	*split;
	char	*tmp;

	line = NULL;
	result = 1;
	split = ft_strdup("");
	while (result > 0)
	{
		result = get_next_line(0, &line);
		tmp = ft_strjoin(split, line);
		free(split);
		free(line);
		if (tmp == NULL)
			return (-1);
		line = ft_strjoin(tmp, "|");
		free(tmp);
		tmp = NULL;
		if (line == NULL)
			return (-1);
		split = line;
	}
	check_instruction(stack_a, split);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		get_stack_ok;
	int		result;

	get_stack_ok = 0;
	stack_a = NULL;
	if (argc < 2)
		exit(0);
	read_parameters(argc, argv, &stack_a);
	get_stack_ok = loop_duplicate(stack_a);
	is_stack_ok(&stack_a, get_stack_ok);
	while (stack_a->head != NULL)
		stack_a = stack_a->head;
	result = read_instruction(&stack_a);
	is_stack_ok(&stack_a, result);
	result = list_sorted(&stack_a, ft_lstsize_stack(stack_a));
	if (result == 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 2);
	ft_lstclear_stack(&stack_a);
	return (0);
}
