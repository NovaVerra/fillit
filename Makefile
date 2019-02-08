CC = gcc
NAME = fillit
FLAGS = -Wall -Wextra -Werror -g
SRCS = ./main.c ./parse.c ./parse2.c ./help.c ./help2.c ./board.c
OBJS = ./main.o ./parse.o ./parse2.o ./help.o ./help2.o ./board.o

INC = -I .

all: $(NAME)

$(NAME): fillit.h
	$(CC) $(FLAGS) -o fillit -L. libft/libft.a $(SRCS)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
