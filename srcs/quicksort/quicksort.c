#include "../../includes/push_swap.h"
#include <stdio.h>
/*
int	partition(t_stack *lst, t_stack *first, t_stack *last, t_stack *pivot)
{

}*/

void	quicksort(t_stack *lst, t_stack *first, t_stack *last)
{
	t_stack	*pivot;

	if (last->number > first->number)
	{
		//partition(lst, first, last, pivot);
		if (last->head != NULL)
			quicksort(lst, first, last->head);
		if (last->next != NULL)
			quicksort(lst, first->next, last);
	}
}

void	quicksort_main(t_stack *lst)
{
	t_stack	*stack_b;
	t_stack	*first;
	t_stack	*last;

	stack_b = NULL;
	first = lst;
	last = ft_lstlast_stack(lst);
	//printf("first=%d\n", first->number);
	//printf("lst_last=%d\n", last->number);
	quicksort(lst, first, last);
}
