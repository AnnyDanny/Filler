NAME = gdanylov.filler
# HEADER = -c -I ./includes/
FLAGS = -Wall -Wextra -Werror
SRC = filler_read.c filler_2.c
VIZ = smile
OBJ = $(SRC:.c=.o)

all: $(NAME) vis

%.o: %.c
		@gcc -c $? $(FLAGS)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)
vis:
	echo "hello\n"
	gcc $(FLAGS) smile.c libft/libft.a -o $(VIZ)

clean:
		rm -f *.o
		make clean -C ./libft/

fclean: clean
			rm -f $(NAME)
			make fclean -C ./libft/

re: fclean all
