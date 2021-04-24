#include "push_swap.h"
#include "libft.h"

int	copy_stack(t_stack *stack_a)
{
	t_stack *lst_median;
	t_stack	*keep_address;
	int	median;

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
	if (median == -1)
		return (-1);
	ft_lstclear_stack(&lst_median);
	while (stack_a)
	{
		if (stack_a->number == median)
			stack_a->is_median = 1;
		stack_a = stack_a->next;
	}
	return (1);
}

/*
 ** Add number into stack
*/

int	add_into_stack(t_stack **stack_a, char *str, int i, int start)
{
	ssize_t	atoi;
	char	*ptr;

	atoi = 0;
	ptr = NULL;
	if (str)
	{
		if (ft_isdigit(str[i]) == 0)
		{
			ptr = ft_substr(str, start, i - start);
			if (ptr == NULL)
				return (-1);
			atoi = ft_atoi(ptr);
			if (ptr != NULL)
				free(ptr);
			if (atoi < -2147483648 || atoi > 2147483647)
				return (-1);
			if (*stack_a != NULL)
				ft_lstadd_back_stack(stack_a, ft_lstnew_stack((int)atoi));
			else
				ft_lstadd_front_stack(stack_a, ft_lstnew_stack((int)atoi));
			start = 0;
		}
	}
	return (1);
}

/*
 ** Get number from the string
*/

int	get_number(t_stack **stack_a, char *str, int *i, int start)
{
	int	result;

	result = 0;
	if (str)
	{
		if (str[*i] == '-')
			(*i)++;
		if (ft_isdigit(str[*i]) == 0)
			return (-1);
		while (str[*i] && ft_isdigit(str[*i]) == 1)
			(*i)++;
		if (stack_a)
			result = add_into_stack(stack_a, str, *i, start);
		if (result == -1)
			return (-1);
		if (str[*i] != '\0' && str[*i] != ' ')
			return (-1);
	}
	return (1);
}

/*
 ** getting the stack from argv
*/

int	get_stack(char *str, t_stack **stack_a)
{
	int	i;
	int	start;
	int	result;

	i = 0;
	start = 0;
	result = 0;
	if (str)
	{
		while (str[i])
		{
			while (str[i] && str[i] == ' ')
				i++;
			if (((ft_isdigit(str[i]) == 0 && str[i] != '-') && str[i] != '\0'))
				return (-1);
			else
			{
				start = i;
				result = get_number(stack_a, str, &i, start);
				if (result == -1)
					return (-1);
			}
		}
	}
	return (1);
}

/*
 ** main program push_swap
*/

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;
	int	i;
	int	get_stack_ok;

	i = 1;
	get_stack_ok = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(0);
	while (argc > i)
	{
		get_stack_ok = get_stack(argv[i], &stack_a);
		i++;
		if (get_stack_ok == -1)
		{
			error();
			ft_lstclear_stack(&stack_a);
			ft_lstclear_stack(&stack_b);
			exit(EXIT_FAILURE);
		}
	}
	if (get_stack_ok == -1)
		error_int_stack();
	get_stack_ok = loop_duplicate(stack_a);
	if (get_stack_ok == -1)
	{
		error();
		ft_lstclear_stack(&stack_a);
		ft_lstclear_stack(&stack_b);
		exit(EXIT_FAILURE);
	}
	while (stack_a->head != NULL)
		stack_a = stack_a->head;
	/*swap_sa(&stack_a);
	push_pb(&stack_a, &stack_b);
	push_pb(&stack_a, &stack_b);
	push_pb(&stack_a, &stack_b);
	rotate_ra(&stack_a, 0);
	rotate_rb(&stack_b);
	rotate_rra(&stack_a, 0);
	rotate_rrb(&stack_b);
	swap_sa(&stack_a);
	push_pa(&stack_a, &stack_b);
	push_pa(&stack_a, &stack_b);
	push_pa(&stack_a, &stack_b);
*/
	/*if (copy_stack(stack_a) == -1)
	{
		error();
		ft_lstclear_stack(&stack_a);
		exit(EXIT_FAILURE);
	}*/
	resolver(&stack_a);
	printf("stack_a-----------------------\n");
	display(stack_a);
	printf("stack_b-----------------------\n");
	//display(stack_b);
	ft_lstclear_stack(&stack_a);
	ft_lstclear_stack(&stack_b);
	return (0);
}
