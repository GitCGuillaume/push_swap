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

void			ft_lstadd_front_stack(t_stack **alst, t_stack *new);
t_stack			*ft_lstnew_stack(int content);

#endif
