GLB	=	./srcs/global

PH	=	./srcs/push_swap

INSTRUCTIONS	=	./srcs/instructions

RESOLVER	=	$(PH)/resolver

SRCS_PH	=	$(GLB)/main.c $(INSTRUCTIONS)/swap.c $(INSTRUCTIONS)/push.c $(INSTRUCTIONS)/rotate.c $(INSTRUCTIONS)/rotate_both.c $(PH)/main.c $(PH)/quicksort.c $(GLB)/duplicate_stack.c $(GLB)/error_handler.c $(RESOLVER)/tools.c $(RESOLVER)/tools_two.c $(RESOLVER)/main.c

SRCS_LIBFT	=	./libft/ft_strcmp.o ./libft/ft_strdup.o ./libft/ft_strjoin.o ./libft/ft_strchr.o ./libft/ft_isdigit.o ./libft/ft_atoi.o ./libft/ft_substr.o ./libft/ft_putstr_fd.o ./libft/ft_strlen.o ./libft/ft_lstnew.o ./libft/ft_lstadd_front.o ./libft/ft_lstsize.o ./libft/ft_lstlast.o ./libft/ft_lstadd_back.o ./libft/ft_lstdelone.o ./libft/ft_lstclear.o ./libft/ft_swap.o ./libft/ft_split.o

CLANG	=	clang -Wall -Wextra -Werror

RM	=	rm -f

OBJS_PH	=	$(SRCS_PH:.c=.o)

OBJS_LIBFT	=	$(SRCS_LIBFT:.c=.o)

NAME_PUSH_SWAP	=	push_swap

.c.o:
	$(CLANG) -Iincludes -Ilibft -c $< -o $(<:.c=.o)

all:	$(NAME_PUSH_SWAP)

$(NAME_PUSH_SWAP):	$(OBJS_PH)
			make -C libft
			make bonus -C libft
			$(CLANG) -Iincludes -Ilibft -o $(NAME_PUSH_SWAP) $(OBJS_LIBFT) $(OBJS_PH)

clean:
	$(RM) $(OBJS_PH)
	make clean -C libft/

fclean:
	rm -f $(NAME_PUSH_SWAP)
	make clean
	make fclean -C libft/

re:
	make fclean
	make all

.PHONY:	all clean fclean re
