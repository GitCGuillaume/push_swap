PH	=	./srcs/push_swap

INSTRUCTIONS	=	./srcs/instructions

RESOLVER	=	$(PH)/resolver

SRCS	=	$(INSTRUCTIONS)/swap.c $(INSTRUCTIONS)/push.c $(INSTRUCTIONS)/rotate.c $(INSTRUCTIONS)/rotate_both.c $(PH)/main.c $(PH)/quicksort.c $(PH)/loop_stack.c $(PH)/error_handler.c $(RESOLVER)/main.c

SRCS_LIBFT	=	./libft/ft_isdigit.o ./libft/ft_atoi.o ./libft/ft_substr.o ./libft/ft_putstr_fd.o ./libft/ft_strlen.o ./libft/ft_lstnew.o ./libft/ft_lstadd_front.o ./libft/ft_lstsize.o ./libft/ft_lstlast.o ./libft/ft_lstadd_back.o ./libft/ft_lstdelone.o ./libft/ft_lstclear.o ./libft/ft_swap.o

CLANG	=	clang -Wall -Wextra -Werror

RM	=	rm -f

OBJS	=	$(SRCS:.c=.o)

OBJS_LIBFT	=	$(SRCS_LIBFT:.c=.o)

NAME_PUSH_SWAP	=	push_swap

.c.o:
	$(CLANG) -Iincludes -Ilibft -c $< -o $(<:.c=.o)

$(NAME_PUSH_SWAP):	$(OBJS)
			make -C libft
			make bonus -C libft
			$(CLANG) -Iincludes -Ilibft -o $(NAME_PUSH_SWAP) $(OBJS_LIBFT) $(OBJS)

all:	$(NAME_PUSH_SWAP)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C libft/

fclean:
	rm -f push_swap
	make clean
	$(MAKE) fclean -C libft/

re:	fclean all

.PHONY:	all clean fclean re
