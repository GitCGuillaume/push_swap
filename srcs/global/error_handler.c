/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:00:56 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/22 11:39:05 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
}

void	error_stack(t_stack **stack_a, t_stack **stack_b, int result)
{
	if (result == -1)
	{
		error();
		ft_lstclear_stack(stack_a);
		ft_lstclear_stack(stack_b);
		exit(EXIT_FAILURE);
	}
}
