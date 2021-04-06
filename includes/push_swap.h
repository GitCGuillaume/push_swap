#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../srcs/libft/libft.h"

typedef	struct	s_stack
{
	struct s_stack	*head;
	struct s_stack	*next;
	size_t		position;
	int		number;
}				t_stack;

t_stack			*ft_lstnew_stack(ssize_t content);
void			ft_lstadd_front_stack(t_stack **alst, t_stack *new, size_t position);
void			ft_lstadd_back_stack(t_stack **alst, t_stack *new, size_t position);
void			ft_lstdelone_stack(t_stack *lst);
void			ft_lstclear_stack(t_stack **lst);

/*
 ** Inscrutions
*/
int	swap_sa(t_stack **stack_a);
int	swap_sb(t_stack **stack_b);
int	swap_ss(t_stack **stack_a, t_stack **stack_b);
int	push_pa(t_stack **stack_a, t_stack **stack_b);
int	push_pb(t_stack **stack_a, t_stack **stack_b);

/*
 ** Error Handler quicksort
*/
void	error_int_stack(void);

#endif
