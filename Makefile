GLB	=	./srcs/global

GNL	=	./srcs/gnl

PH	=	./srcs/push_swap

CHK	=	./checker_bonus

INSTRUCTIONS	=	./srcs/instructions

RESOLVER	=	$(PH)/resolver

SRCS_PH	=	$(GLB)/main.c $(INSTRUCTIONS)/swap.c $(INSTRUCTIONS)/push.c $(INSTRUCTIONS)/rotate.c $(INSTRUCTIONS)/rotate_both.c $(PH)/main.c $(PH)/quicksort.c $(GLB)/duplicate_stack.c $(GLB)/error_handler.c $(RESOLVER)/tools.c $(RESOLVER)/tools_two.c $(RESOLVER)/main.c

SRCS_CHK =	 $(GNL)/get_next_line.c $(GNL)/get_next_line_utils.c $(GLB)/main.c $(GLB)/error_handler.c $(GLB)/duplicate_stack.c $(INSTRUCTIONS)/swap.c $(INSTRUCTIONS)/push.c $(INSTRUCTIONS)/rotate.c $(INSTRUCTIONS)/rotate_both.c $(CHK)/tools_bonus.c $(CHK)/check_bonus.c $(CHK)/execute_bonus.c $(CHK)/main_bonus.c

SRCS_LIBFT	=	./libft/ft_strcmp.o ./libft/ft_strdup.o ./libft/ft_strjoin.o ./libft/ft_strchr.o ./libft/ft_isdigit.o ./libft/ft_atoi.o ./libft/ft_substr.o ./libft/ft_putstr_fd.o ./libft/ft_strlen.o ./libft/ft_lstnew.o ./libft/ft_lstadd_front.o ./libft/ft_lstsize.o ./libft/ft_lstlast.o ./libft/ft_lstadd_back.o ./libft/ft_lstdelone.o ./libft/ft_lstclear.o ./libft/ft_swap.o ./libft/ft_split.o

CLANG	=	clang -Wall -Wextra -Werror

RM	=	rm -f

OBJS_PH	=	$(SRCS_PH:.c=.o)

OBJS_CHK =	$(SRCS_CHK:.c=.o)

OBJS_LIBFT	=	$(SRCS_LIBFT:.c=.o)

NAME_PUSH_SWAP	=	push_swap

NAME_CHECKER	=	checker

.c.o:
	$(CLANG) -Iincludes -Ilibft -Isrcs/gnl -c $< -o $(<:.c=.o)

all:	$(NAME_PUSH_SWAP)

$(NAME_CHECKER):	$(OBJS_CHK)
			make -C libft
			make bonus -C libft
			$(CLANG) -Iincludes -Ilibft -Isrcs/gnl -o $(NAME_CHECKER) $(OBJS_LIBFT) $(OBJS_CHK)

$(NAME_PUSH_SWAP):	$(OBJS_PH)
			make -C libft
			make bonus -C libft
			$(CLANG) -Iincludes -Ilibft -o $(NAME_PUSH_SWAP) $(OBJS_LIBFT) $(OBJS_PH)


clean:
	$(RM) $(OBJS_CHK)
	$(RM) $(OBJS_PH)
	$(MAKE) clean -C libft/

fclean:
	rm -f checker
	rm -f push_swap
	make clean
	$(MAKE) fclean -C libft/

bonus: $(NAME_PUSH_SWAP) $(NAME_CHECKER)

re:
	make fclean
	make all

.PHONY:	all clean fclean re
