NAME = gdanylov.filler
# HEADER = -c -I ./includes/
FLAGS = -Wall -Wextra -Werror
SRC = filler_read.c filler_2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
		@gcc -c $? $(FLAGS)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean:
		rm -f *.o
		make clean -C ./libft/

fclean: clean
			rm -f $(NAME)
			make fclean -C ./libft/

re: fclean all
