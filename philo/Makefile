NAME = philo

CC = clang
CFLAGS = -Wall -Wextra -Werror -g -I.
RM = rm -f

SRC = ./atoi.c \
	./main.c \
	./monitor.c \
	./philo_routine.c \
	./philo_utils.c \
	./simulation.c \
	./utils.c


all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:


fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
