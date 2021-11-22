/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:01:16 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/22 21:19:46 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Check if list sorted
*/

int	list_sorted(t_stack **stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack == NULL)
		return (-1);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (*stack != NULL)
			{
				if ((*stack)->next != NULL)
					if ((*stack)->number > (*stack)->next->number)
						return (0);
				stack = &(*stack)->next;
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
 ** Add number into stack
*/

int	add_into_stack(t_stack **stack_a, char *str, int i, int start)
{
	ssize_t	atoi;
	char	*ptr;

	atoi = 0;
	ptr = NULL;
	if (str == NULL || stack_a == NULL)
		return (-1);
	if (ft_isdigit(str[i]) == 0)
	{
		ptr = ft_substr(str, start, i - start);
		if (ptr == NULL)
			return (-1);
		atoi = ft_atoi(ptr);
		if (ptr != NULL)
			free(ptr);
		if (atoi < -2147483648 || atoi > 2147483647)
			return (-1);
		if (*stack_a != NULL)
			ft_lstadd_back_stack(stack_a, ft_lstnew_stack((int)atoi));
		else
			ft_lstadd_front_stack(stack_a, ft_lstnew_stack((int)atoi));
		start = 0;
	}
	return (1);
}

/*
 ** Get number from the string
*/

int	get_number(t_stack **stack_a, char *str, int *i, const int start)
{
	int	result;

	result = 0;
	if (str == NULL || stack_a == NULL)
		return (-1);
	if (str)
	{
		if (str[*i] == '-')
			(*i)++;
		if (ft_isdigit(str[*i]) == 0)
			return (-1);
		while (str[*i] && ft_isdigit(str[*i]) == 1)
			(*i)++;
		if (stack_a)
			result = add_into_stack(stack_a, str, *i, start);
		if (result == -1)
			return (-1);
		while (str[*i] && str[*i] == ' ')
			(*i)++;
	}
	return (1);
}

/*
 ** getting the stack from argv
*/

int	get_stack(char *str, t_stack **stack_a)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (str == NULL || stack_a == NULL)
		return (-1);
	if (str)
	{
		while (str[i])
		{
			while (str[i] && str[i] == ' ')
				i++;
			if (((ft_isdigit(str[i]) == 0 && str[i] != '-') && str[i] != '\0'))
				return (-1);
			else
			{
				result = get_number(stack_a, str, &i, i);
				if (result == -1)
					return (-1);
			}
		}
	}
	return (1);
}

void	is_stack_ok(t_stack **stack_a, int get_stack_ok)
{
	if (get_stack_ok == -1)
	{
		error();
		if (stack_a)
			ft_lstclear_stack(stack_a);
		exit(EXIT_FAILURE);
	}
}
