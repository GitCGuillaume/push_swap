/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:03:11 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/23 18:23:26 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*partition(t_stack **first, t_stack **last)
{
	t_stack	**keep_address;
	t_stack	**pivot;

	keep_address = NULL;
	pivot = NULL;
	if (first && last)
	{
		ft_swap(&(*first)->number, &(*last)->number);
		keep_address = first;
		while ((*first)->next != NULL && ((*last)->position > (*first)->position))
		{
			if ((*last)->number > (*first)->number)
			{
				ft_swap(&(*first)->number, &(*keep_address)->number);
				keep_address = &(*keep_address)->next;
			}
			first = &(*first)->next;
		}
		ft_swap(&(*last)->number, &(*keep_address)->number);
		pivot = keep_address;
	}
	return (*pivot);
}

void	quicksort(t_stack *first, t_stack *last)
{
	t_stack	*pivot;

	pivot = NULL;
	if (first && last)
	{
		if (last->position > first->position)
		{
			pivot = partition(&first, &last);
			if (pivot->head != NULL)
				quicksort(first, pivot->head);
			if (pivot->next != NULL)
				quicksort(pivot->next, last);
		}
	}
}

/*
 ** Need to find the median from the list
*/

t_stack	*get_median(t_stack *lst, int median)
{
	//t_stack *biggest;
	int	i;

	i = 0;
	//biggest = NULL;
	if (lst)
	{
		//biggest = get_biggest(&lst);
		while (lst != NULL)
		{
			i++;
			/*if (i == median && lst->number != biggest->number)
				return (lst);
			else if (i == median && lst->number == biggest->number
				&& lst->next != NULL)
				return (lst->next);
			else */
			if (i == median)
				return (lst);
			lst = lst->next;
		}
	}
	return (lst);
}

/*
 ** Quicksort Algorithm with pivot
*/

t_stack	*quicksort_median(t_stack *lst)
{
	t_stack	*first;
	t_stack	*last;
	int		size;
	int		median;

	if (lst == NULL)
		return (NULL);
	first = lst;
	last = ft_lstlast_stack(lst);
	quicksort(first, last);
	size = ft_lstsize_stack(lst);
	median = 0;
	if (size <= 100)
	{
		if (size % 2 == 1)
			size++;
		median = size / 2;
	}
	else
	{
		median = size / 6;
	}
	return (get_median(first, median));
}
