#include "../../includes/push_swap.h"
#include <stdio.h>

int	partition(t_stack *lst, t_stack *stack_b, t_stack *first, t_stack *last)
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

void	quicksort(t_stack *lst, t_stack *stack_b, t_stack *first, t_stack *last)
{
	if (last->position > first->position)
	{
		partition(lst, stack_b, first, last);
		if (last->head != NULL)
			quicksort(lst, stack_b, first, last->head);
		if (first->next != NULL)
			quicksort(lst, stack_b, first->next, last);
	}
}

/*
 ** Need to find the median from the list
*/

void	quicksort_main(t_stack *lst)
{
	t_stack	*stack_b;
	t_stack	*first;
	t_stack	*last;

	stack_b = NULL;
	first = lst;
	last = ft_lstlast_stack(lst);
	quicksort(lst, stack_b, first, last);
}
