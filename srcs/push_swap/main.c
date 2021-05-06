#include "push_swap.h"

void	seek_median(t_stack **stack_a, int median)
{
	while (*stack_a)
	{
		if ((*stack_a)->number == median)
			(*stack_a)->is_median = 1;
		stack_a = &(*stack_a)->next;
	}
}

int	copy_stack(t_stack *stack_a)
{
	t_stack *lst_median;
	t_stack	*keep_address;
	t_stack	*median;

	keep_address = stack_a;
	lst_median = NULL;
	if (keep_address == NULL || stack_a == NULL)
		return (-1);
	while (keep_address != NULL)
	{
		ft_lstadd_back_stack(&lst_median, ft_lstnew_stack(keep_address->number));
		keep_address = keep_address->next;
	}
	if (lst_median == NULL)
		return (-1);
	median = quicksort_median(lst_median);
	if (median == NULL)
		return (-1);
	ft_lstclear_stack(&lst_median);
	seek_median(&stack_a, median->number);
	return (1);
}

void	is_stack_ok(t_stack **stack_a, int get_stack_ok)
{
	if (get_stack_ok == -1)
	{
		error();
		ft_lstclear_stack(stack_a);
		exit(EXIT_FAILURE);
	}
}

/*
 ** main program push_swap
*/

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	int	i;
	int	get_stack_ok;

	i = 1;
	get_stack_ok = 0;
	stack_a = NULL;
	if (argc < 2)
		exit(0);
	while (argc > i)
	{
		get_stack_ok = get_stack(argv[i], &stack_a);
		i++;
		is_stack_ok(&stack_a, get_stack_ok);
	}
	is_stack_ok(&stack_a, get_stack_ok);
	get_stack_ok = loop_duplicate(stack_a);
	is_stack_ok(&stack_a, get_stack_ok);
	while (stack_a->head != NULL)
		stack_a = stack_a->head;
	resolver(&stack_a);
//	display(stack_a);
	ft_lstclear_stack(&stack_a);
	return (0);
}
