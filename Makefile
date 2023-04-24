SRC = sources/*.c
OBJ = $(SRC:.c=.o)
CC = cc -Wall -Wextra -Werror
HEAD = push_swap.h
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