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
#include "../../includes/push_swap.h"

t_stack	*ft_lstnew_stack(ssize_t content)
{
	t_stack	*t_lst;

	if (!(t_lst = malloc(sizeof(t_stack))))
		return (NULL);
	t_lst->position = 1;
	t_lst->number = content;
	t_lst->head = NULL;
	t_lst->next = NULL;
	return (t_lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*t_lst;

	if (!(t_lst = malloc(sizeof(t_list))))
		return (NULL);
	t_lst->content = content;
	return (t_lst);
}
