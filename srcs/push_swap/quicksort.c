#include "push_swap.h"
#include <stdio.h>
t_stack	*partition(t_stack **first, t_stack **last)
{
	t_stack	**keep_address;
	t_stack	**pivot;

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
	return (*pivot);
}

void	quicksort(t_stack *first, t_stack *last)
{
	t_stack	*pivot;

	if (last->position > first->position)
	{
		pivot = partition(&first, &last);
		if (pivot->head != NULL)
			quicksort(first, pivot->head);
		if (pivot->next != NULL)
			quicksort(pivot->next, last);
	}
}

/*
 ** Need to find the median from the list
*/

t_stack	*get_median(t_stack *lst, int median)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		if (i == median)
			return (lst);
		lst = lst->next;
		//printf("lst=n %d median=%d\n", lst->number, median);
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
	int	median;
	int	size;

	if (lst == NULL)
		return (NULL);
	first = lst;
	last = ft_lstlast_stack(lst);
	quicksort(first, last);
	size = ft_lstsize_stack(lst);
	median = size % 2;
	if (size < 100)
	{
		if (median == 1)
			median = (size + 1) / 2;
		else
			median = size / 2;
	}
	else
	{
		if (median == 1)
			median = (size + 1) / 4;
		else
			median = size / 4;
	}
	return (get_median(lst, median));
}
