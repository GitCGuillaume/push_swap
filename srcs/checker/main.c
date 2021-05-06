#include "push_swap.h"
#include "get_next_line.h"
#include <stdio.h>

/*
 ** ft_strlen(str_one) to get full length, because str_two will
 ** make the compare_string ft bug
*/

int	compare_strings(char *str_one, char *str_two)
{
	int	result;
	int	cmp;

	result = 0;
	cmp = ft_strcmp(str_one, str_two);
	if (cmp == 0)
		return (1);
	else
		return (0);
	exit(0);
}


int	execute_instruction(t_stack **stack_a, char **split)
{
	int	i;
	int	result;
	t_stack	*stack_b;

	i = 0;
	stack_b = NULL;
	while (split[i] != NULL)
	{
		result = compare_strings(split[i], "sa");
		if (result == 1)
			swap_sa(stack_a, NULL);
		result = compare_strings(split[i], "sb");
		if (result == 1)
			swap_sb(&stack_b);
		result = compare_strings(split[i], "ss");
		if (result == 1)
			swap_ss(stack_a, &stack_b, NULL);
		result = compare_strings(split[i], "pa");
		if (result == 1)
			push_pa(stack_a, &stack_b);
		result = compare_strings(split[i], "pb");
		if (result == 1)
			push_pb(stack_a, &stack_b);
		result = compare_strings(split[i], "ra");
		if (result == 1)
			rotate_ra(stack_a, 0);
		result = compare_strings(split[i], "rb");
		if (result == 1)
			rotate_rb(&stack_b);
		result = compare_strings(split[i], "rr");
		if (result == 1)
			rotate_rr(stack_a, &stack_b, 0);
		result = compare_strings(split[i], "rra");
		if (result == 1)
			rotate_rra(stack_a, 0);
		result = compare_strings(split[i], "rrb");
		if (result == 1)
			rotate_rrb(&stack_b);
		result = compare_strings(split[i], "rrr");
		if (result == 1)
			rotate_rrr(stack_a, &stack_b, 0);
		i++;
	}
	if (stack_b != NULL)
	{
		ft_lstclear_stack(&stack_b);
		return (0);
	}
	return (1);
}

void	*ft_free(char **ptr)
{
	int	size;

	size = 0;
	if (ptr)
	{
		while (ptr[size] != NULL)
			size++;
		while (size != 0)
		{
			size--;
			if (ptr[size])
				free(ptr[size]);
		}
		free(ptr);
	}
	return (NULL);
}

int	check_instruction(t_stack **stack_a , char *str)
{
	int	i;
	int	result;
	char	**split;

	i = 0;
	result = 0;
	split = ft_split(str, '|');
	if (split)
	{
		while (split[i] != NULL)
		{
			result = compare_strings(split[i], "sa");
			if (result == 0)
				result = compare_strings(split[i], "sb");
			if (result == 0)
				result = compare_strings(split[i], "ss");
			if (result == 0)
				result = compare_strings(split[i], "pa");
			if (result == 0)
				result = compare_strings(split[i], "pb");
			if (result == 0)
				result = compare_strings(split[i], "ra");
			if (result == 0)
				result = compare_strings(split[i], "rb");
			if (result == 0)
				result = compare_strings(split[i], "rr");
			if (result == 0)
				result = compare_strings(split[i], "rra");
			if (result == 0)
				result = compare_strings(split[i], "rrb");
			if (result == 0)
				result = compare_strings(split[i], "rrr");
			if (result == 0)
			{
				error();
				free(str);
				ft_free(split);
				ft_lstclear_stack(stack_a);
				exit(EXIT_FAILURE);
			}
			i++;
		}
	}
	result = execute_instruction(stack_a, split);
	if (result == 0)
	{
		free(str);
		ft_lstclear_stack(stack_a);
		ft_free(split);
		ft_putstr_fd("KO\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_free(split);
	free(str);
	return (1);
}

int	read_instruction(t_stack **stack)
{
	int	result;
	int	i;
	char	*line;
	char	*split;
	char	*tmp;
(void)stack;
	i = 0;
	line = NULL;
	result = 1;
	split = ft_strdup("");
	tmp = NULL;
	while (result > 0)
	{
		result = get_next_line(0, &line);
		tmp = ft_strjoin(split, line);
		free(split);
		split = NULL;
		free(line);
		line = NULL;
		if (tmp != NULL)
		{
			line = ft_strjoin(tmp, "|");
			free(tmp);
			tmp = NULL;
			split = line;
		}
	}
	check_instruction(stack, split);
	/*if (line)
	{
		while (*line)
		{
			printf("l=%s\n", *line);
			free(line);
			(*line)++;
		}
	}*/
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;
	int	i;
	int	get_stack_ok;
	int	result;

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
	{
		error();
		ft_lstclear_stack(&stack_a);
		ft_lstclear_stack(&stack_b);
		exit(EXIT_FAILURE);
	}
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
	read_instruction(&stack_a);
	result = list_sorted(&stack_a, ft_lstsize_stack(stack_a));
	if (result == 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 2);
	ft_lstclear_stack(&stack_a);
	ft_lstclear_stack(&stack_b);
	return (0);
}
