SRC = sources/check_create/check_errors.c\
sources/check_create/create_stacks.c\
sources/check_create/ft_lstadd_back_bonus.c\
sources/check_create/ft_lstnew_push_swap.c\
sources/libft/ft_atoi.c\
sources/libft/ft_isdigit.c\
sources/libft/ft_itoa.c\
sources/libft/ft_split.c\
sources/libft/ft_strdup.c\
sources/libft/ft_strlen.c\
sources/libft/ft_substr.c\
sources/libft/ft_bzero.c\
sources/libft/ft_calloc.c\
sources/print/ft_printf.c\
sources/print/ft_printf_utils.c\
sources/sort/push_stack.c\
sources/sort/push_swap.c\
sources/sort/rotate.c\
sources/sort/sort.c\
sources/sort/sort_long.c\
sources/sort/sort_short.c\
sources/sort/swap.c\
sources/tools/free.c\
sources/tools/ft_lstlast_bonus.c\
sources/tools/ft_lstsize_push_swap.c\
sources/tools/is_sorted.c\
sources/tools/sorting_tools.c\
sources/tools/tool.c
OBJ = $(SRC:.c=.o)
CC = cc -Wall -Wextra -Werror
HEAD = sources/push_swap.h
NAME = push_swap



$(NAME) : $(OBJ) 
	$(CC) -o $(NAME) $(SRC)

all : $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY : all clean fclean re push_swap