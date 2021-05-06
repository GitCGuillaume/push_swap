#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef	struct	s_stack
{
	struct s_stack	*head;
	struct s_stack	*next;
	size_t		position;
	int		is_median;
	int		number;
}				t_stack;

t_stack			*ft_lstnew_stack(ssize_t content);
void			ft_lstadd_front_stack(t_stack **alst, t_stack *new);
void			ft_lstadd_back_stack(t_stack **alst, t_stack *new);
void			ft_lstdelone_stack(t_stack *lst);
void			ft_lstclear_stack(t_stack **lst);
t_stack			*ft_lstlast_stack(t_stack *lst);
int			ft_lstsize_stack(t_stack *lst);

/*
 ** GLOBALS FUCTIONS
*/

int	list_sorted(t_stack **stack, int size);
int	add_into_stack(t_stack **stack_a, char *str, int i, int start);
int	get_number(t_stack **stack_a, char *str, int *i, int start);
int	get_stack(char *str, t_stack **stack_a);

/*
 ** Instructions
*/
int	swap_sa(t_stack **stack_a, t_stack **median);
int	swap_sb(t_stack **stack_b);
int	swap_ss(t_stack **stack_a, t_stack **stack_b, t_stack **median);
int	push_pa(t_stack **stack_a, t_stack **stack_b);
int	push_pb(t_stack **stack_a, t_stack **stack_b);
int	rotate_ra(t_stack **stack_a, t_stack **median);
int	rotate_rb(t_stack **stack_b);
int	rotate_rr(t_stack **stack_a, t_stack **stack_b, t_stack **median);
int	rotate_rra(t_stack **stack_a, t_stack **median);
int	rotate_rrb(t_stack **stack_b);
int	rotate_rrr(t_stack **stack_a, t_stack **stack_b, t_stack **median);

/*
 ** Loop stack
*/
void	display(t_stack *stack);
int	check_duplicate(t_stack *stack);
int	loop_duplicate(t_stack *stack_a);

/*
 ** Error Handler quicksort
*/
void	error(void);

/*
 ** Quicksort
*/

int	copy_stack(t_stack *stack_a);
t_stack	*quicksort_median(t_stack *lst);

/*
 ** Resolver push_swap
*/

int	resolver(t_stack **stack_a);

#endif
