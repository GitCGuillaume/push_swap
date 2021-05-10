/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:00:47 by gchopin           #+#    #+#             */
/*   Updated: 2021/05/10 14:00:48 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** ft_strlen(str_one) to get full length, because str_two will
 ** make the compare_string ft bug
*/

int	compare_strings(char *str_one, char *str_two)
{
	int	result;
	int	cmp;

	result = 0;
	cmp = ft_strcmp(str_one, str_two);
	if (cmp == 0)
		return (1);
	else
		return (0);
	exit(0);
}

void	free_array(char **ptr)
{
	int	size;

	size = 0;
	if (ptr)
	{
		while (ptr[size] != NULL)
			size++;
		while (size != 0)
		{
			size--;
			if (ptr[size])
				free(ptr[size]);
		}
		free(ptr);
	}
}

void	read_parameters(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	int		get_stack_ok;

	i = 1;
	get_stack_ok = 0;
	while (argc > i)
	{
		get_stack_ok = get_stack(argv[i], stack_a);
		i++;
		is_stack_ok(stack_a, get_stack_ok);
	}
	is_stack_ok(stack_a, get_stack_ok);
}
