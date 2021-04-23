#include "push_swap.h"

int	partition(t_stack *lst, t_stack *first, t_stack *last)
{
	t_stack *pivot;
	t_stack	*keep_address;

	keep_address = first;
	ft_swap(&first->number, &last->number);
	pivot = last;
	while (first->next != NULL && (last->position > first->position))
	{
		if (last->number > first->number)
		{
			ft_swap(&first->number, &keep_address->number);
			keep_address = keep_address->next;
		}
		first = first->next;
	}
	ft_swap(&last->number, &keep_address->number);
	return (0);
}

void	quicksort(t_stack *lst, t_stack *first, t_stack *last)
{
	if (last->position > first->position)
	{
		partition(lst, first, last);
		if (last->head != NULL)
			quicksort(lst, first, last->head);
		if (first->next != NULL)
			quicksort(lst, first->next, last);
	}
}

/*
 ** Need to find the median from the list
*/

int	get_median(t_stack *lst, int median)
{
	int	i;

	i = 0;
	while (lst != NULL && median > i)
	{
		i++;
		if (i == median)
			return (lst->number);
		lst = lst->next;
	}
	return (0);
}

/*
 ** Quicksort Algorithm with pivot
*/

int	quicksort_median(t_stack *lst)
{
	t_stack	*first;
	t_stack	*last;
	int	median;
	int	size;

	if (lst == NULL)
		return (-1);
	first = lst;
	last = ft_lstlast_stack(lst);
	quicksort(lst, first, last);
	size = ft_lstsize_stack(lst);
	median = size % 2;
	if (median == 1)
		median = (size + 1) / 2;
	else
		median = size / 2;
	median = get_median(lst, median);
	return (median);
}
