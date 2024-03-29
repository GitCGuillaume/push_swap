/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 14:08:51 by gchopin           #+#    #+#             */
/*   Updated: 2020/06/19 11:35:47 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*ft_lstnew_stack(ssize_t content)
{
	t_stack	*t_lst;

	t_lst = malloc(sizeof(t_stack));
	if (t_lst == NULL)
		return (NULL);
	t_lst->position = 1;
	t_lst->is_median = 0;
	t_lst->number = content;
	t_lst->head = NULL;
	t_lst->next = NULL;
	return (t_lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*t_lst;

	t_lst = malloc(sizeof(t_list));
	if (t_lst == NULL)
		return (NULL);
	t_lst->content = content;
	return (t_lst);
}
