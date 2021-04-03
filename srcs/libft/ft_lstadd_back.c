/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 12:37:25 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/22 18:08:42 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../includes/push_swap.h"
/*
void	ft_lstadd_back_stack(t_stack **alst, t_stack *new, size_t position)
{
	t_stack *t_lst;

	if (new)
	{
		if (*alst && alst)
		{
			t_lst = ft_lstlast_stack(*alst);
			if (t_lst)
			{
				new->position = position;
				t_lst->next = new;
			}
		}
		else
			*alst = new;
	}
}*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *t_lst;

	if (new)
	{
		if (*alst && alst)
		{
			t_lst = ft_lstlast(*alst);
			if (t_lst)
			{
				t_lst->next = new;
			}
		}
		else
			*alst = new;
	}
}
