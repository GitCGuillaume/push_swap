#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../srcs/libft/libft.h"

typedef	struct	s_stack
{
	struct s_stack	*head;
	struct s_stack	*next;
	int		position;
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
 ** Instructions
*/
int	swap_sa(t_stack **stack_a);
int	swap_sb(t_stack **stack_b);
int	swap_ss(t_stack **stack_a, t_stack **stack_b);
int	push_pa(t_stack **stack_a, t_stack **stack_b);
int	push_pb(t_stack **stack_a, t_stack **stack_b);
int	rotate_ra(t_stack **stack_a);
int	rotate_rb(t_stack **stack_b);
int	rotate_rr(t_stack **stack_a, t_stack **stack_b);
int	rotate_rra(t_stack **stack_a);
int	rotate_rrb(t_stack **stack_b);
int	rotate_rrr(t_stack **stack_a, t_stack **stack_b);

/*
 ** Loop stack
*/
void	display(t_stack *stack);
int	check_duplicate(t_stack *stack);
int	loop_duplicate(t_stack *stack_a);

/*
 ** Error Handler quicksort
*/
void	error_int_stack(void);
void	error(void);

/*
 ** Quicksort
*/
void	quicksort_main(t_stack *lst);

#endif
