int	rotate_ra(t_stack **stack_a)
{
	int	*first_save;
	int	*seconde_save;

	first_save = (*stack)->number;
	*stack_a = (*stack_a)->head;
	second_save = (*stack)->number;
	(*stack_a)->number = first_save;
	return (1);
}
